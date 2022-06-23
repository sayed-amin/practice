/*
KPRIME.cpp
23 June 2022
Thu 12:58

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<bool> prime(100000 + 1, 1);
vector<int> c(100000 + 1, 0);
void solve()
{
    int a, b, k;
    cin >> a >> b >> k;
    int ans = 0;
    for (int i = a; i <= b; i++)
    {
        //  cout << c[i] << " ";
        if (c[i] == k)
            ans++;
    }

    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= 100000 + 1; i++)
    {
        if (prime[i])
        {
            c[i]++;
            for (int j = 2 * i; j <= 100000 + 1; j += i)
            {
                prime[j] = false;
                c[j]++;
            }
        }
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}