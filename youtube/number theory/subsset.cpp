/*
subsset.cpp
19 November 2022
Sat 04:51
https://leetcode.com/problems/subsets/description/
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//subsets using bit masking 
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>>sub;
    int n = nums.size();
    int sub_count = 1 << n;
    for (int mask = 0; mask < sub_count; mask++)
    {
        vector<int>subset;
        for(int i=0;i<n;i++)
        {
            if(mask &( 1<<i))
            subset.push_back(nums[i]);
        }
        sub.push_back(subsets);
    }
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