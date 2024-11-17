/*
saint arrangment.cpp
31 July 2024
Wed 23:34

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    queue<int> q;
    unordered_map<int, int> dist;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        dist[x] = 0;
        q.push(x);
    }
    int val = 0;
    vector<int> ans;
    while (ans.size() < m)
    {
        int v = q.front();
        q.pop();
        if (dist.count(v - 1) == 0)
        {
            dist[v - 1] = dist[v] + 1;
            q.push(v - 1);
            ans.push_back(v - 1);
            val += dist[v - 1];
        }
        if (ans.size() == m)
        {
            break;
        }
        if (dist.count(v + 1) == 0)
        {
            dist[v + 1] = dist[v] + 1;
            q.push(v + 1);
            ans.push_back(v + 1);
            val += dist[v + 1];
        }
    }
    cout << val << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    // s cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}