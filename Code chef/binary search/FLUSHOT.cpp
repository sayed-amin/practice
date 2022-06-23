//
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check(vector<double> &pos, int n, double t, double mid)
{
    double currpos = pos[n - 1] + mid;
    for (int i = n - 2; i >= 0; i--)
    {
        currpos -= t;
        if (currpos > pos[i] + mid)
        {
            currpos = pos[i] + mid;
        }
        else if (currpos < pos[i] - mid)
        {
            return false;
        }
    }
    if (currpos >= 0.0)
        return true;
    return false;
}
void solve()
{
    int n;
    cin >> n;
    double t;
    cin >> t;
    vector<double> a(n, 0.0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    double low = 0.0, ans = 0.0, high = 10000000000.0;
    while ((high - low) > 0.00005)
    {
        double mid = (low + high) / 2.0;
        if (check(a, n, t, mid))
        {
            ans = mid * 1.0;
            high = mid;
        }
        else
            low = mid;
    }
    cout << fixed << setprecision(4);
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}