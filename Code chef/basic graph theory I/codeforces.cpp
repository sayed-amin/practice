#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string s;
    cin >> s;
    if (s.length() == 1)
    {
        cout << "Bob"
             << " " << s[0] - 'A' - 31 << endl;
    }
    else if (!(s.length() & 1))
    {
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
            ans += s[i] - 'A' - 31;
        cout << "Alice"
             << " " << ans << endl;
    }
    else
    {
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
            ans += s[i] - 'A' - 31;
        int la = s[0] - 'A' - 31, ra = s[s.length() - 1] - 'A' - 31;
        if (ans - la >= ans - ra)
        {
            cout << "Alice"
                 << " " << ans - la - la << endl;
        }
        else if (ans - la < ans - ra)
        {
            cout << "Alice"
                 << " " << ans - ra - ra << endl;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}