/*
Frog1.cpp
24 February 2023
Fri 23:32
https://atcoder.jp/contests/dp/tasks/dp_a
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
int h[N];
int dp[N];
int k;
int func(int i)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int cost = __INT_MAX__;
    for (int j = 1; j <= k; j++)
        if ((i - j) >= 0)
            cost = min(cost, func(i - j) + abs(h[i] - h[i - j]));

    return dp[i] = cost;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cin >> k;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    cout << func(n - 1) << endl;
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