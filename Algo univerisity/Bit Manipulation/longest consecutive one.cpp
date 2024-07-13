/*
longest consecutive one.cpp
23 June 2024
Sun 12:06

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {

        if (n & (1 << i))
        {

            count++;

            ans = max(ans, count);
        }
        else
        {

            count = 0;
        }
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}