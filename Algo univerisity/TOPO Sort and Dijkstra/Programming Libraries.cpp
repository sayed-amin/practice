/*
Programming Libraries.cpp
04 August 2024
Sun 12:39

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
    vector<int> inDegree(n, 0);

    // Read the dependencies and build the adjacency list and in-degree count
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;
    // Push all vertices with in-degree 0 into the queue
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> topOrder;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topOrder.push_back(u);

        // Reduce the in-degree of all adjacent vertices
        for (int child : adj[u])
        {
            inDegree[child]--;
            if (inDegree[child] == 0)
                q.push(child);
        }
    }

    // Output the topological order
    for (auto i : topOrder)
        cout << i << " ";
    cout << endl;
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
