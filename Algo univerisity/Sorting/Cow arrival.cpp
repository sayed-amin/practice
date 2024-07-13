/*
Cow arrival.cpp
09 June 2024
Sun 22:19

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> cows(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows.begin(), cows.end());
    int current_time = 0;
    for (int i = 0; i < n; i++)
    {
        int arrival_time = cows[i].first;
        int checkup_time = cows[i].second;
        if (current_time < arrival_time)
        {
            current_time = arrival_time;
        }
        current_time += checkup_time;
    }
    cout << current_time << endl;
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