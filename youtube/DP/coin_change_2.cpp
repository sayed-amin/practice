/*
coin_change_I.cpp
28 June 2022
Tue 05:19
https://leetcode.com/problems/coin-change-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
class Solution
{
public:
    int dp[310][10010];
    int func(int idx, int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 1;
        if (idx < 0)
            return 0;
        int ways = 0;
        if (dp[idx][amount] != -1)
            return dp[idx][amount];
        for (int coin_amount = 0; coin_amount <= amount; coin_amount += coins[idx])
        {
            ways += func(idx - 1, amount - coin_amount, coins);
        }
        return dp[idx][amount] = ways;
    }
    int change(int amount, vector<int> &coins)
    {
        memset(dp, -1, sizeof(dp));
        int ans = func(coins.size() - 1, amount, coins);
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