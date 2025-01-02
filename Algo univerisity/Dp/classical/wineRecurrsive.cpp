/*
wineRecurrsive.cpp
17 November 2024
Sun 12:19

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int dp[900][900];
int recur(int i, int j, vector<int> &p)
{
    if (i == j)
    {
        return n * p[i];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int years = n - (j - i);
    return dp[i][j] = max(recur(i + 1, j, p) + (p[i] * years), recur(i, j - 1, p) + (p[j] * years));
}
void solve()
{

    cin >> n;
    vector<int> p(n);

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout << recur(0, n - 1, p);
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