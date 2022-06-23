//
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first > p2.first;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;

    for (int i = 0; i < n - 1;)
    {
        if (a[i + 1] - a[i] <= k)
        {
            ans++;
            i += 2;
        }
        else
            i++;
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}