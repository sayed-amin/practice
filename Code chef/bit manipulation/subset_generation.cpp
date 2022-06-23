// subset generation using bit masking or manipulation
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> subsets;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int subsets_count = 1 << n;
    set<vector<int>> s;
    for (int mask = 0; mask < subsets_count; mask++)
    {
        vector<int> subset;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
            {
                subset.push_back(nums[i]);
            }
        auto pos = s.find(subset);
        if (pos != s.end())
        {
            continue;
            ;
        }
        s.insert(subset);
        subsets.push_back(subset);
    }
    return subsets;
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