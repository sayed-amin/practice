//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    set<int> s;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s.insert(a);
    }
    int ans = -1;
    int j = 0;
    int max = *(--s.end());
    for (int i = 0; i <= max + 1; i++)
    {
        if (k == 0 and s.find(j) == s.end())
        {
            ans = j;
            break;
        }
        if (k > 0 and s.find(j) == s.end())
        {
            k--;
        }
        j++;
    }
    if (k and ans != -1)
        cout << ans + k + 1 << endl;
    else if (k and ans == -1)
        cout << j + k << endl;
    else if (ans == -1)
        cout << j << endl;
    else
        cout << ans << endl;
}
int32_t main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}