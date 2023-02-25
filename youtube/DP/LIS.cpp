/*
LIS.cpp
19 February 2023
Sun 11:38
LIS
https://leetcode.com/problems/longest-increasing-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e4 + 10;
vector<int> a(N);
int dp[N];
int LIS(int i)
{
    if (dp[i] != -1)
        return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++)
    {
        if (a[i] > a[j])
            ans = max(ans, LIS(j) + 1);
    }
    return dp[i] = ans;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, LIS(i));
    }
    cout << ans << endl;
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