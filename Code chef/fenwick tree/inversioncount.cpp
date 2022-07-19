/*
inversioncount.cpp
19 July 2022
Tue 06:11

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e7 + 10;
vector<int> bit(N);

void update(int i, int x)
{
    for (; i < N; i += (i & -i))
        bit[i] += x;
}

int sum(int i)
{
    int ans = 0;
    for (; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

void solve()
{
    bit.assign(N, 0);
    int n;
    cin >> n;
    long long a[n + 10];
    map<long long, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        mp[a[i]];
    }

    // compression of numbers for the case where a[i] > 10 ^ 6
    int ptr = 1;
    for (auto &pr : mp)
    {
        pr.second = ptr++;
    }

    for (int i = 1; i <= n; ++i)
    {
        a[i] = mp[a[i]];
    }

    // Finding Inversion count

    int inversion_ct = 0;
    for (int i = 1; i <= n; ++i)
    {
        inversion_ct += (sum(N - 5) - sum(a[i]));
        update(a[i], 1);
    }

    cout << inversion_ct << endl;
    int x;
    // cin >> x;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    int bankspakce;
    //   cin >> bankspakce;
    while (t--)
    {

        solve();
    }
    return 0;
}