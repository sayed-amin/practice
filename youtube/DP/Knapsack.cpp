/*
Knapsack.cpp
28 June 2022
Tue 13:02
https://atcoder.jp/contests/dp/tasks/dp_d
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int wt[105], value[105];
int dp[105][100005];
int func(int idx, int weight_left)
{
    if (weight_left == 0)
        return 0;
    if (idx < 0)
        return 0;
    if (dp[idx][weight_left] != -1)
        return dp[idx][weight_left];
    int ans = func(idx - 1, weight_left);
    if (weight_left - wt[idx] >= 0)
        ans = max(ans, func(idx - 1, weight_left - wt[idx]) + value[idx]);
    return dp[idx][weight_left] = ans;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
        cin >> wt[i] >> value[i];
    cout << func(n - 1, w);
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