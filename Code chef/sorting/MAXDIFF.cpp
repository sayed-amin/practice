//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    int sum2 = 0;
    for (int i = 1; i <= k; i++)
    {
        sum2 += a[i];
    }
    int sum1 = sum - sum2;
    int sum3 = 0;
    int i = n;
    while (k--)
    {
        sum3 += a[n];
        n--;
    }
    int sum4 = abs(sum - sum3);
    cout << max(abs(sum1 - sum2), abs(sum4 - sum3)) << endl;
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