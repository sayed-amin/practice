/*
pair2.cpp
06 July 2023
Thu 02:46

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    pair<int, int> p;
    p = {1, 2};
    // p = make_pair(1, 3);
    cout << p.second << endl;
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