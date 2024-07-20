/*
Beautiful Snowflakes3 .cpp
30 June 2024
Sun 21:13

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int, int> snowfalkessizes;
    for (int i = 1; i < n; i++)
    {
        if (adj[i].size() > 1)
        {
            int sizeOf = 1;
            for (auto child : adj[i])
            {
                if (adj[child].size() > 1)
                {
                    continue;
                }
                sizeOf++;
            }
            snowfalkessizes[sizeOf]++;
        }
    }
    int beautifulSnowflakes = 0;
    for (const auto &entry : snowfalkessizes)
    {
        if (entry.second == 1)
        {
            beautifulSnowflakes++;
        }
    }
    cout << beautifulSnowflakes << endl;
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