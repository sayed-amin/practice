/*
Chopsticks.cpp
18 March 2023
Sat 06:51
https://www.codechef.com/submit/TACHSTCK?tab=statement
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> lenght(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lenght[i];
    }
    sort(lenght.begin(), lenght.end());
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (lenght[i] - lenght[i - 1] <= d)
        {
            ans++;
            i++;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}