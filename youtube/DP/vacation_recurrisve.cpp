#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;

int solveRecursive(int i, int task, vector<vector<int>> &dp, vector<vector<int>> &data)
{
    if (i == 0)
    {
        return data[i][task];
    }

    if (dp[i][task] != -1)
    {
        return dp[i][task];
    }

    int result;
    if (task == 1)
    {
        result = data[i][1] + max(solveRecursive(i - 1, 2, dp, data), solveRecursive(i - 1, 3, dp, data));
    }
    else if (task == 2)
    {
        result = data[i][2] + max(solveRecursive(i - 1, 1, dp, data), solveRecursive(i - 1, 3, dp, data));
    }
    else
    {
        result = data[i][3] + max(solveRecursive(i - 1, 1, dp, data), solveRecursive(i - 1, 2, dp, data));
    }

    dp[i][task] = result;
    return result;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> data(n, vector<int>(4));
    vector<vector<int>> dp(n, vector<int>(4, -1));

    for (int i = 0; i < n; i++)
    {
        cin >> data[i][1] >> data[i][2] >> data[i][3];
    }

    int result = max({solveRecursive(n - 1, 1, dp, data), solveRecursive(n - 1, 2, dp, data), solveRecursive(n - 1, 3, dp, data)});
    cout << result << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
