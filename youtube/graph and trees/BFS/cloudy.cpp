/*
cloudy.cpp
07 March 2024
Thu 09:26
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/cloudy-days-82a872ec/
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e3 + 10;
const int INF = 1e7 + 10;
vector<vector<int>> g(N);
vector<int> level(N, INF);
int vis[N];
void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    while (!q.empty())
    {
        int curr_v = q.front();
        q.pop();
        for (auto &child : g[curr_v])
        {
            if (vis[child])
                continue;

            vis[child] = 1;
            q.push(child);
            level[child] = level[curr_v] + 1;
        }
    }
}
void solve()
{
    int n, m, k, c;
    cin >> n >> m >> k >> c;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    level[c] = 0;
    bfs(c);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << i << " " << level[i] << endl;
        if (level[i] <= k)
            ans++;
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