/*
order_set.cpp
17 July 2022
Sun 08:40

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    map<int, int> m;
    while (t--)
    {
        char c;
        cin >> c;
        if (c == 'I')
        {
            int x;
            cin >> x;
            m[x]++;
        }
        else if (c == 'D')
        {
            int x;
            cin >> x;
            if (m.find(x) != m.end())
            {
                m.erase(m.find(x));
            }
        }
        else if (c == 'K')
        {
            int x;
            cin >> x;
            if (m.size() >= x)
            {
                auto pos = m.begin();
                x--;
                while (x--)
                {
                    pos++;
                }
                cout << pos->first << endl;
            }
            else
                cout << "invalid" << endl;
        }
        else
        {
            int x;
            cin >> x;
            auto pos = m.begin();
            int count = 0;
            while (pos->first < x and pos != m.end())
            {
                count++;
                pos++;
            }
            cout << count << endl;
        }
    }
    return 0;
}