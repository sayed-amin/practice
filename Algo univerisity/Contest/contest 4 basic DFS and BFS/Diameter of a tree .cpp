/*
Diameter of a tree .cpp
13 July 2024
Sat 13:59

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void dfs(int n, int par, vector<vector<int>> &adj, vector<int> &depth)
{
    for (auto child : adj[n])
    {
        if (child == par)
        {
            continue;
        }
        depth[child] = depth[n] + 1;
        dfs(child, n, adj, depth);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> depth(n + 1, 0);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1, adj, depth);
    int max_node;
    int max_depth = -1;
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] > max_depth)
        {
            max_node = i;
            max_depth = depth[i];
        }
        depth[i] = 0;
    }
    // cout << max_node << endl;
    dfs(max_node, -1, adj, depth);
    max_depth = -1;
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] > max_depth)
        {
            max_node = i;
            max_depth = depth[i];
        }
        depth[i] = 0;
    }
    cout << max_depth << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}