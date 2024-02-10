/*
pair.cpp
28 January 2023
Sat 06:33
pairs in stl
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    pair<int, string> p;
    p = make_pair(2, "hello");
    // another way to declare pair
    p = {2, "hello"};
    pair<int, string> &a = p;
    a.first = 1;
    cout << p.first << " " << p.second << endl;

    pair<int, int> p_arry[3];
    p_arry[0] = make_pair(0, 1);
    p_arry[1] = {1, 2};
    p_arry[2] = {2, 3};
    sort()
    for (int i = 0; i < 3; i++)
        cout << p_arry[i].first << " " << p_arry[i].second << endl;
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