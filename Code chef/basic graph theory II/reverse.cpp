#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back({v, 0});
        g[v].push_back({u, 1});
    }
    priority_queue<pair<int, int>> q;
    vector<int> dist(n + 1, 1e9);
    q.push({0, 1});
    dist[1] = 0;
    int count = 0;
    int flag = 0;
    while (!q.empty())
    {
        auto temp = q.top().second;
        q.pop();
        for (auto val : g[temp])
        {
            int v = val.first;
            int wei = val.second;
            if (dist[v] > dist[temp] + wei)
            {
                dist[v] = dist[temp] + wei;
                q.push({-wei, v});
            }
        }
    }
    if (dist[n] >= 1e9)
        cout << -1 << endl;
    else
        cout << dist[n] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}