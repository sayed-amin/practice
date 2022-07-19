/*
segment_tree_for_max_sum.cpp
15 July 2022
Fri 06:16

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
struct Data
{
    int sum, pre, suff, ans;
};
Data tree[4 * N];
int a[N];

Data combine(Data l, Data r)
{
    Data res;
    res.sum = l.sum + r.sum;
    res.pre = max(l.pre, l.sum + r.pre);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pre);
    return res;
}
Data make(int val)
{
    Data res;
    res.sum = val;
    res.pre = res.suff = res.ans = max(0ll, val);
    return res;
}
void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = make(a[start]);
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
}
void update(int node, int start, int end, int pos, int value)
{
    if (start == end)
        tree[node] = make(value);
    else
    {
        int mid = (start + end) / 2;
        if (pos <= mid)
        {
            update(2 * node, start, mid, pos, value);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, pos, value);
        }
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    cout << tree[1].ans << endl;

    while (m--)
    {
        int pos, val;
        cin >> pos >> val;
        update(1, 0, n - 1, pos, val);
        cout << tree[1].ans << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}