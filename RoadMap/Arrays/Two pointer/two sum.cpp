/*
two sum.cpp
12 June 2024
Wed 23:26

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        multi_map<int, int> have_num;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            have_num.insert({nums[i], i});
        }
        have_num.find() for (int i = 0; i < nums.size(); i++)
        {
            int sum1 = nums[i];
            int sum2 = target - sum1;
            auto it = have_num.find(sum2);
            if (it != have_num.end())
            {
                ans.push_back(i);
                ans.push_back(it->second);
                break;
            }
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