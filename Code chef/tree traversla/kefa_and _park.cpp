/*
kefa_and _park.cpp
19 July 2022
Tue 15:23

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int> ans;
vector<int> leaf;
int n, m;
int o = 0;
void dfs(int v, int par, vector<vector<int>> &g, vector<int> &a, int k)
{
    if (k > m)
        return;
    int flag = 1;
    for (auto child : g[v])
    {
        if (child == par)
            continue;
        flag = 0;
        ans[child] = k * (ans[child] + ans[v]);
        dfs(child, v, g, a, k * a[child] + a[child]);
    }
    o += flag;
}
void solve()
{
    cin >> n >> m;
    ans.assign(n + 1, 0);
    leaf.assign(n + 1, 0);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans[i] = a[i];
    }
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1, g, a, a[1]);
    cout << o << endl;
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