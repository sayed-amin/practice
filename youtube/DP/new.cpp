/*
new.cpp
11 October 2023
Wed 16:13

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int LIS(int i, vector<int> &nums)
{
    if (i < 0)
        return 0;
    int ans = 1e9;
    for (int j = 0; j < i; j++)
    {
        if (nums[j] < nums[i])
        {
            ans = min(ans, LIS(j, nums));
        }
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, greater());
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //   cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}