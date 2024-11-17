/*
Nirvana.cpp
04 August 2024
Sun 15:02

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void dfs(int node, vector<vector<int>> &graph, vector<int> &status, vector<int> &result, bool &hasCycle)
{
    status[node] = 1; // visiting
    for (int neighbor : graph[node])
    {
        if (status[neighbor] == 0)
        {
            dfs(neighbor, graph, status, result, hasCycle);
        }
        else if (status[neighbor] == 1)
        {
            hasCycle = true; // found a cycle
        }
    }
    status[node] = 2; // visited
    if (!hasCycle)
    {
        result.push_back(node);
    }
}
vector<int> findSafeNodes(int n, vector<vector<int>> &graph)
{
    vector<int> status(n, 0);
    vector<int> result;
    for (int i = 0; i < n; ++i)
    {
        bool hasCycle = false;
        if (status[i] == 0)
        {
            dfs(i, graph, status, result, hasCycle);
        }
    }
    sort(result.begin(), result.end());
    return result;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> safeNodes = findSafeNodes(n, graph);
    cout << safeNodes.size() << " ";
    for (int node : safeNodes)
    {
        cout << node << " ";
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