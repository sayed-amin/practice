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
    int u, v, cost;
    bool operator<(const Edge &other) const
    {
        return cost < other.cost;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    for (int i = 0; i < M; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
        edges[i].u--; // Convert to 0-based index
        edges[i].v--;
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
