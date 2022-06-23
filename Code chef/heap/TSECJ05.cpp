//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int k, n;
    cin >> k >> n;
    multiset<int> s;
    if (k == 1)
    {
        int a;
        cin >> a;
        cout << a << " ";
        for (int i = 2; i <= n; i++)
        {
            int b;
            cin >> b;
            a = max(a, b);
            cout << a << " ";
        }
    }
    else
    {
        for (int i = 1; i < k; i++)
        {
            int a;
            cin >> a;
            s.insert(a);
            cout << -1 << " ";
        }

        int a;
        cin >> a;
        s.insert(a);
        cout << *s.begin() << " ";
        for (int i = k + 1; i <= n; i++)
        {
            int a;
            cin >> a;
            if (*s.begin() < a)
            {
                // cout << *s.begin() << endl;
                s.erase(*s.begin());
                s.insert(a);
                cout << *s.begin() << " ";
            }
            else
            {
                // cout << "alkdjd" << endl;
                cout << *s.begin() << " ";
            }
        }
    }
    cout << endl;
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