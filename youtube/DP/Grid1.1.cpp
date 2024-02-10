/*
Grid1.1.cpp
02 February 2024
Fri 11:16

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int Mod = 1e9 + 7;
int h, w;
int countPaths(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &dp)
{
    if (i < 1 or j < 1 or i > h or j > w or grid[i][j] == '#')
        return 0;
    if (i == (h) and j == (w))
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int rightpath = countPaths(i, j + 1, grid, dp) % Mod;
    int downpath = countPaths(i + 1, j, grid, dp) % Mod;
    return dp[i][j] = (rightpath + downpath) % Mod;
}
void solve()
{
    cin >> h >> w;
    vector<vector<char>> grid(h + 1, vector<char>(w + 1, 0));
    vector<vector<int>> dp(h + 1, vector<int>(w + 1, -1));
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << countPaths(1, 1, grid, dp) << endl;
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