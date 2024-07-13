/*
easy counting.cpp
22 June 2024
Sat 21:08

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    string s;
    cin >> s;
    unordered_map<char, int> frequency;

    for (char c : s)
    {
        frequency[c]++;
    }

    int count = 0;

    for (auto &entry : frequency)
    {
        int freq = entry.second;
        count += freq * freq;
    }

    cout << count << endl;
    ;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    //   cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}