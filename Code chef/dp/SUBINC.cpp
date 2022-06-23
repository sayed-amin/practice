/*
SUBINC.cpp
23 June 2022
Thu 11:29
dp
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<bool> prime(100000 + 1, 1);
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> dp(n, 1);

    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
            dp[i] += dp[i - 1];
        ans += dp[i];
    }

    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= 100000 + 1; i++)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j <= 100000 + 1; j += i)
                prime[j] = false;
        }
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}