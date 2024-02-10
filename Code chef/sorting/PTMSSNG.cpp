/*
PTMSSNG.cpp
31 March 2023
Fri 07:27

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int x = 0, y = 0;
    for (int i = 1; i <= 4 * n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        x ^= a;
        y ^= b;
    }
    cout << x << " " << y << endl;
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