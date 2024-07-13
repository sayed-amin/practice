/*
Linear probbling .cpp
22 June 2024
Sat 21:35

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> ans(m, -1);
    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int key = a[i];
        int initialpos = key % m;
        int j = initialpos;
        while (ans[j] != -1 and ans[j] != key)
        {
            j = (j + 1) % m;
            if (j == initialpos)
            {
                break;
            }
        }
        if (ans[j] == -1 || ans[j] == key)
        {
            ans[j] = key;
        }
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}