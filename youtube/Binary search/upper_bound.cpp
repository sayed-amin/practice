/*
upper_bound.cpp
04 May 2024
Sat 17:12

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> vec(n);
    int position;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++)
    {
        cout << i << "value " << vec[i] << endl;
    }
    cout << *upper_bound(vec.begin(), vec.end(), 9);
    // int low = 0, high = n - 1;
    // // while (low + 1 < high)
    // // {
    // //     int mid = (high + low) / 2;
    // //     if (vec[mid] > 0)
    // //     {
    // //         high = mid;
    // //     }
    // //     else
    // //     {
    // //         low = mid;
    // //     }
    // // }
    // // cout << high << endl;
    // // cout << low << endl;
    // // cout << "another variant of binary search " << endl;
    // while (low + 1 < high)
    // {
    //     int mid = (high + low) / 2;
    //     if (vec[mid] >= target)
    //     {
    //         high = mid;
    //     }
    //     else
    //     {
    //         low = mid;
    //     }
    // }
    // cout << high << " " << vec[high] << endl;
    // cout << low << vec[low] << endl;
    // cout << "another variant of binary search " << endl;

    // while (low + 1 > high)
    // {
    //     int mid = (high + low) / 2;
    //     if (vec[mid] >= target)
    //     {
    //         high = mid;
    //     }
    //     else
    //     {
    //         low = mid + 1;
    //     }
    // }
    // cout << high << " " << vec[high] << endl;
    // cout << low << " " << vec[low] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    //  cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}