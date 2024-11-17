/*
TilingCorridor.cpp
17 November 2024
Sun 11:53

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int modulo = 1000000007;
int recur(int n, vector<int> &dp)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = (recur(n - 1, dp) + recur(n - 2, dp)) % modulo;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);

    cout << recur(n, dp);
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