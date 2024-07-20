/*
impoartant nodes.cpp
13 July 2024
Sat 14:50

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int> bfs(int node, int n, vector<vector<int>> &adj)
{
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(node);
    dist[node] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto child : adj[v])
        {
            if (dist[child] == -1)
            {
                dist[child] = dist[v] + 1;

                q.push(child);
            }
        }
    }
    return dist;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> distFrom1 = bfs(1, n, adj);
    vector<int> distFromn = bfs(n, n, adj);
    int shortestPath = distFrom1[n];
    if (shortestPath == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<int> result;
        for (int i = 1; i <= n; i++)
        {
            if (distFrom1[i] + distFromn[i] == shortestPath)
            {
                result.push_back(i);
            }
        }
        sort(result.begin(), result.end());
        for (int node : result)
        {
            cout << node << " ";
        }
    }
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