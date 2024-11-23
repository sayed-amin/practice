/*
coin_change_1.cpp
19 February 2023
Sun 11:57
https://leetcode.com/problems/coin-change/description/
// commit signing testing
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
class Solution
{
public:
    int dp[10010];
    int func(int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 0;
        if (dp[amount] != -1)
            return dp[amount];
        int ans = 1e9;
        for (auto coin : coins)
        {
            if (amount - coin >= 0)
                ans = min(ans + 0ll, func(amount - coin, coins) + 1ll);
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        memset(dp, -1, sizeof(dp));
        int ans = func(amount, coins);
        if (ans == 1e9)
            return -1;
        return ans;
    }
};
void solve()
{
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}