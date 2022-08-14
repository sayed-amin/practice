/*
parking_lot.cpp
20 July 2022
Wed 07:10

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    cout << (24 * binpow(4, n - 3) + (n - 3) * 36 * binpow(4, n - 4));
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