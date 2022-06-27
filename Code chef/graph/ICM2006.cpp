/*
ICM2006.cpp
24 June 2022
Fri 04:57
dfa
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve()
{
    string s;
    cin >> s;
    int adj[6][2];
    adj[1][1] = 2;
    adj[1][0] = 1;
    adj[2][1] = 2;
    adj[2][0] = 3;
    adj[3][1] = 2;
    adj[3][0] = 4;
    adj[4][1] = 2;
    adj[4][0] = 5;
    adj[5][1] = 2;
    adj[5][0] = 1;
    int n = s.size();
    int curr = 1;
    for (int i = 0; i < n; i++)
    {
        curr = adj[curr][s[i] - '0'];
    }
    if (curr == 5)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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