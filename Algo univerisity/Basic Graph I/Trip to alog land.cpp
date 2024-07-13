/*
Trip to alog land.cpp
30 June 2024
Sun 21:57

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<string, string>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        string u, v, l;
        cin >> u >> v >> l;
        adj[u].push_back({v, l});
    }
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