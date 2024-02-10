/*
comparator.cpp
31 January 2023
Tue 07:55
comparator
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool cmp1(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }
    // sort(v.begin(), v.end());
    // sort(v.begin(), v.end(), greater<pair<int, int>>());
    sort(v.begin(), v.end(), cmp1);
    for (auto &p : v)
    {
        cout << p.first << " " << p.second << endl;
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