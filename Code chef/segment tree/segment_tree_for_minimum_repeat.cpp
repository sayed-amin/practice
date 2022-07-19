/*
segment_tree_for_minimum_repeat.cpp
11 July 2022
Mon 22:50
segemnt tree
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10, MOD = 1e16;
pair<int, int> tree[4 * N];
int a[N];
pair<int, int> combine(pair<int, int> a, pair<int, int> b)
{ // just change the sign for max reapeated number
    if (a.first < b.first)
        return a;
    if (b.first < a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}
void build(int node, int start, int end)
{
    if (start == end)
        tree[node] = make_pair(a[start], 1);
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }
}
pair<int, int> get_max(int node, int start, int end, int l, int r)
{
    if (start > r || end < l)
        return {MOD, -1};
    if (start >= l and end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    pair<int, int> q1 = get_max(2 * node, start, mid, l, r);
    pair<int, int> q2 = get_max(2 * node + 1, mid + 1, end, l, r);
    return combine(q1, q2);
}
void update(int node, int start, int end, int pos, int value)
{
    if (start == end)
        tree[node] = make_pair(value, 1);
    else
    {
        int mid = (start + end) / 2;
        if (pos <= mid)
            update(2 * node, start, mid, pos, value);
        else
            update(2 * node + 1, mid + 1, end, pos, value);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
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
            pair<int, int> s = get_max(1, 0, n - 1, l, r - 1);
            cout << s.first << " " << s.second << endl;
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