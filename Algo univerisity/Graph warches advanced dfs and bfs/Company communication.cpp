/*
Company communication.cpp
02 August 2024
Fri 09:02

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void dfs(int source, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[source] = true;
    for (int child : adj[source])
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
    vector<vector<int>> adj(n + m + 1);
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int x;
            cin >> x;
            adj[i].push_back(n + x);
            adj[n + x].push_back(i);
        }
    }
    vector<bool> vis(n + m + 1, 0);
    dfs(1, adj, vis);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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