/*
Beautiful Snowflakes.cpp
30 June 2024
Sun 18:13

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void findconnectedcomponents(int n, vector<vector<int>> &adj, vector<vector<int>> &components)
{
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        vector<int> component;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            component.push_back(node);
            for (int child : adj[node])
            {
                if (vis[child])
                {
                    continue;
                }
                vis[child] = true;
                q.push(child);
            }
        }
        components.push_back(component);
    }
}
bool issnowflake(const vector<int> &component, const vector<int> &degrees)
{
    int centerCount = 0;
    for (int node : component)
    {
        if (degrees[node] != 1)
        {
            if (++centerCount > 1)
                return false;
        }
    }
    return centerCount == 1;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> degrees(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degrees[u]++;
        degrees[v]++;
    }
    vector<vector<int>> components;

    findconnectedcomponents(n, adj, components);

    unordered_map<int, int> snowfalkessizes;
    for (const auto &component : components)
    {
        if (issnowflake(component, degrees))
        {
            int size = component.size();
            snowfalkessizes[size]++;
        }
    }
    int beautifulSnowflakes = 0;
    for (const auto &entry : snowfalkessizes)
    {
        if (entry.second == 1)
        {
            beautifulSnowflakes++;
        }
    }
    cout << beautifulSnowflakes << endl;
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