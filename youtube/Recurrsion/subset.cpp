/*
subset.cpp
03 February 2023
Fri 23:20
https://leetcode.com/problems/subsets/description/
using recurrion
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// sub(int a[],int pos)
vector<vector<int>> subsets;
void sub(vector<int> &nums, vector<int> &v, int pos)
{
    if (pos == v.size())
        return;
    // ith element is not in the subset
    sub(nums, v, pos + 1);

    // ith element in the subset
    v.push_back(nums[pos]);
    sub(nums, v, pos);
    v.pop_back();
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