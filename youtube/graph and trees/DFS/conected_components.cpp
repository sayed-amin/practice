/*
cycle_CC.cpp
18 February 2023
Sat 11:45
cycle and connected components
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
vector<int> g[N];
vector<int> vis(N);
void dfs(int v)
{
    /*
      Take action on vertex after entering the vertex
    */
    vis[v] = 1;
    for (auto child : g[v])
    {
        if (vis[child])
            continue;
        /*
        Take action on child before entering the child node
        */
        dfs(child);
        /*
        Take action on child after existing the child node
        */
    }
    /*
    Take action on vertex before exiting the vertex
    */
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        dfs(i);
        count++;
    }
    cout << count << endl;
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