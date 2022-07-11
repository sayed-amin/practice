/*
edge_deletion.cpp
30 June 2022
Thu 05:58

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
vector<int> g[N];
int s[N];
void dfs(int v, int par = -1)
{
    s[v] += v;
    for (auto child : g[v])
    {
        if (child == par)
            continue;
        dfs(child, v);
        s[v] += s[child];
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        int part1 = s[i] % mod;
        int part2 = (s[1] % mod - part1 % mod) % mod;
        ans = max(ans, (part1 * part2) % mod);
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}