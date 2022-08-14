/*
NOLOGIC.cpp
25 July 2022
Mon 08:06
basic programming
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    string s;
    cin >> s;
    vector<int> a(126, -1);
    for (int i = 0; i < s.size(); i++)
    {
        a['~' - s[i]]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (a[65 + i] != -1 and a[90 + i] != -1)
            cout << 'a' + i;
    }
    cout << endl;
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