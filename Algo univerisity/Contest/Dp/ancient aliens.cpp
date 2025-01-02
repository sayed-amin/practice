#include <bits/stdc++.h>
using namespace std;

string findSCS(string s1, string s2, int n, int m)
{

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Step 2: Construct SCS
    string scs = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            scs += s1[i - 1];
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            scs += s1[i - 1];
            i--;
        }
        else
        {
            scs += s2[j - 1];
            j--;
        }
    }
    while (i > 0)
    {
        i--;
    }
    while (j > 0)
    {
        scs += s2[j - 1];
        j--;
    }
    reverse(scs.begin(), scs.end());
    return scs;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    cout << findSCS(s1, s2, n, m) << endl;
    return 0;
}
