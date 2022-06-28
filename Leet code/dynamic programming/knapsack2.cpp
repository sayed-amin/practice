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
int func(int idx, int value_left)
{
    if (value_left == 0)
        return 0;
    if (idx < 0)
        return 1e15;
    if (dp[idx][value_left] != -1)
        return dp[idx][value_left];
    int ans = func(idx - 1, value_left);
    if (value_left - value[idx] >= 0)
        ans = min(ans, func(idx - 1, value_left - value[idx]) + wt[idx]);
    return dp[idx][value_left] = ans;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
        cin >> wt[i] >> value[i];
    for (int i = 1e5; i >= 0; i--)
    {
        if (func(n - 1, i) <= w)
        {
            cout << i << endl;
            break;
        }
    }
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