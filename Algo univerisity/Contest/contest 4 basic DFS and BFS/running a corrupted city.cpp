/*
running a corrupted city.cpp
13 July 2024
Sat 14:27

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int dfs(int node, vector<vector<int>> &adj, int par = -1)
{
    int ans = 0;
    if (adj[node].size() == 1 and node != 1)
    {
        return node;
    }
    int child_amount = 0;
    for (auto child : adj[node])
    {
        if (child == par)
        {
            continue;
        }
        child_amount += dfs(child, adj, node);
    }
    return (child_amount - (child_amount / 10));
}
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int total_tax = dfs(1, adj);

    if (total_tax >= x)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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