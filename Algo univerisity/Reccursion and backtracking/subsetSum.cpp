/*
subsetSum.cpp
06 June 2024
Thu 20:28

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void findMinimalDifference(vector<int> &nums, int idx, int sum1, int total_sum, int &minDiff)
{
    if (idx == nums.size())
    {
        int sum2 = total_sum - sum1;

        minDiff = min(minDiff, abs(sum1 - sum2));
        return;
    }
    findMinimalDifference(nums, idx + 1, sum1 + nums[idx], total_sum, minDiff);
    findMinimalDifference(nums, idx + 1, sum1, total_sum, minDiff);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        total_sum += v[i];
    }
    
    int minDiff = INTMAX_MAX;
    findMinimalDifference(v, 0, 0, total_sum, minDiff);
    cout << minDiff << endl;
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