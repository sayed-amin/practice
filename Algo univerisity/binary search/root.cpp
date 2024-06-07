/*
root.cpp
05 May 2024
Sun 11:34

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
double predicate(double mid, double n)
{
    if (mid * mid < n)
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
    double n;
    cin >> n;
    double low = 0, high = n;
    double eps = 1e-7;
    while (low + eps < high)
    {
        double mid = (low + high) / 2.0;
        if (predicate(mid, n) == 0)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    cout << high << endl;
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