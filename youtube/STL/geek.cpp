/*
geek.cpp
04 February 2023
Sat 22:42

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int> countDistinct(int a[], int n, int k)
{
    // code here.
    map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < k; i++)
        m[a[i]]++;
    ans.push_back(m.size());
    int i, j;
    i = k;
    j = 0;
    while (i < n)
    {
        auto it = m.find(a[j]);
        if (m[a[j]] == 1)
            m.erase(it);
        else
            m[a[j]]--;
        m[a[i]]++;
        ans.push_back(m.size());
        i++, j++;
    }
    return ans;
}
void solve()
{
    int a[] = {4, 1, 1};
    vector<int> ans = countDistinct(a, 3, 2);
    for (auto i : ans)
        cout << i << endl;
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