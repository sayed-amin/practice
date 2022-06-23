/*
MGCRNK.cpp
23 June 2022
Thu 20:11

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
vector<vector<int>> grid;
vector<vector<int>> dp;
int g(int i, int j)
{
    if (i == grid.size() and j == grid.size())
        return 0;
    if (i >= grid.size() || j >= grid.size())
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == grid.size() - 1)
    {
        return dp[i][j] = grid[i][j] + g(i, j + 1);
    }
    else if (j == grid.size() - 1)
    {
        return dp[i][j] = grid[i][j] + g(i + 1, j);
    }
    return dp[i][j] = grid[i][j] + max(g(i + 1, j), g(i, j + 1));
}

void solve()
{

    cin >> n;
    grid.clear();
    dp.clear();
    grid.resize(n, vector<int>(n));
    dp.resize(n, vector<int>(n));
    // cout << dp[0][0] << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            dp[i][j] = -1;
        }
    }
    int h = g(0, 0);
    if (h < 0)
        cout << "Bad Judges" << endl;
    else
        cout << fixed << setprecision(6) << 1.0 * h / (2 * n - 3) << endl;
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
    }
    return 0;
}