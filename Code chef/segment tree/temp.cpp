/*
temp.cpp
10 July 2022
Sun 20:16

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
        build(2 * node, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
int query_sum(int node, int start, int end, int l, int r)
{
    //  l.....r start  // end l.....r
    if (start > r || end < l)
        return 0;
    if (l <= start and end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    int q1 = query_sum(2 * node, start, mid, l, r);
    int q2 = query_sum(2 * node + 1, mid + 1, end, l, r);
    return q1 + q2;
}
void update(int node, int start, int end, int pos, int value)
{
    if (start == end)
        tree[node] = value;
    else
    {
        int mid = (start + mid) / 2;
        if (pos <= mid)
        {
            update(2 * node, start, mid, pos, value);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, pos, value);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
void solve()
{
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}