// map stl
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    multiset<int> s;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        s.insert(num);
    }
    int i = 1;
    while (!s.empty())
    {
        auto pos = s.end();
        pos--;
        int last = *pos;
        ans.push_back(*pos);
        s.erase(pos);
        if ((last / 2) != 0)
            s.insert(last / 2);
        i++;
    }
    while (m--)
    {
        int t;
        cin >> t;
        cout << ans[t - 1] << endl;
    }
    // for (auto ele : ans)
    //     cout << ele << " ";
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