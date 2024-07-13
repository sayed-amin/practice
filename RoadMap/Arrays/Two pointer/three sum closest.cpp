/*
three sum closest.cpp
07 July 2024
Sun 08:58

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n; i++)
        {
            if (i > 0 and nums[i] == nums[i - 1])
            {
                continue;
            }
            int low = i + 1, high = n - 1;
            while (low < high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                if (abs(target - sum) < abs(target - closest))
                {
                    closest = sum;
                    low++;
                }
                else if (sum > target)
                {

                    high--;
                }
                else
                {
                    low++;
                }
            }
        }

        return closest;
    }
};

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n; i++)
        {
            if (i > 0 and nums[i] == nums[i - 1])
            {
                continue;
            }
            int low = i + 1, high = n - 1;
            while (low < high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                if (abs(target - sum) < abs(target - closest))
                {
                    closest = sum;
                }
                else if (sum > target)
                {

                    high--;
                }
                else if (sum < target)
                {
                    low++;
                }
                else
                {
                    return sum;
                }
            }
        }

        return closest;
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