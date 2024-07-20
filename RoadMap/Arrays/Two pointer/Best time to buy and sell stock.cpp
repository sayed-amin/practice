/*
Best time to buy and sell stock.cpp
16 July 2024
Tue 07:39

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = INT_MIN;
        int low = 0, high = 1;
        while (high < prices.size())
        {
            if (prices[low] >= prices[high])
            {
                low = high;
            }
            else
            {
                ans = max(ans, prices[high] - prices[low]);
            }
            high++;
        }
        if (ans == INT_MIN)
        {
            return 0;
        }
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
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}