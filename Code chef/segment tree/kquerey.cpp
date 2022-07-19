/*
kquerey.cpp
17 July 2022
Sun 16:38

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
vector<int> tree[N];
int a[N];
void build(int node, int start, int end)
{
    if (start == end)
        tree[node].push_back(a[start]);
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node].resize(tree[2 * node].size() + tree[2 * node + 1].size());
        int i, j, k;
        i = j = k = 0;
        while (j < tree[2 * node].size() and k < tree[2 * node + 1].size())
        {
            if (tree[2 * node][j] < tree[2 * node + 1][k])
            {
                tree[node][i] = tree[2 * node][j];
                i++, j++;
            }
            else
            {
                tree[node][i] = tree[2 * node + 1][k];
                i++, k++;
            }
        }
        while (j < tree[2 * node].size())
        {
            tree[node][i] = tree[2 * node][j];
            i++, j++;
        }
        while (k < tree[2 * node + 1].size())
        {
            tree[node][i] = tree[2 * node + 1][k];
            i++, k++;
        }
    }
}
int query(int node, int start, int end, int l, int r, int value)
{
    if (start > r || end < l)
        return 0;
    if (l <= start and end <= r)
        return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), value);
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r, value) + query(2 * node + 1, mid + 1, end, l, r, value);
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
    int ans = 0;
    while (q--)
    {
        int i, j, k;
        cin >> i >> j >> k;
        i = i ^ ans;
        j = j ^ ans;
        k = k ^ ans;
        i--, j--;
        cout << query(1, 0, n - 1, i, j, k) << endl;
        ;
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