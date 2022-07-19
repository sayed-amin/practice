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
const int MOD = 1e15;
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
    res.pre = res.suff = max(-MOD, val);
    res.ans = max(-MOD, val);
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
Data query(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return make(-1e15);
    if (l == tl && r == tr)
        return tree[v];
    int tm = (tl + tr) / 2;
    return combine(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void solve()
{
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    cin >> m;
    // cout << tree[1].ans << endl;

    while (m--)
    {
        int l, r;
        cin >> l >> r;

        {
            Data ns = query(1, 0, n - 1, l - 1, r - 1);
            cout << ns.ans << endl;
        }
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