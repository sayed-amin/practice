/*
trapping rain water.cpp
09 July 2024
Tue 07:20

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

// solution 1 with O(n) extra space
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> maxLeft(n);
        vector<int> maxRight(n);
        vector<int> minlr(n);
        int maxi = height[0];
        for (int i = 0; i < n; i++)
        {

            maxLeft[i] = maxi;
            maxi = max(maxi, height[i]);
        }
        maxi = height[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {

            maxRight[i] = maxi;
            maxi = max(maxi, height[i]);
        }
        for (int i = 0; i < n; i++)
        {
            minlr[i] = min(maxLeft[i], maxRight[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (minlr[i] - height[i] >= 0)
            {
                ans += minlr[i] - height[i];
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.empty())
        {
            return 0;
        }
        int ans = 0;
        int low = 0, high = height.size() - 1;
        int leftMax = height[0], rightMax = height[height.size() - 1];
        while (low < high)
        {
            if (leftMax < rightMax)
            {
                low++;
                leftMax = max(leftMax, height[low]);
                ans += leftMax - height[low];
            }
            else
            {
                high--;
                rightMax = max(rightMax, height[high]);
                ans += leftMax - height[high];
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
    // cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}