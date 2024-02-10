/*
Toa.cpp
02 October 2023
Mon 19:14
https://atcoder.jp/contests/dp/tasks/dp_c
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> activities(N, vector<int>(3));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> activities[i][j];
        }
    }
    vector<vector<int>> dp(N, vector<int>(3, 0));
    for (int j = 0; j < 3; ++j)
    {
        dp[0][j] = activities[0][j];
    }

    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                if (j != k)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + activities[i][j]);
                }
            }
        }
    }
    int result = max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
    cout << result << endl;
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