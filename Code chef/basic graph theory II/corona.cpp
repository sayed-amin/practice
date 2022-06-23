#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n + 1);
    vector<int> dist(n + 1, 1e15);
    set<pair<int, int>> s;
    for (int i = 0; i < k; i++)
    {
        int city, cost_vac;
        cin >> city >> cost_vac;
        dist[city] = cost_vac;
        s.insert({cost_vac, city});
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        g[u].push_back({v, weight});
        g[v].push_back({u, weight});
    }
    while (!s.empty())
    {

        auto x = *(s.begin());
        s.erase(x);
        for (auto i : g[x.second])
        {
            if (dist[i.first] > dist[x.second] + i.second)
            {
                s.erase({dist[i.first], i.first});
                dist[i.first] = dist[x.second] + i.second;
                s.insert({dist[i.first], i.first});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}