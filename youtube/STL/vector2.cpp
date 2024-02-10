/*
vector.cpp
28 January 2023
Sat 06:44
vector in stl
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void print_vect(vector<int> &v)
{
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void solve()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    cout << v[2] << endl;
    print_vect(v);
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