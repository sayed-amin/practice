/*
nested_segment.cpp
16 July 2022
Sat 23:10

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 10, MOD = 1e9 + 7;
struct triplet
{
    int l, r, index;
};
bool cmp(triplet t1, triplet t2)
{
    return t1.r < t2.r;
}
const int N = 1e5 + 10;
int tree[4 * N], a[N];
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
    int n;
    cin >> n;
    triplet t1;
    t1.l = -1, t1.r = -1;
    vector<triplet> t(n, t1);

    for (int i = 0; i < 2 * n; i++)
    {
        int x;
        cin >> x;
        if (t[x].l == -1)
        {
            t[x].l = i;
        }
        else
        {
            t[x].r = i;
        }
        t[x - 1].index = x;
    }
    sort(t.begin(), t.end(), cmp);
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