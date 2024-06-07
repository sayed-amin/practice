/*
Unique_Window.cpp
01 June 2024
Sat 19:52

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int unique_count(unordered_map<int, int> &freq_map)
{
    int unique_element = 0;
    for (auto &it : freq_map)
    {
        if (it.second > 0)
        {
            unique_element++;
        }
    }
    return unique_element;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    unordered_map<int, int> freq_map;
    for (int i = 0; i < k; i++)
    {
        freq_map[a[i]]++;
    }
    result.push_back(unique_count(freq_map));
    for (int i = k; i < n; i++)
    {
        freq_map[a[i - k]]--;
        freq_map[a[i]]++;
        result.push_back(unique_count(freq_map));
    }

    for (auto &it : result)
    {
        cout << it << " ";
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