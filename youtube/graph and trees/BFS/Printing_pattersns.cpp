/*
Printing_pattersns.cpp
07 March 2024
Thu 15:01
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/waves-b18625d7/
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int r, c;

bool isvalid(int x, int y)
{
    return (x >= 0 and y >= 0 and x < r and y < c);
}
void bfs(int x, int y, vector<vector<int>> &level, vector<vector<int>> &vis)

{
    queue<pair<int, int>> q;
    q.push({x, y});
    vector<pair<int, int>> coordinates = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    vis[x][y] = 1;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int xx = p.first;
        int yy = p.second;
        ˀ¯
            ˀ for (auto &pxy : coordinates)
        {
            ˀˀ int xxx = xx + pxy.first;
            int yyy = yy + pxy.second;
            if (!isvalid(xxx, yyy))
            {
                continue;
            }
            if (vis[xxx][yyy])
                continue;
            level[xxx][yyy] = level[xx][yy] + 1;
            q.push({xxx, yyy});
            vis[xxx][yyy] = 1;
        }
    }
}
void solve()
{

    cin >> r >> c;
    int x, y;
    cin >> x >> y;
    vector<vector<int>> level(r, vector<int>(c, 0));
    vector<vector<int>> vis(r, vector<int>(c, 0));
    bfs(x, y, level, vis);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << level[i][j] << " ";
        }
        cout << endl;
    }
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