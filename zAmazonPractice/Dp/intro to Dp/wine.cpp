#include <bits/stdc++.h>
using namespace std;
int wineprofit(int i, int j, vector<vector<int>> &dp, vector<int> &profit)
{
    if (i == j)
    {
        return profit.size() * profit[i];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int y = profit.size() - (j - i);
    return dp[i][j] = max(wineprofit(i, j - 1, dp, profit) + profit[j] * y, wineprofit(i + 1, j, dp, profit) + profit[i] * y);
}
int main()
{
    int n;
    cin >> n;
    vector<int> wines(n);
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> wines[i];
    }
    cout << wineprofit(0, n - 1, dp, wines) << endl;
}