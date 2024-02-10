/*
Longest Path .cpp
01 February 2024
Thu 19:43

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
vector<int> g[N];
vector<int> vis(N);
vector<int> dp(N + 1, 0);
int length = 0;
void dfs(int v)
{
    vis[v] = 1;

    for (auto child : g[v])
    {
        if (!vis[child])
            dfs(child);
        dp[v] = max(dp[v], dp[child] + 1);
    }
}
void solve()
{
    fill(vis.begin(), vis.end(), 0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        dfs(i);
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}