#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX

// Dijkstra's algorithm to find the shortest path from source to all other nodes
vector<int> dijkstra(int source, const vector<vector<pair<int, int>>> &graph, int N)
{
    vector<int> dist(N + 1, INF);
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

        for (auto &[v, cost] : graph[u])
        {
            if (dist[u] + cost < dist[v])
            {
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

void solve()
{
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);
    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < M; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].emplace_back(v, c);
        edges.emplace_back(u, v, c);
    }

    // Find shortest path from 1 to all nodes
    vector<int> distFrom1 = dijkstra(1, graph, N);

    // Create a reverse graph to find shortest path from all nodes to N
    vector<vector<pair<int, int>>> reverseGraph(N + 1);
    for (int i = 0; i < M; ++i)
    {
        auto [u, v, c] = edges[i];
        reverseGraph[v].emplace_back(u, c);
    }

    // Find shortest path from all nodes to N
    vector<int> distToN = dijkstra(N, reverseGraph, N);

    // Calculate the minimum cost considering the discount on each edge
    int minCost = distFrom1[N];
    for (auto &[u, v, c] : edges)
    {
        int discountedCost = c / 2;
        if (distFrom1[u] < INF && distToN[v] < INF)
        {
            minCost = min(minCost, distFrom1[u] + discountedCost + distToN[v]);
        }
    }

    cout << minCost << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
