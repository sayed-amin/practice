// string map

#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string s;
    cin >> s;
    vector<bool> m(27, false);
    for (int i = 0; i < s.size(); i++)
        m[s[i] - 'a'] = true;

    int n;
    cin >> n;
    while (n--)
    {
        string work;
        cin >> work;
        int flag = 1;
        for (int i = 1; i < work.size(); i++)
        {
            if (!m[work[i] - 'a'])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}