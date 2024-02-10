/*
The Wave.cpp
24 January 2024
Wed 14:20

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    while (q--)
    {
        int num;
        cin >> num;
        auto it = upper_bound(v.begin(), v.end(), num);
        int low = it - v.begin();
        if (low == n)
        {
            cout << "POSITIVE" << endl;
        }
        else if (low != 0 and v[low - 1] == num)
        {
            cout << "0" << endl;
        }
        else
        {
            if ((n - low) % 2 == 0)
                cout << "POSITIVE\n";
            else
                cout << "NEGATIVE\n";
        }
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