/*
ant_colony.cpp
19 July 2022
Tue 05:11

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 3e5 + 20;
int tree[4 * N], a[N], d[N];
void build(int node, int start, int end)
{
    if (start == end)
        tree[node] = a[start];
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = (tree[2 * node] + tree[2 * node + 1]);
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
    return (q1 + q2);
}
void update(int node, int start, int end, int l, int r)
{

    if (l > r)
        return;
    if (l == start && r == end)
    {
        tree[v] += add;
    }
    else
    {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), add);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n - 1);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = query_sum(1, 0, n - 1, l, r);
        cout << r - l + 1 - ans << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
            d[j]++;
    }
    // cout << d[6] << endl;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}