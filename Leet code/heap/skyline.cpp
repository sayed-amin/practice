// very good problem
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair<int, pair<int, bool>> p1, pair<int, pair<int, bool>> p2)
{
    if ((p1.first == p2.first) and (p1.second.first == p2.second.first) and (p1.second.second != p2.second.second))
    {
        return (p1.second.second == 1) ? 0 : 1;
    }
    else if (p1.first == p2.first and p1.second.second == 1 and p2.second.second == 1)
    {
        return p1.second.first > p2.second.first;
    }
    else if (p1.first == p2.first and p1.second.second == 0 and p2.second.second == 0)
    {
        return p1.second.first < p2.second.first;
    }
    else if (p1.first == p2.first)
    {
        return p1.second.first > p2.second.first;
    }
    return p1.first < p2.first;
}
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<pair<int, pair<int, bool>>> p;
        for (int i = 0; i < buildings.size(); i++)
        {

            p.push_back({buildings[i][0], {buildings[i][2], 1}});
            p.push_back({buildings[i][1], {buildings[i][2], 0}});
        }
        sort(p.begin(), p.end(), cmp);
        vector<vector<int>> ans;
        int height = -1;
        multiset<int> s;
        s.insert(0);

        for (auto i : p)
            cout << i.first << " " << i.second.first << " " << i.second.second << endl;
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i].second.second == 1)
            {
                s.insert(p[i].second.first);
                auto pos = s.end();
                pos--;

                if (height != *pos)
                {
                    {
                        ans.push_back({p[i].first, p[i].second.first});
                        height = *pos;
                    }
                }
            }
            else if (p[i].second.second == 0)
            {
                auto temp = s.find(p[i].second.first);
                s.erase(temp);
                temp = s.end();
                temp--;
                if (height != *temp)
                {
                    ans.push_back({p[i].first, *temp});
                    height = *temp;
                }
            }
        }
        return ans;
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