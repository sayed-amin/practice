//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string s;
    cin >> s;
    int flag = 1;
    for (int i = 0; i + 3 <= s.size(); i++)
    {
        if (s.substr(i, 3) == "010" || s.substr(i, 3) == "101")
        {
            flag = 0;
            break;
        }
    }
    if (flag)
        cout << "Bad" << endl;
    else
        cout << "Good" << endl;
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