/*
three sum.cpp
15 June 2024
Sat 11:55

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

// solution 1
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                break; // Since array is sorted, no need to check further if the current number is > 0
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // Skip duplicate elements for the first element of the triplet

            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0)
                {
                    r--;
                }
                else if (sum < 0)
                {
                    l++;
                }
                else
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1])
                    { // Skip duplicate elements for the second element of the triplet
                        l++;
                    }
                }
            }
        }
        return res;
    }
};
// solution 2:
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        for (int i = 0; i < n - 2; i++)
        {
            int low = i + 1, high = n - 1;
            int firstTriplet = nums[i];
            while (low < high)
            {
                int sum = firstTriplet + nums[low] + nums[high];
                if (sum == 0)
                {
                    s.insert({nums[i], nums[low], nums[high]});
                    low++, high--;
                }
                else if (sum < 0)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }

        for (auto &i : s)
        {
            ans.push_back(i);
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