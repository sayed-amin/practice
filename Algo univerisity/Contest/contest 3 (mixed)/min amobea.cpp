/*
min amobea.cpp
22 June 2024
Sat 21:18

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int x;
    cin >> x;
    if (x < 0 || x > 1e9)
    {
        cout << -1 << endl;
        return;
    }
    int count = 0;
    while (x > 0)
    {
        count += (x & 1);
        x >>= 1;
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}