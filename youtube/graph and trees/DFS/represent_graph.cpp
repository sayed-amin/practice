/*
represent_graph.cpp
17 February 2023
Fri 23:26
how to represent graph
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e3 + 10;
int graph[N][N];
vector<int> graph2[N];
vector<vector<int>> g(N);
void solve()
{
    /// @brief /////
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;

        graph2[x].push_back(y);
        graph2[y].push_back(x);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout << graph[1][3] << endl;
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