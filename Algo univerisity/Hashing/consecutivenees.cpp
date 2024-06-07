/*
consecutivenees.cpp
01 June 2024
Sat 23:13

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    unordered_set<int> nums_set(nums.begin(), nums.end());
    int max_length = -1;
    for (auto &it : nums)
    {
        if (nums_set.find(it - 1) == nums_set.end())
        {
            int current_num = it;
            int current_lenght = 1;
            while (nums_set.find(current_num + 1) != nums_set.end())
            {
                current_num++;
                current_lenght++;
            }
            max_length = max(max_length, current_lenght);
        }
    }
    cout << max_length << endl;
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