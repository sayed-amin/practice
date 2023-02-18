/*
super_pow.cpp
15 February 2023
Wed 06:27
https://leetcode.com/problems/super-pow/description/
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int binexp(int a, int b, int m)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans * 1LL * a) % m;
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return ans;
}
int superPow(int a, vector<int> &b)
{
    int bmod = 0;
    for (auto &val : b)
    {
        bmod = (bmod * 10 + val) % 1140;
    }
    return binexp(a, bmod, 1337);
}
void solve()
{
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