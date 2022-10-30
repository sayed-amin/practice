// bfs
#include <bits/stdc++.h>
using namespace std;

bool isvalid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > 8 || y > 8)
        return false;
    return true
}
void solve()
{
    int col, row, k;
    cin >> row >> col >> k;
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    int x[] = {-1, 1, -1, 0, 0, 1, 1, -1};
    int y[] = {-1, 1, 0, -1, 1, 0, -1, 1};
    vector<vector<int>> vis(9, vector<int>(9, 0));
    vector<vector<int>> moves(9, vector<int>(9, 0));
    while (!q.empty())
    {
        pair<int, int> currposs = q.front();
        int crow = currposs.first;
        int ccol = currposs.second;
        q.pop();
        vis[crow][ccol] = 1;
        for (int i = 0; i < 8; i++)
        {
            int xr = crow + x[i];
            int xc = ccol + y[i];
            pair<int, int> nexcell = make_pair(xr, xc);
            if (isvalid(xr, xc) and vis[xr][xc] == 0)
            {
                q.push(nexcell);
                moves[xr][xc] = moves[crow][ccol] + 1;
                vis[xr][xc] = 1;
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
        {
            if (moves[i][j] <= k)
                count++;
        }
    cout << count << endl;
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