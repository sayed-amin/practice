/*
contest.cpp
03 July 2022
Sun 08:14

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
string decodeMessage(string s, string message)
{
    string ans;
    vector<int> vis(26, 0);
    map<char, char> m;
    char temp = 'a';
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ' || vis[s[i] - 'a'])
            continue;
        vis[s[i] - 'a'] = 1;
        m[s[i]] = temp;
        temp++;
    }
    for (int i = 0; i < message.size(); i++)
    {
        if (message[i] == ' ')
            ans += " ";
        ans += m[message[i]];
    }
    // cout << ans << endl;
    return ans;
}
void solve()
{
    string s, m;
    s = "the quick brown fox jumps over the lazy dog";
    m = "vkbs bs t suepuv";
    cout << decodeMessage(s, m);
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