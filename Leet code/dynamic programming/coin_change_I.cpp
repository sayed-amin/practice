/*
coin_change_I.cpp
28 June 2022
Tue 05:19
https://leetcode.com/problems/coin-change/
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int func(int amount, vector<int> &coins)
{
    if (amount == 0)
        return 0;
    int ans = 1e16;
    for (auto coin : coins)
    {
        if (amount - coin >= 0)
            ans = min(ans, func(amount - coin, coins) + 1);
    }
}
int coinChange(vector<int> &coins, int amount)
{
    int ans = func(amount, coins);
    if (ans == 1e16)
        return -1;
    return ans;
}
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