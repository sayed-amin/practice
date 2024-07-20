/*
most profitable team.cpp
08 July 2024
Mon 19:43

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void dfs(int node, vector<vector<int>> &adj, vector<int> &team_profit, vector<int> &profit, int &maxProfit, int par = -1)
{
    team_profit[node] += profit[node];
    for (auto child : adj[node])
    {
        if (child == par)
        {
            continue;
        }
        dfs(child, adj, team_profit, profit, maxProfit, node);
        team_profit[node] += team_profit[child];
    }
    maxProfit = max(maxProfit, team_profit[node]);
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> profit(n + 1);
    vector<int> team_profit(n + 1, 0);
    int maxProfit = LLONG_MIN;
    for (int i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> profit[i];
    }
    dfs(1, adj, team_profit, profit, maxProfit);
    cout << maxProfit;
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