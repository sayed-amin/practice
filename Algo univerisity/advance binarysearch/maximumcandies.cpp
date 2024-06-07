/*
maximumcandies.cpp
12 May 2024
Sun 19:59

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int predicate(int mid, int n)
{
    int max_cost = mid * (mid + 1) / 2;
    if (max_cost <= n)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void solve()
{
    int n;
    cin >> n;
    int low = -1, high = 1e18;
    while (low + 1 < high)
    {
        int mid = low + (high - low) / 2;
        if (predicate(mid, n) == 0)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    cout << low << endl;
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