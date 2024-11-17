/*
Good luck path.cpp
03 August 2024
Sat 13:09

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    set<array<int, 3>> triplets;
    for (int i = 0; i < k; ++i)
    {
        int x, y, z;

        cin >> x >> y >> z;
        --x, --y, --z;
        triplets.insert({x, y, z});
    }
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(n, {-1, -1}));
    queue<pair<int, int>> q;
    set<pair<int, int>> vis;
    q.push({0, 0});
    vis.insert({0, 0});
    bool found = false;
    while (q.size())
    {
        auto p = q.front();
        q.pop();
        int vf = p.first;
        int vs = p.second;
        for (int u : adj[vs])
        {
            if (triplets.find({vf, vs, u}) != triplets.end())
                continue;
            if (vis.find({vs, u}) != vis.end())
                continue;
            par[vs][u] = p;
            q.push({vs, u});
            vis.insert({vs, u});
            if (u == n - 1)
                found = true;
            if (found)
                break;
        }
        if (found)
            break;
    }
    for (int i = 0; i < n; ++i)
    {
        if (par[i][n - 1] != pair<int, int>(-1, -1))
        {
            // ans is here
            vector<int> path;
            pair<int, int> cur = {i, n - 1};
            while (cur != pair<int, int>(-1, -1))
            {
                int vf = cur.first;
                int vs = cur.second;
                int pf = par[vf][vs].first;
                int ps = par[vf][vs].second;
                path.push_back(vs);
                cur = {pf, ps};
            }
            reverse(path.begin(), path.end());
            cout << path.size() - 1 << endl;
            for (int p : path)
                cout << p + 1 << " ";
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}