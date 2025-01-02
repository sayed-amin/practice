#include <bits/stdc++.h>
using namespace std;

bool findTarget(int idx, int target, vector<int> &choclates, vector<vector<int>> &dp)
{
    if (idx < 0 || target < 0)
    {
        return false;
    }
    if (target == 0)
    {
        return true;
    }
    if (dp[idx][target] != -1)
    {
        return dp[idx][target];
    }
    int ans = findTarget(idx - 1, target, choclates, dp);
    ans |= findTarget(idx - 1, target - choclates[idx], choclates, dp);
    return dp[idx][target] = ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> choclates(n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> choclates[i];
            ans += choclates[i];
        }
        vector<vector<int>> dp(n, vector<int>(ans + 1, -1));
        if (ans & 1)
        {
            cout << "NO" << endl;
            continue;
        }
        ans = findTarget(n - 1, ans / 2, choclates, dp);
        if (ans == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}