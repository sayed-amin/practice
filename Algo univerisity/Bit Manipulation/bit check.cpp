/*
bit check.cpp
23 June 2024
Sun 11:53

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, k;
    cin >> n >> k;
    if ((n & (1 << k)))
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
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