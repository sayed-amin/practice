/*
Back to square one.cpp
02 August 2024
Fri 07:46

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool dfs(vector<vector<int>> &adj, vector<int> &vis, int source)
{

    vis[source] = 1;
    bool ans = false;
    for (auto child : adj[source])
    {
        if (vis[child] == 1)
        {
            ans = true;
        }
        if (vis[child] == 0)
        {
            ans |= dfs(adj, vis, child);
        }
    }
    vis[source] = 2;
    return ans;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int ans = false;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            ans |= dfs(adj, vis, i);
        }
    }
    if (ans)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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