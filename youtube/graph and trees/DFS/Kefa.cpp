#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cats;        // Stores whether a vertex has a cat (1) or not (0)
vector<vector<int>> adj; // Adjacency list representation of the tree
int m;                   // Maximum number of consecutive vertices with cats allowed

int validRestaurants(int v, int parent, int consecutiveCats)
{
    if (cats[v] == 1)
    {
        consecutiveCats++;
    }
    else
    {
        consecutiveCats = 0; // Reset consecutiveCats count if the current vertex doesn't have a cat
    }

    // Check if consecutiveCats count exceeds m
    if (consecutiveCats > m)
    {
        return 0; // Stop traversal along this path
    }

    // Check if u is a leaf node
    if (adj[v].size() == 1 && v != 1)
    {
        return 1; // This is a valid restaurant
    }

    int validRestaurantsCount = 0;
    for (int child : adj[v])
    {
        if (child != parent)
        { // Avoid visiting the parent vertex again
            validRestaurantsCount += validRestaurants(child, v, consecutiveCats);
        }
    }
    return validRestaurantsCount;
}

int main()
{
    int n;
    cin >> n >> m;

    // Initialize vectors
    cats.resize(n + 1);
    adj.resize(n + 1);

    // Read input
    for (int i = 1; i <= n; ++i)
    {
        cin >> cats[i];
    }

    // Read tree edges
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Perform DFS traversal starting from vertex 1
    int result = validRestaurants(1, -1, 0);
    cout << result << endl;

    return 0;
}
