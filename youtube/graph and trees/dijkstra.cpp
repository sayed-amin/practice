/*
dijkstra.cpp
02 July 2022
Sat 05:51
dijkstra
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
// first->vertex second->weight
vector<pair<int, int>> g[N];

void djkstra(int source)
{
    vector<int> dist(N, INF);
    vector<int> vis(N, 0);
    // first->weight second->vertex
    set<pair<int, int>> s;
    s.insert({0, source});
    dist[source] = 0;
    while (!s.empty())
    {
        auto node = *s.begin();
        int wt_par = node.first;
        int par = node.second;
        s.erase(s.begin());

        if (vis[par])
            continue;
        vis[par] = 1;
        for (auto child : g[par])
        {
            int child_v = child.first;
            int child_wt = child.second;
            if (dist[par] + child_wt < dist[child_v])
            {
                dist[child_v] = dist[par] + child_wt;
                s.insert({dist[child_v], child_v});
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
        g[y].push_back({x, wt});
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}