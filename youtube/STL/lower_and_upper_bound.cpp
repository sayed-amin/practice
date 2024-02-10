/*
lower_and_upper_bound.cpp
31 January 2023
Tue 20:43

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int *ptr = lower_bound(a, a + n, 26);
    int *ptr2 = upper_bound(a, a + n, 89);
    cout << *ptr2 << endl;
    if (ptr == a + n)
        cout << "not found" << endl;
    else
        cout << *ptr << endl;
    // for set
    set<int> s;
    auto it = s.lower_bound(3);
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