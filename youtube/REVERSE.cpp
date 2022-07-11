/*
REVERSE.cpp
01 July 2022
Fri 21:06
0 1 bfs
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> g[N];
vector<int> level(N, INF);
int n, m;
int bfs()
{
    deque<int> q;
    q.push_back(1);
    level[1] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop_front();
        for (auto child : g[curr])
        {
            int cv = child.first;
            int we = child.second;
            if (level[curr] + we < level[cv])
            {
                level[cv] = level[curr] + we;
                if (we == 1)
                    q.push_back(cv);
                else
                    q.push_front(cv);
            }
        }
    }
    if (level[n] == INF)
        return -1;
    return level[n];
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == v)
            continue;
        g[u].push_back({v, 0});
        g[v].push_back({u, 1});
    }
    cout << bfs() << endl;
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