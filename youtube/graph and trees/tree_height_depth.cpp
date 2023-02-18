/*
tree_height_depth.cpp
29 June 2022
Wed 06:49
https://www.youtube.com/watch?v=i_FktdKVXDc&list=PLauivoElc3ghxyYSr_sVnDUc_ynPk6iXE&index=7
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5;
vector<int> g[N];
int depth[N], height[N];
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
        height[v] = max(height[child] + 1, height[v]);
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