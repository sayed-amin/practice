/*
1binary_exp0_iterative.cpp
24 June 2022
Fri 13:53
iterative method
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int MOD;
int binRecurr(int a, int b)
{
    if (b == 0)
        return 1;
    int res = binRecurr(a, b / 2);
    if (b & 1)
        return a * res * res;
    else
        return res * res;
}
int binexpiterative(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }

    return ans;
}
// step multiply for value of b is value large
int stepmultiply(int a, int b)
{
    int ans = 0;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
}
void solve()
{
    int a;
    cin >> a;
    vector<int> b;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}