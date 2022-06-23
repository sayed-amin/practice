//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    for (int i = 0; i < n - 1; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = b[0] - a[1];
    for (auto i : b)
    {
        if (s.count(i - ans) == 0)
        {
            ans = b[0] - a[0];
            break;
        }
    }
    if (ans <= 0)
        ans = b[0] - a[0];
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