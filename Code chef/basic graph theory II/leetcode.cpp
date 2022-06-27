/*
leetcode.cpp
25 June 2022
Sat 20:32
dfs
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
vector<vector<int>> g(n);
vector<int> vis(n);
int ans;
void dfs(int v, int par = -1)
{
    vis[v] = 1;
    for (auto child : g[v])
    {
        if (child == par)
            continue;
        dfs(child, v);
    }
}
long long countPairs(int n, vector<vector<int>> &edges)
{
    for (auto i : edges)
    {
        g[i[0]].push_back(i[1]);
        g[i[1]].push_back(i[0]);
    }
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        ans = 0;
        dfs(i);
        a.push_back(ans);
    }
    for (auto i : a)
        cout << i << " ";
    return ans;
}
void solve()
{
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