#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

int heightCombination(int idx, int h, vector<int> &heights, vector<vector<int>> &dp)
{
    if (h < 0)
        return 0; // Impossible to achieve negative height
    if (h == 0)
        return 1; // Exactly achieved height
    if (idx < 0)
        return 0; // No more blocks to consider
    if (dp[idx][h] != -1)
        return dp[idx][h]; // Return memoized result

    // Exclude current block
    int ans = heightCombination(idx - 1, h, heights, dp);

    // Include current block
    ans = (ans + heightCombination(idx, h - heights[idx], heights, dp)) % MOD;

    return dp[idx][h] = ans; // Memoize the result
}

void solve()
{
    int n, h;
    cin >> n >> h;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    vector<vector<int>> dp(n, vector<int>(h + 1, -1));
    cout << heightCombination(n - 1, h, heights, dp) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}
