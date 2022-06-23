#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> g;
vector<int> num;
void dfs(int v, int par = 0)
{
    num[v] = (num[par] & 1) ? 2 : 1;
    for (auto child : g[v])
    {
        if (par == child)
            continue;
        dfs(child, v);
    }
}
void solve()
{
    int n;
    cin >> n;
    num.assign(n + 1, 0);
    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << num[i] << " ";
    cout << endl;
    g.clear();
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