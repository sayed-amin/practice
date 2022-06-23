//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ans[0] = a[0] & a[1];
    ans[n - 1] = a[n - 1] & a[n - 2];
    for (int i = 1; i <= n - 2; i++)
    {
        ans[i] = max(a[i] & a[i - 1], a[i] & a[i + 1]);
    }
    for (auto ele : ans)
        cout << ele << " ";
    cout << endl;
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