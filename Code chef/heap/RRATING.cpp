/*
RRATING.cpp
04 July 2022
Mon 12:33

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    multiset<int> s;
    while (n--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int a;
            cin >> a;
            s.insert(a);
        }
        else
        {
            int siz = s.size();
            siz = siz / 3;
            //  cout << siz << endl;
            if (siz != 0)
            {
                auto pos = s.end();
                // pos--;

                while (siz != 0)
                {
                    --pos;
                    // cout << *pos << " ";
                    --siz;
                }
                //  cout << endl;
                cout << *pos << endl;
            }
            else
                cout << "No reviews yet" << endl;
        }
    }
    // for (auto i : s)
    //     cout << i << " ";
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