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
        return;
    }

    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void build_sum(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start];
        return;
    }

    int mid = (start + end) / 2;
    build_sum(2 * node, start, mid);
    build_sum(2 * node + 1, mid + 1, end);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
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
int query_min(int node, int start, int end, int l, int r)
{
    if (start > r || end < l)
        return INT_MIN;
    if (l <= start and end <= r)
        return tree[node];
    int q1 = query_sum(2 * node, start, mid, l, r);
    int q2 = query_sum(2 * node + 1, mid + 1, end, l, r);
    return max(q1, q2);
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
int32_t main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    for (int i = 1; i < 15; i++)
    {
        cout << tree[i] << endl;
    }
    cout << query_sum(1, 0, n - 1, 1, 5);
    cout << querey_max(1, 0, n - 1, 1, 5);
    return 0;
}
