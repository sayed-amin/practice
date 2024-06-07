/*
frequency_sort.cpp
01 June 2024
Sat 20:19

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}
void solve()
{
    int n;
    cin >> n;

    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        m[temp]++;
    }
    vector<pair<int, int>> frequency_vector(m.begin(), m.end());
    sort(frequency_vector.begin(), frequency_vector.end(), cmp);
    for (auto &it : frequency_vector)
    {
        for (int i = 0; i < it.second; i++)
        {
            cout << it.first << " ";
        }
    }
    cout << endl;
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