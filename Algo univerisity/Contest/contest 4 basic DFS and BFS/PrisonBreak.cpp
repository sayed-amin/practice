/*
PrisonBreak.cpp
13 July 2024
Sat 15:14

*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int directions = 4;
int px[directions] = {0, 0, -1, 1}; // Left, Right, Up, Down
int py[directions] = {-1, 1, 0, 0}; // Left, Right, Up, Down

bool isValid(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
bool isBoundary(int x, int y, int n, int m)
{
    return x == 0 || x == n - 1 || y == 0 || y == m - 1;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> prison(n, vector<char>(m));
    vector<vector<int>> monsterTime(n, vector<int>(m, INF));
    pair<int, int> start;

    queue<pair<int, int>> monsterQueue;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> prison[i][j];
            if (prison[i][j] == 'M')
            {
                monsterQueue.push({i, j});
                monsterTime[i][j] = 0;
            }
            else if (prison[i][j] == 'A')
            {
                start = {i, j};
            }
        }
    }

    // BFS for monsters
    while (!monsterQueue.empty())
    {
        auto [x, y] = monsterQueue.front();
        monsterQueue.pop();
        for (int i = 0; i < directions; ++i)
        {
            int nx = x + px[i];
            int ny = y + py[i];
            if (isValid(nx, ny, n, m) && prison[nx][ny] == '.' && monsterTime[nx][ny] == INF)
            {
                monsterTime[nx][ny] = monsterTime[x][y] + 1;
                monsterQueue.push({nx, ny});
            }
        }
    }

    queue<pair<int, pair<int, int>>> playerQueue;
    playerQueue.push({0, start});
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[start.first][start.second] = true;
    if (isBoundary(start.first, start.second, n, m))
    {
        cout << "YES" << endl;
        return;
    }
    while (!playerQueue.empty())
    {
        auto [time, pos] = playerQueue.front();
        auto [x, y] = pos;
        playerQueue.pop();

        if (isValid(x, y, n, m) && isBoundary(x, y, n, m) && prison[x][y] == '.')
        {
            cout << "YES" << endl;
            return;
        }

        for (int i = 0; i < directions; ++i)
        {
            int nx = x + px[i];
            int ny = y + py[i];
            if (isValid(nx, ny, n, m) && prison[nx][ny] == '.' && !visited[nx][ny])
            {
                if (time + 1 < monsterTime[nx][ny])
                {
                    visited[nx][ny] = true;
                    playerQueue.push({time + 1, {nx, ny}});
                }
            }
        }
    }

    cout << "NO" << endl;
}

int main()
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
