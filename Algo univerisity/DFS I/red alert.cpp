/*
red alert.cpp
08 July 2024
Mon 20:05

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int dfs(int node, vector<vector<int>> &adj, vector<int> &flag, int par, int countred, int c)
{
    if (flag[node] == 1)
    {
        countred++;
    }
    else
    {
        countred = 0;
    }
    if (countred > c)
        return 0;
    if (adj[node].size() == 1 && node != 1)
        return 1;
    int visited_leaf = 0;
    for (auto child : adj[node])
    {
        if (child == par)
        {
            continue;
        }

        visited_leaf += dfs(child, adj, flag, node, countred, c);
    }
    return visited_leaf;
}
void solve()
{
    int n, c;
    cin >> n >> c;
    vector<vector<int>> adj(n + 1);
    vector<int> flag(n + 1);
    int countred = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> flag[i];
    }
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << dfs(1, adj, flag, -1, countred, c) << endl;
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