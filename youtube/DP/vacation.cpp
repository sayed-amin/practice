/*
vacation.cpp
20 January 2024
Sat 23:36

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
int dp[N][4];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {

        int a, b, c;
        cin >> a >> b >> c;
        if (i == 1)
        {
            dp[1][1] = a;
            dp[1][2] = b;
            dp[1][3] = c;
        }
        else
        {
            dp[i][1] = a + max(dp[i - 1][2], dp[i - 1][3]);
            dp[i][2] = b + max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][3] = c + max(dp[i - 1][2], dp[i - 1][1]);
        }
    }
    cout << max({dp[n][1], dp[n][2], dp[n][3]}) << endl;
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