/*
jump possibility.cpp
23 November 2024
Sat 16:06
// include dont include
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// dp [i][j] means first's i value of the array can we reach J or not ?
bool findNextAns(int n, int target, vector<int> &jumps, vector<vector<int>> &dp)
{

    if (target == 0)
    {
        return true;
    }
    if (target < 0 || n < 0)
    {
        return false;
    }
    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }
    // include
    bool ans = findNextAns(n - 1, target - jumps[n], jumps, dp);

    // Dont include
    ans |= findNextAns(n - 1, target, jumps, dp);

    return dp[n][target] = ans;
}
void solve()
{
    int n;
    cin >> n;
    int s;
    cin >> s;

    vector<vector<int>> dp(n, vector<int>(s + 1, -1));
    vector<int> jumps(n);
    for (int i = 0; i < n; i++)
    {
        cin >> jumps[i];
    }
    int ans = findNextAns(n - 1, s, jumps, dp);
    if (ans == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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