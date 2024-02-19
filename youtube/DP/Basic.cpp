/*
Basic.cpp
19 February 2023
Sun 10:30
Dp top down and bottom up apporach
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
int dp[N];
int fib(int n)
{
    //  base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fib(n - 1) + fib(n - 2);
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << fib(n);
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