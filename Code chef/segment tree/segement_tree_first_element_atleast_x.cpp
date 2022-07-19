/*
segement_tree_first_element_atleast_x.cpp
15 July 2022
Fri 19:41

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
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
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
        tree[node] = max(tree[node * 2], tree[2 * node + 1]);
    }
}
int querey_max(int node, int start, int end, int l, int r)
{
    if (start > r || end < l)
        return -1e15;
    if (l <= start and end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    int q1 = querey_max(2 * node, start, mid, l, r);
    int q2 = querey_max(2 * node + 1, mid + 1, end, l, r);
    return max(q1, q2);
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
            int l;
            cin >> l;
            int low = 0, high = n - 1, ans = n;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (querey_max(1, 0, n - 1, low, mid) < l)
                    low = mid + 1;
                else
                {
                    high = mid - 1;
                    ans = min(ans, mid);
                }
            }
            if (ans == n)
                cout << -1 << endl;
            else
                cout << ans << endl;
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