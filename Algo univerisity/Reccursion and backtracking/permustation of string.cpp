/*
permustation of string.cpp
06 June 2024
Thu 21:53

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void PermutationOfString(string &s, int idx, string &temp)
{

    if (idx == s.size() - 1)
    {
        cout << temp << endl;
        return;
    }
    if (idx >= s.size())
    {
        return;
    }

    temp += s[idx];
    PermutationOfString(s, idx + 1, temp);
    temp.pop_back();
    PermutationOfString(s, idx, temp);
    temp += s[idx];
}
void solve()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
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