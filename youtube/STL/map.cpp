/*
auto.cpp
28 January 2023
Sat 19:33
map stl
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    map<int, string> m;
    m[0] = "amin";
    m[1] = "sayed";
    map<int, string>::iterator it;
    it = m.find(1);
    cout << (*it).first << " " << it->second << endl;
    map<vector<pair<int, int>>, int> test;
    vector<pair<int, int>> p1 = {{1, 2}, {2, 3}};
    test[p1]++;
    for (auto &i : test)
    {
        for (int j = 0; j < i->first.size(); j++)
            cout << i->first << " ";
        cout << "second pair"
             << " " << i->second;
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