/*
ENGXOR.cpp
21 June 2022
Tue
bit manipulation
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n "
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> count(2, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        count[__builtin_popcount(a[i]) % 2]++;
    }
    while (q--)
    {
        int p;
        cin >> p;
        int z = __builtin_popcount(p);
        if (z & 1)
        {
            cout << count[1] << " " << count[0] << endl;
        }
        else
            cout << count[0] << " " << count[1] << endl;
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