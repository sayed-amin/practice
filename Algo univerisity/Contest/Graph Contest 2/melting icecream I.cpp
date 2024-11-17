/*
melting icecream I.cpp
04 August 2024
Sun 14:02

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n, m, k;
bool isvalid(int x, int y)
{
    return x >= 0 and x < n and y >= 0 and y < m;
}
void solve()
{

    cin >> n >> m >> k;
    //  int u, v;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    q.push({0, 0});
    vis[0][0] = 1;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;

        for (auto direc : directions)
        {
            int new_x = x + direc.first;
            int new_y = y + direc.second;
            if (isvalid(new_x, new_y))
            {
                if (vis[new_x][new_y])
                {
                    continue;
                }
                vis[new_x][new_y] = 1;
                dist[new_x][new_y] = dist[x][y] + 1;
                q.push({new_x, new_y});
            }
        }
    }
    if (dist[n - 1][m - 1] <= k)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}