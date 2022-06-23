#include <bits/stdc++.h>
using namespace std;
#define int long long
int length = 0;
bool cycle(vector<vector<int>> &g, vector<bool> &vis, int v, int par = -1)
{

    vis[v] = true;
    length++;
    bool isexist = false;
    for (auto child : g[v])
    {
        if ((child == par) and vis[child])
            continue;
        if (vis[child])
            return true;
        isexist |= cycle(g, vis, child, v);
    }
    return isexist;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> vis(n + 1, false);
    bool exit = false;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        if (cycle(g, vis, i) && (length & 1))
        {
            exit = true;
            break;
        }
        length = 0;
    }
    if (exit)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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