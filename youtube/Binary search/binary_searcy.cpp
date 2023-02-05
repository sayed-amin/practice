/*
binary_searcy.cpp
24 August 2022
Wed 06:07
basic code of binary search
line to the question:
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int to_find;
    cin >> to_find;
    int low = 0, high = n - 1;
    int mid;
    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (v[mid] < to_find)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    if (v[low] == to_find)
        cout << low << endl;
    else if (v[high] == to_find)
        cout << high << endl;
    else
        cout << "not found" << endl;
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