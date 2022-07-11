/*
diameter.cpp
29 June 2022
Wed 07:36

*/
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
const int N = 1e5 + 10;
vector<int> g[N];
int p[N];
void dfs(int v, int par = -1)
{

    p[v] = par;
    for (auto child : g[v])
    {
        if (child == par)
            continue;
        dfs(child, v);
    }
}
vector<int> path(int v)
{
    vector<int> ans;
    while (v != -1)
    {
        ans.push_back(v);
        v = p[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
    int x, y;
    cin >> x >> y;
    vector<int> px = path(x);
    vector<int> py = path(y);
    int min_len = min(px.size(), py.size());
    int lca = -1;
    for (int i = 0; i < min_len; i++)
    {
        if (px[i] == py[i])
        {
            lca = px[i];
        }
        else
            break;
    }
    cout << lca << endl;
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