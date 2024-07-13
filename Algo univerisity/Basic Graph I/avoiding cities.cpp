/*
avoiding cities.cpp
30 June 2024
Sun 21:44

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    int source, destination;
    cin >> source >> destination;
    vector<int> cursed(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cursed[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n, false);
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