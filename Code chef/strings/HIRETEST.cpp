//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    string ans = "";
    while (n--)
    {

        string candidate;
        cin >> candidate;
        int solved = 0, partial = 0;
        for (int i = 0; i < m; i++)
        {
            if (candidate[i] == 'F')
                solved++;
            if (candidate[i] == 'P')
                partial++;
        }
        if (solved >= x || (x - 1 == solved and partial >= y))
            ans.push_back('1');
        else
            ans.push_back('0');
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