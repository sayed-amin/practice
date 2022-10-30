/*
Luxury_Number.cpp
07 October 2022
Fri 20:29

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int l, r;
    cin >> l >> r;
    int ans = 0;
    // for (int i = l; i <= r; i++)
    // {
    //     int check = sqrt(i);
    //     if (i % check == 0)
    //         ans++;
    // }
    cout << sqrt(100000000000000000) << endl;
    for (int i = 1; i <= 100; i++)
        cout << sqrt(i) << "   " << i << endl;

    // cout << ans << endl;
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