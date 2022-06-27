/*
PPTEST.cpp
24 June 2022
Fri 05:31

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    int w;
    cin >> n >> w;
    vector<pair<int, pair<int, int>>> s;
    for (int i = 1; i <= n; i++)
    {
        int c, p, t;
        cin >> c >> p >> t;
        s.push_back({t, {c, 9}});
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