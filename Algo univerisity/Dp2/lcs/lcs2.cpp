/*
lcs2.cpp
21 December 2024
Sat 17:25

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int func(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    int ans = -1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
    {
        ans = max(ans, func(i - 1, j - 1, s1, s2, dp) + 1);
    }
    ans = max(ans, func(i - 1, j, s1, s2, dp));
    ans = max(ans, func(i, j - 1, s1, s2, dp));
    return dp[i][j] = ans;
}
int func2(string &s, string &t)
{
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
void solve()
{
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
    cout << func2(s, t) << endl;
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