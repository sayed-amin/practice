//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    pair<int, int> ans = {1e11, 0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (k % a[i] == 0)
        {
            if (ans.first > (k / a[i]) - 1)
            {
                ans.first = (k / a[i]) - 1;
                ans.second = a[i];
            }
        }
    }
    if (ans.first == 1e11)
        cout << -1 << endl;
    else
        cout << ans.second << endl;
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