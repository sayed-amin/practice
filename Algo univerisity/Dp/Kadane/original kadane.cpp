/*
original kadane.cpp
02 January 2025
Thu 20:51
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int kadaneTopdown(int i, vector<int> &dp, vector<int> &nums)
{
    if (i == 0)
    {
        return nums[i];
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    return dp[i] = max(kadaneTopdown(i - 1, dp, nums) + nums[i], nums[i]);
}
// Solve Function
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = INT_MIN;
    vector<int> dp(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        ans = max(kadaneTopdown(i, dp, a), ans);
    }
    cout << ans << endl;
    // Bottom-Up Approach
    // vector<int> dpBottomUp(n, 0);
    // dpBottomUp[0] = a[0];
    // for (int i = 1; i < n; i++)
    // {
    //     dpBottomUp[i] = max(dpBottomUp[i - 1] + a[i], a[i]);
    // }
    // int maxBottomUp = *max_element(dpBottomUp.begin(), dpBottomUp.end());
    // cout << maxBottomUp << endl;
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
