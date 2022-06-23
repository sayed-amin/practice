#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int INF = 1e9 + 10;
const int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int y[] = {-1, 1, 0, -1, 1, -1, 1, 0};
int val[N][N];
int vis[N][N];
int level[N][N];
int n, m;
void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = 0;
            level[i][j] = INF;
        }
    }
}
bool isvalid(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return false;
    return true;
}
int bfs()
{
    queue<pair<int, int>> q;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            mx = max(mx, val[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (val[i][j] == mx)
            {
                q.push(make_pair(i, j));
                level[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    int ans = 0;
    while (!q.empty())
    {
        pair<int, int> v = q.front();
        int cr = v.first;
        int cc = v.second;
        q.pop();
        vis[cr][cc] = 1;
        for (int i = 0; i < 8; i++)
        {
            int xr = cr + x[i];
            int xc = cc + y[i];
            pair<int, int> xq = make_pair(xr, xc);
            if (isvalid(xr, xc) and vis[xr][xc] == 0)
            {
                q.push(xq);
                level[xr][xc] = level[cr][cc] + 1;
                vis[xr][xc] = 1;
                ans = max(ans, level[xr][xc]);
            }
        }
    }
    return ans;
}
void solve()
{
    reset();
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> val[i][j];
        }
    }
    cout << bfs() << endl;
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