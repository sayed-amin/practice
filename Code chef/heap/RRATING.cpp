//

#include <bits/stdc++.h>
using namespace std;
const int max_char = 26;
struct KEY
{
    /* data */
    int frequency;
    char ch;
    bool operator<(const KEY &k) const
    {
        return frequency < k.frequency;
    }
};

class Solution
{
public:
    string reorganizeString(string s)
    {
        int n = s.size();
        vector<int> count(max_char, 0);
        for (int i = 0; i < n; i++)
        {
            count[s[i] - 'a']++;
        }
        priority_queue<KEY> p;
        for (char i = 'a'; i <= 'z'; i++)
        {
            int val = i - 'a';
            if (count[val])
            {
                p.push({count[val], i});
            }
        }
        s = "";
        KEY prev({-1, '#'});

        while (!p.empty())
        {
            KEY k = p.top();
            p.pop();
            s = s + k.ch;
            if (prev.frequency > 0)
                p.push(prev);
            (k.frequency)--;

            prev = k;
        }
        if (n != s.length())
            return "";
        return s;
    }
};
void solve()
{
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}