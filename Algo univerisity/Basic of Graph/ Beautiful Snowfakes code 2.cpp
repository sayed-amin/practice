#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Union-Find (Disjoint Set Union) class
class UnionFind
{
public:
    UnionFind(int n) : parent(n), rank(n, 0), size(n, 1)
    {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unionSets(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
            }
            else if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            }
            else
            {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
                rank[rootU]++;
            }
            return true;
        }
        return false;
    }

    int componentSize(int u)
    {
        return size[find(u)];
    }

private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
};

int countBeautifulSnowflakes(int n, int m, const vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(n);
    vector<int> degree(n, 0);
    UnionFind uf(n);

    // Build the adjacency list and calculate degrees
    for (const auto &edge : edges)
    {
        int u = edge.first - 1;
        int v = edge.second - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
        uf.unionSets(u, v);
    }

    // Find all connected components
    unordered_map<int, vector<int>> components;
    for (int i = 0; i < n; ++i)
    {
        components[uf.find(i)].push_back(i);
    }

    // Check for snowflakes and count their sizes
    unordered_map<int, int> snowflakeSizes;
    for (const auto &comp : components)
    {
        const vector<int> &nodes = comp.second;
        int nonLeafCount = 0;
        for (int node : nodes)
        {
            if (degree[node] != 1)
            {
                nonLeafCount++;
            }
        }
        if (nonLeafCount == 1)
        {
            int size = nodes.size();
            snowflakeSizes[size]++;
        }
    }

    // Count beautiful snowflakes (unique sizes)
    int beautifulSnowflakes = 0;
    for (const auto &entry : snowflakeSizes)
    {
        if (entry.second == 1)
        {
            beautifulSnowflakes++;
        }
    }

    return beautifulSnowflakes;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i].first >> edges[i].second;
    }

    int result = countBeautifulSnowflakes(n, m, edges);
    cout << result << endl;

    return 0;
}
