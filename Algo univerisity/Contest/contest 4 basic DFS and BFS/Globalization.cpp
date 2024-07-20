/*
Globalization.cpp
13 July 2024
Sat 14:17

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (vis[child])
        {
            continue;
        }
        dfs(child, adj, vis);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> vis(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int connected_components = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        dfs(i, adj, vis);
        connected_components++;
    }
    cout << connected_components - 1;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    //  cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}