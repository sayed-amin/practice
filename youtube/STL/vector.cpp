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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        // print_vect(v);
        v.push_back(x);
    }
    v.insert(v.begin(), 255);
    cout << v[0] << endl;
    print_vect(v);
    int A = 5;
    vector<vector<int>> ans(A, vector<int>(A, 0));
    vector<vector<int>> test(A, vector<int>(A, 0));
    vector<int> arr[A];
    vector<array<int, 5>> arr2;
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