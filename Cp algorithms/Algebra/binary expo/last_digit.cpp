/*
last_digit.cpp
20 July 2022
Wed 07:14

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int a, b;
    cin >> a >> b;
    int res = binpow(a, b, 10);
    cout << res % 10 << endl;
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