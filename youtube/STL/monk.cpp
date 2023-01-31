/*
monk.cpp
29 January 2023
Sun 12:56
https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/?fbclid=IwAR2kDiVkEaxu9dkCTCUhzXLuIccNn0Gz3dSfkaSUjlDE6Nb9UHMzt8HNDo4
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, k;
    cin >> n >> k;
    int total_candies_eataen = 0;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    while (k > 0 and !s.empty())
    {
        auto it = s.end();
        it--;
        total_candies_eataen += *it;
        // cout << *it << endl;
        s.insert((*it) / 2);
        s.erase(it);
        k--;
    }
    cout << total_candies_eataen << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}