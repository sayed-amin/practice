/*
Minimum_jumps.cpp
30 June 2024
Sun 20:53

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> distance(n, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int source, destination;
    cin >> source >> destination;
    source--, destination--;
    queue<int> q;
    q.push(source);
    vector<bool> vis(n, false);
    distance[source] = 0;
    vis[source] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto child : adj[node])
        {
            if (vis[child])
            {
                continue;
            }
            q.push(child);
            vis[child] = 1;
            distance[child] = distance[node] + 1;
        }
    }
    if (distance[destination] == -1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << distance[destination] << endl;
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