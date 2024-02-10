/*
diameter.cpp
29 June 2022
Wed 07:36

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5;
vector<int> g[N];
int depth[N], height[N], subtree_sum[N], even[N];
void dfs(int v, int par = -1)
{
    /*
          Take action on vertex after entering the vertex
     */

    for (auto child : g[v])
    {
        if (child == par)
            continue;
        /*
          Take action on child before entering the child node
        */
        depth[child] = depth[v] + 1;
        dfs(child, v);
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
    int max_node;
    int max_depth = -1;
    for (int i = 1; i < n; i++)
    {
        if (depth[i] > max_depth)
        {
            max_node = i;
            max_depth = depth[i];
        }
        depth[i] = 0;
    }
    dfs(max_node);
    max_depth = -1;
    for (int i = 1; i < n; i++)
    {
        if (depth[i] > max_depth)
        {
            max_node = i;
            max_depth = depth[i];
        }
        depth[i] = 0;
    }
    cout << max_depth << endl;
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