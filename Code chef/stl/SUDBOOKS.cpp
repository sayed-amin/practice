// stl

#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int q;
    cin >> q;
    stack<int> s;
    while (q--)
    {
        int type;
        cin >> type;

        if (type == -1)
        {
            if (s.empty())
                cout << "kuchbhi?" << endl;
            else
            {
                int t = s.top();
                s.pop();
                cout << t << endl;
            }
        }
        else
        {
            int n;
            cin >> n;
            s.push(n);
        }
    }
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