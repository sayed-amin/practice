/*
iteraor.cpp
28 January 2023
Sat 19:18
iterator in container
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<int>::iterator it;
    // it = v.begin();
    // it++;
    // cout << *(++it) << endl;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}