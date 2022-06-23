//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> a(101, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    int count = 0;
    int ans = 0;
    for (int i = 0; i < 101; i++)
    {
        if (a[i] == 0)
            continue;
        count += a[i];
        if (count > n - count)
            ans += a[i];
    }
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