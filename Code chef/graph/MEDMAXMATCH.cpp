/*
MEDMAXMATCH.cpp
25 July 2022
Mon 06:41
basic
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{

    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < n; j++)
        cin >> b[j];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int med = ceil(n / 2);
    sort(b.begin() + med, b.end(), greater<int>());
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i] + b[i];
    }
    sort(c.begin(), c.end());
    cout << c[med] << endl;
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