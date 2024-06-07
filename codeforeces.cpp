/*
codeforeces.cpp
21 February 2024
Wed 13:59

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<vector<int>> g;
vector<int> cats;
int n, m;
int dfs(int v, int par = -1, int consecutive_cats = 0)
{
    if (cats[v] == 1)
    {
        consecutive_cats++;
    }
    else
    {
        consecutive_cats = 0;
    }
    if (consecutive_cats > m)
    {
        return 0;
    }
    if (g[v].size() == 1 and v != 1)
        return 1;
    int ans = 0;
    for (auto child : g[v])
    {
        if (child != par)
        {
            ans += dfs(child, v, consecutive_cats);
        }
    }
    return ans;
}
void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    cats.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> cats[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << dfs(1) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}