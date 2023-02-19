/*
NAKANJ.cpp
01 July 2022
Fri 19:19
https://www.spoj.com/problems/NAKANJ/
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int vis[8][8];
int level[8][8];
int px[] = {-1, 1, -1, 1, 2, 2, -2, -2};
int py[] = {2, 2, -2, -2, -1, 1, -1, 1};
int getx(string s)
{
    return s[0] - 'a';
}
bool isvalid(int x, int y)
{
    return x >= 0 and y >= 0 and x < 8 and y < 8;
}
int gety(string s)
{
    return s[1] - '1';
}
int bfs(string source, string dest)
{
    int sx = getx(source);
    int sy = gety(source);
    int dx = getx(dest);
    int dy = gety(dest);
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;
    while (!q.empty())
    {
        pair<int, int> c = q.front();
        q.pop();
        int x = c.first;
        int y = c.second;
        for (auto i = 0; i < 8; i++)
        {
            int x1 = px[i] + x;
            int y1 = py[i] + y;
            if (!isvalid(x1, y1))
                continue;
            if (vis[x1][y1])
                continue;
            vis[x1][y1] = 1;
            q.push({x1, y1});
            level[x1][y1] = level[x][y] + 1;
        }
    }
    return level[dx][dy];
}
void reset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = 0;
            vis[i][j] = 0;
        }
    }
}
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << bfs(s1, s2) << endl;
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
        reset();
    }
    return 0;
}