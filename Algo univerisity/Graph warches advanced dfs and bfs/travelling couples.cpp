/*
travelling couples.cpp
24 July 2024
Wed 07:36

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int c1, c2, c3, n, m;
vector<vector<int>> adj;
vector<int> bfs(int source)
{
    queue<int> q;
    vector<int> dist(n + 1, -1);
    dist[source] = 0;
    q.push(source);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int child : adj[u])
        {
            if (dist[child] == -1)
            {
                dist[child] = dist[u] + 1;
                q.push(child);
            }
        }
    }
    return dist;
}
void solve()
{

    cin >> c1 >> c2 >> c3 >> n >> m;
    adj.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> d1 = bfs(1);
    vector<int> d2 = bfs(2);
    vector<int> d3 = bfs(n);
    int ans = d1[n] * c1 + d2[n] * c2;
    for (int i = 1; i <= n; i++)
    {
        int temp = d1[i] * c1 + d2[i] * c2 + d3[i] * c3;
        ans = min(ans, temp);
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    //  cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}