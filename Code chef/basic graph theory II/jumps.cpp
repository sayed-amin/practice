#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> g(10);
    for (int i = 0; i < n; i++)
    {
        g[s[i] - '0'].push_back(i);
    }
    vector<int> vis(n, 0), dist(n, 0);
    queue<int> q;
    q.push(0);
    vis[0] = 1;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        if (temp == n - 1)
            break;
        int value = s[temp] - '0';
        int size = g[value].size();

        for (int j = 0; j < size; j++)
        {

            int nextindx = g[value][j];
            if (vis[nextindx] == 0)
            {
                vis[nextindx] = 1;
                q.push(nextindx);
                dist[nextindx] = dist[temp] + 1;
            }
        }
        g[value].clear();
        if (temp - 1 >= 0 and temp - 1 < n)
        {
            if (vis[temp - 1] == 0)
            {
                vis[temp - 1] = 1;
                q.push(temp - 1);
                dist[temp - 1] = dist[temp] + 1;
            }
        }
        if (temp + 1 >= 0 and temp + 1 < n)
        {
            if (vis[temp + 1] == 0)
            {
                vis[temp + 1] = 1;
                q.push(temp + 1);
                dist[temp + 1] = dist[temp] + 1;
            }
        }
    }
    cout << dist[n - 1] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}