/*
test.cpp
05 August 2023
Sat 14:39

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int binexp(int a, int b)
{
    if (b == 0)
        return 1;
    res = binexp(a, b / 2);
    if (a & 1)
        return a * res * res;
    else
        return res * res;
}
int binite(int a, int b)
{
    int res = 1;
    while (b)
    {

        if (b & 1)
            ans = ans * a;
        a = a * a;
        b >> 1;
    }
}
void solve()
{
    cout << char('a' & '_');
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