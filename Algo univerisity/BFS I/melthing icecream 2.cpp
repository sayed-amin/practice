#include <bits/stdc++.h>
using namespace std;

int n, m, k;

bool isvalid(int x, int y)
{
    return (x >= 0 and y >= 0 and x < n and y < m);
}

int main()
{
    cin >> n >> m >> k;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            mat[i][j] = s[j];
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> distance(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    if (mat[0][0] != '#')
    {
        q.push({0, 0});
        vis[0][0] = 1;
    }

    vector<pair<int, int>> coordinates = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;

        for (auto &pxy : coordinates)
        {
            int xx = x + pxy.first;
            int yy = y + pxy.second;
            if (!isvalid(xx, yy))
            {
                continue;
            }
            if (vis[xx][yy] || mat[xx][yy] == '#')
            {
                continue;
            }
            distance[xx][yy] = distance[x][y] + 1;
            q.push({xx, yy});
            vis[xx][yy] = 1;
        }
    }

    if (vis[n - 1][m - 1] == 0 || distance[n - 1][m - 1] > k)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}
