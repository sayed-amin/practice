/*
TestSample.cpp
01 January 2025
Wed 07:16

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int minLenght(string &s, string &t, int n, int m, vector<vector<int>> &dp)
{
    int ans = INT_MAX;
    if (n < 0)
    {
        return m + 1;
    }
    if (m < 0)
    {
        return n + 1;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (s[n] == t[m])
    {
        ans = min(minLenght(s, t, n - 1, m - 1, dp), ans);
    }
    else
    {
        // delete
        ans = min(minLenght(s, t, n - 1, m, dp), ans);
        ans = min(ans, minLenght(s, t, n - 1, m - 1, dp));
        ans = min(ans, minLenght(s, t, n, m - 1, dp));
        ans++;
    }
    return dp[n][m] = ans;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << minLenght(s, t, n - 1, m - 1, dp) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}