#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int r, a, b;
    cin >> r >> a >> b;
    double ans = 0;
    bool flag = 1;
    vector<int> radius;
    radius.push_back(r * r);
    while (r)
    {
        if (flag)
        {
            r = r * a;
            radius.push_back(r * r);
            flag = 0;
        }
        else
        {
            r /= b;
            radius.push_back(r * r);
            flag = 1;
        }
    }
    for (auto i = radius.begin(); i != radius.end(); i++)
    {
        ans += *i;
    }
    cout << fixed << setprecision(6);
    ans = ans * 3.14159265;
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