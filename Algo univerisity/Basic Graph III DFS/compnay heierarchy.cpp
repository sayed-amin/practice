/*
compnay heierarchy.cpp
08 July 2024
Mon 18:59

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void dfs(int node, vector<vector<int>> &adj, vector<int> &children, int par = -1)
{
    for (auto child : adj[node])
    {
        if (child == par)
        {
            continue;
        }
        // children[node] = children[child] + 1;
        dfs(child, adj, children, node);
        children[node] += children[child] + 1;
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> child(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        adj[i].push_back(u);
        adj[u].push_back(i);
    }
    dfs(1, adj, child);
    for (int i = 1; i <= n; i++)
    {
        cout << child[i] << " ";
    }
    cout << endl;
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