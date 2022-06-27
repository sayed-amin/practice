/*
monk.cpp
25 June 2022
Sat 13:37
https://www.hackerearth.com/problem/algorithm/monk-and-divisor-conundrum-56e0eb99/
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
int hsh[N];
int mulitple_ct[N];
void solve()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        hsh[x]++;
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            mulitple_ct[i] += hsh[j];
        }
    }
    while (q--)
    {
        int p, r;
        cin >> p >> r;
        int l = lcm(p, r);
        int ans = mulitple_ct[p] + mulitple_ct[r];
        if (l < N)
            ans -= mulitple_ct[l];
        cout << ans << endl;
    }
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