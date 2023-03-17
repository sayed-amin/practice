/*
Partition_equal_sum.cpp
28 June 2022
Tue 19:57
https://leetcode.com/problems/partition-equal-subset-sum/
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool func(int index, int sum, vector<int> &nums)
{
    if (sum == 0)
        return 1;
    if (index < 0)
        return 0;

    bool ans = func(index - 1, sum, nums);
    if (sum - nums[index] >= 0)
        ans | = func(index - 1, sum - nums[index], nums);
    return ans;
}
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum += nums[i];
    return func(nums.size() - 1, sum / 2, nums);
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