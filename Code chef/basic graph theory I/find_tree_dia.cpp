// diameter if the tree
#include <bits/stdc++.h>
using namespace std;

void dep(int v, int par, vector<vector<int>> &g, int depth[])
{

    for (int child : g[v])
    {
        if (child == par)
            continue;
        depth[child] = depth[v] + 1;
        dep(child, v, g, depth);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    int depth[n + 1];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dep(1, -1, g, depth);
    int mx_dep = -1;
    int mx_node;
    for (int i = 1; i <= n; i++)
    {
        if (mx_dep < depth[i])
        {
            mx_dep = depth[i];
            mx_node = i;
        }
        depth[i] = 0;
    }
    dep(mx_node, -1, g, depth);
    mx_dep = -1;
    for (int i = 1; i <= n; i++)
    {
        if (mx_dep < depth[i])
        {
            mx_dep = depth[i];
        }
    }
    cout << mx_dep << endl;
}
int32_t main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}