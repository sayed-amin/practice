// string
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string s;
    cin >> s;
    int flag = 1;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (flag)
        {
            if (s[i] == '1')
            {
                continue;
            }
            else
            {
                ans++;
                flag = 0;
            }
        }
        else
        {
            if (s[i] == '0')
            {
                continue;
            }
            else
            {
                ans++;
                flag = 1;
            }
        }
    }
    cout << ans << endl;
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