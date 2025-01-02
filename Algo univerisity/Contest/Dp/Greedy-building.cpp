#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

void solve()
{
    int n, h;
    cin >> n >> h;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    vector<int> dp(h + 1, INF); // Initialize DP array with a large number
    dp[0] = 0;                  // Base case: 0 height requires 0 blocks

    for (int i = 0; i < n; i++)
    { // Iterate over all block types
        for (int j = heights[i]; j <= h; j++)
        { // Update DP array for each height
            dp[j] = min(dp[j], dp[j - heights[i]] + 1);
        }
    }

    // Output the result
    if (dp[h] == INF)
    {
        cout << -1 << endl; // Impossible to construct height H
    }
    else
    {
        cout << dp[h] << endl; // Minimum blocks required
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
