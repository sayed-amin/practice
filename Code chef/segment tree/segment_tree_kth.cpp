/*
segment_tree_for_sum.cpp
11 July 2022
Mon 07:38

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
        tree[node] = a[start];
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
void update(int node, int start, int end, int pos)
{
    if (start == end)
    {
        if (a[start] == 0)
        {
            a[start] = 1;
            tree[node] = 1;
        }
        else
        {
            a[start] = 0;
            tree[node] = 0;
        }
    }
    else
    {
        int mid = (start + end) / 2;
        if (pos <= mid)
            update(2 * node, start, mid, pos);
        else
            update(2 * node + 1, mid + 1, end, pos);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
int find_kth(int node, int start, int end, int k)
{
    if (start == end)
        return start;
    int mid = (start + end) / 2;
    if (k < tree[2 * node])
        return find_kth(2 * node, start, mid, k);
    else
        return find_kth(2 * node + 1, mid + 1, end, k - tree[2 * node]);
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
            int pos;
            cin >> pos;

            update(1, 0, n - 1, pos);
        }
        else
        {
            int kth;
            cin >> kth;
            cout << find_kth(1, 0, n - 1, kth) << endl;
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