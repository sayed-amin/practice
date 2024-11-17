#include <bits/stdc++.h>
using namespace std;

// Union-Find Data Structure
class UnionFind
{
private:
    vector<int> parent, rank;

public:
    UnionFind(int size)
    {
        parent.resize(size);
        rank.resize(size, 0);
        iota(parent.begin(), parent.end(), 0); // Initialize parent
    }

    int find(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    void unionSets(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

struct Edge
{
    int u, v;
    long long cost;
    bool operator<(const Edge &other) const
    {
        return cost < other.cost;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;

    vector<tuple<int, int, int>> cities(N);
    for (int i = 0; i < N; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        cities[i] = {x, y, z};
    }

    vector<Edge> edges;

    // Generate all possible edges based on Manhattan distance
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            auto [x1, y1, z1] = cities[i];
            auto [x2, y2, z2] = cities[j];
            long long dist = abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2);
            edges.push_back({i, j, dist * M});
        }
    }

    // Kruskal's Algorithm
    sort(edges.begin(), edges.end());

    UnionFind uf(N);
    long long mstCost = 0;
    int edgesUsed = 0;

    for (const Edge &e : edges)
    {
        if (uf.find(e.u) != uf.find(e.v))
        {
            uf.unionSets(e.u, e.v);
            mstCost += e.cost;
            edgesUsed++;
            if (edgesUsed == N - 1)
            {
                break;
            }
        }
    }

    if (edgesUsed == N - 1)
    {
        cout << mstCost << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
