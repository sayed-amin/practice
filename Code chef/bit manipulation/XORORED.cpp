//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int ans1 = -1, ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans1 &= a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] ^ ans1;
        // cout << a[i] << " ";
        ans2 |= a[i];
    }
    cout << ans1 << " " << ans2 << endl;
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