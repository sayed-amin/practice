// bit manipulation
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ans ^= s[i];
    }
    if (ans)
        cout << (char)ans << endl;
    else
        cout << -1 << endl;
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