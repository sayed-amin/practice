/*
XORSUB.cpp
21 June 2022
Tue 22:45
bit manipulation
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int mx = -1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int subsets_count = 1 << n;
    for (int mask = 0; mask < subsets_count; mask++)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                ans ^= a[i];
        mx = max(mx, ans ^ k);
    }
    cout << mx << endl;
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