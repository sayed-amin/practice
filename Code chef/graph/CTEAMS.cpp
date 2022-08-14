/*
CTEAMS.cpp
24 July 2022
Sun 07:45
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pii pair<int, int>
void solve()
{
    int n;
    cin >> n;
    priority_queue<pii, vector<pii>, less<pii>> young;
    priority_queue<pii, vector<pii>, greater<pii>> old;
    int sy = 0, so = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, r;
        cin >> a >> r;
        if (old.empty() || a < old.top().first)
        {
            young.push(make_pair(a, r));
            sy += r;
        }
        else
        {
            old.push(make_pair(a, r));
            so += r;
        }

        if (young.size() > old.size() + 1)
        {
            pair<int, int> p = young.top();
            young.pop();
            old.push(p);
            sy -= p.second;
            so += p.second;
        }
        else if (young.size() < old.size())
        {
            pair<int, int> p = old.top();
            old.pop();
            young.push(p);
            so -= p.second;
            sy += p.second;
        }
        cout << abs(so - sy) << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}