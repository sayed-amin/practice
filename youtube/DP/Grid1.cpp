/*
Grid1.cpp
02 February 2024
Fri 08:25

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int Mod = 1e9 + 7;
int h, w;

void solve()
{

    cin >> h >> w;
    vector<vector<char>> grid(h + 1, vector<char>(w + 1, 0));
    vector<vector<int>> dp(h + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> grid[i][j];
        }
    }
    dp[1][1] = 1;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (grid[i][j] == '#')
                dp[i][j] = 0;
            else
            {
                if (i > 1)
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j]) % Mod;
                }
                if (j > 1)
                {
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % Mod;
                }
            }
        }
    }

    cout << dp[h][w] << endl;
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