/*
Bfs.cpp
19 February 2023
Sun 04:55
breadth first serach
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
vector<int> g[N];
int vis[N];
int level[N];
void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    while (!q.empty())
    {
        int curr_v = q.front();
        q.pop();
        for (auto child : g[curr_v])
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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
    for (int i = 1; i <= n; i++)
        cout << level[i] << endl;
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