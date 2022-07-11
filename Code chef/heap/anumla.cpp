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
    multiset<int> res;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
        a[i] += a[i - 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {

            if (res.size() < k3)
                res.insert(a[j] - a[i - 1]);
            else
            {
                auto p = res.begin();
                if ((a[j] - a[i - 1]) > (*p))
                {
                    res.erase(p);
                    res.insert(a[j] - a[i - 1]);
                }
            }
        }
    }
    for (auto x : res)
        ans.push_back(x);
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