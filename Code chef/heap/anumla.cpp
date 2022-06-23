//
#include <bits/stdc++.h>
using namespace std;
//#define int long long

void solve()
{
    int n;
    cin >> n;
    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    vector<int> a(n + 1);
    vector<int> prefix_sum(n + 1);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
        ans.push_back(prefix_sum[i]);
        for (int j = 1; j < i; j++)
        {
            ans.push_back(prefix_sum[i] - prefix_sum[j]);
        }
    }
    sort(ans.begin(), ans.end(), greater<int>());

    cout << ans[k1 - 1] << " " << ans[k2 - 1] << " " << ans[k3 - 1] << endl;
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