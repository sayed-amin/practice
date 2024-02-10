/*
Monk and his Friends.cpp
17 January 2024
Wed 20:10

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    set<int> s;
    while (n--)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    while (m--)
    {
        int x;
        cin >> x;
        auto it = s.find(x);
        if (it != s.end())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
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