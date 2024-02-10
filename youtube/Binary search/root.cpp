/*
root.cpp
30 August 2022
Tue 05:45
nth root of the binary tree
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
double eps = 1e-6;
void solve()
{
    double x;
    cin >> x;
    double low = 1, high = x, mid;
    while (high - low > eps)
    {
        mid = (high + low) / 2;
        if (mid * mid < x)
        {
            low = mid;
        }
        else
            high = mid;
    }
    cout << setprecision(10) << low << " " << high << " " << floor(low) << endl;
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