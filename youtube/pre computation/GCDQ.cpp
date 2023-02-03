/*
GCDQ.cpp
20 August 2022
Sat 17:48
https://www.codechef.com/problems/GCDQ?tab=statement
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int suff[n], pre[n];
    pre[0] = a[0];
    suff[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
    {
        pre[i] = gcd(pre[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suff[i] = gcd(suff[i + 1], a[i]);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l == 0 and r != n - 1)
            cout << suff[r + 1] << endl;
        else if (l != 0 and r == n - 1)
            cout << pre[l - 1] << endl;
        else
            cout << gcd(pre[l - 1], suff[r + 1]) << endl;
    }
}
void solve2()
{
    int n, q;
    cin >> n >> q;
    int a[n + 10];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int suff[n + 10], pre[n + 10];
    pre[0] = 0;
    suff[n + 1] = 0;
    for (int i = 1; i < n; i++)
    {
        pre[i] = gcd(pre[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        suff[i] = gcd(suff[i + 1], a[i]);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << gcd(pre[l - 1], suff[r + 1]) << endl;
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
        solve2();
    }
    return 0;
}