/*
PTUPLES.cpp
25 June 2022
Sat 22:15
number theory
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
vector<int> ans(N, 0);
void solve()
{
    int l, r;
    cin >> l >> r;
    int count = 0;
    for (int i = l; i <= r; i++)
    {
        count += ans[i];
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i < N; i += 2)
    {

        for (int j = i; j < N; j += i)
            ans[j] += i;
    }

    while (t--)
    {
        solve();
    }
    return 0;
}