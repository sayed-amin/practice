/*
GCDQ.cpp
23 June 2022
Thu 08:55

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> pre(n), suff(n);
    pre[0] = a[0];
    suff[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
    {
        pre[i] = gcd(a[i], pre[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suff[i] = gcd(a[i], suff[i + 1]);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l != 0 and r != n - 1)
            cout << gcd(pre[l - 1], suff[r + 1]) << endl;
        else if (l == 0)
            cout << suff[r + 1] << endl;

        else
            cout << pre[l - 1] << endl;
    }
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