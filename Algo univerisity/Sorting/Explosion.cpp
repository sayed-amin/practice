/*
Explosion.cpp
18 June 2024
Tue 23:19

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> explosive(n);
    for (int i = 0; i < n; i++)
    {
        cin >> explosive[i];
    }
    sort(explosive.begin(), explosive.end());
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int t = 1;

        int temp_ans = 1;
        for (int j = i + 1; j < n; j++)
        {

            if (explosive[j] - explosive[j - 1] <= t)
            {
                t++;
                temp_ans++;
            }
            else
            {
                break;
            }
        }
        t = 1;
        int j = i - 1;
        // going left
        while (j >= 0)
        {
            if (abs(explosive[j + 1] - explosive[j]) <= t)
            {
                t++;
                temp_ans++;
            }
            else
            {
                break;
            }
            j--;
        }
        ans = max(ans, temp_ans);
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}