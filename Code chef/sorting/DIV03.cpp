/*
DIV03.cpp
31 March 2023
Fri 06:21
https://www.codechef.com/submit/DIV03?tab=statement
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
void solve()
{
    vector<pair<int, int>> v(10);
    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        v[i] = {i, x};
    }
    int k;
    cin >> k;

    // sort(v.begin(), v.end(), cmp);
    for (int i = 9; i >= 0; i--)
    {
        int temp = v[i].second;
        if (v[i].second >= k)
        {
            v[i].second = temp - k;
            k = temp - k;
        }
        else
        {
            v[i].second = 0;
            k = k - temp;
        }
        if (k == 0 or k < 0)
            break;
    }

    int ans = -1;
    for (int i = 9; i >= 0; i--)
    {
        if (v[i].second != 0)
        {
            ans = v[i].first;
            break;
        }
    }
    cout << ans + 1 << endl;
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