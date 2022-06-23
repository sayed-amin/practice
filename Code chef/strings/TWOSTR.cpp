// strings
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string a, b;
    cin >> a >> b;
    int flag = 1;
    for (int i = 0; i <= a.size(); i++)
    {
        if (a[i] == b[i] || a[i] == '?' || b[i] == '?')
        {
            continue;
        }
        flag = 0;
        break;
    }
    if (flag)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
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