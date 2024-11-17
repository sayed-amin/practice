/*
farthest node.cpp
02 August 2024
Fri 08:14

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void dfs(int source, vector<vector<int>> &g, vector<int> &depth, int par = -1)
{

    for (auto child : g[source])
    {
        if (child == par)
        {
            continue;
        }
        depth[child] = depth[source] + 1;
        dfs(child, g, depth, source);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    vector<int> deptha(n + 1, 0);
    vector<int> depthb(n + 1, 0);
    vector<int> depthc(n + 1, 0);
    dfs(1, adj, deptha);
    int max_node_a = 1;

    for (int i = 1; i <= n; i++)
    {
        if (deptha[i] > deptha[max_node_a])
        {
            max_node_a = i;
        }
    }

    dfs(max_node_a, adj, depthb);
    int max_node_b = max_node_a;
    for (int i = 1; i <= n; i++)
    {
        if (depthb[i] > depthb[max_node_b])
        {
            max_node_b = i;
        }
    }
    dfs(max_node_b, adj, depthc);

    for (int i = 1; i <= n; i++)
    {
        cout << max(depthb[i], depthc[i]) << " ";
    }
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