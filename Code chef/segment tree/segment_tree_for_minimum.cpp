/*
segment_tree_for_minimum.cpp
11 July 2022
Mon 15:32
segment tree
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
int tree[4 * N], a[N];
void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}
int querey_min(int node, int start, int end, int l, int r)
{
    if (start > r || end < l)
        return 1e15;
    if (l <= start and end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    int q1 = querey_min(2 * node, start, mid, l, r);
    int q2 = querey_min(2 * node + 1, mid + 1, end, l, r);
    return min(q1, q2);
}
void update(int node, int start, int end, int pos, int value)
{
    if (start == end)
    {
        tree[node] = value;
    }
    else
    {
        int mid = (start + end) / 2;
        if (pos <= mid)
            update(2 * node, start, mid, pos, value);
        else
            update(2 * node + 1, mid + 1, end, pos, value);
        tree[node] = min(tree[node * 2], tree[2 * node + 1]);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n - 1);
    while (m--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int pos, value;
            cin >> pos >> value;
            update(1, 0, n - 1, pos, value);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            int s = querey_min(1, 0, n - 1, l, r - 1);
            cout << s << endl;
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