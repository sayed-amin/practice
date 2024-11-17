/*
Valentine Gifts.cpp
04 August 2024
Sun 14:18

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int INF = 1e18;
void dijkstra(int source, vector<vector<pair<int, int>>> &adj, vector<int> &dist)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    dist[source] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int q, k;
    cin >> q >> k;
    vector<int> dist(n + 1, INF);
    dijkstra(k, adj, dist);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << dist[x] + dist[y] << endl;
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