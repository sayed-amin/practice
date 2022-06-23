#include <bits/stdc++.h>
using namespace std;
#define int long long
int x, n;
const int N = 1e5 + 10;
vector<vector<int>> g(N);
vector<int> a(N);
int dfs(int v, int par)
{
    int sum = 0;
    for (auto child : g[v])
    {
        if (child != par)
            sum += dfs(child, v);
    }
    return max(sum + a[v], -x);
}
void solve()
{

    cin >> n >> x;
    a.clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << dfs(1, 0) << endl;
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