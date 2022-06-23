//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        m[a]++;
    }
    int ans = n, count = 0;
    for (auto e : m)
    {
        ans = min(ans, n - e.second);
        count++;
    }
    if (count >= 2)
        ans = min(ans, n - 2);
    cout << ans << endl;
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