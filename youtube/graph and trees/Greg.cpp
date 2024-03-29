/*
Greg.cpp
02 July 2022
Sat 07:20

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 510;
const int INF = 1e9 + 10;
int dist[N][N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            cin >> dist[i][j];
        }
    }
    vector<int> del_order(n);
    for (int i = 0; i < n; i++)
        cin >> del_order[i];
    reverse(del_order.begin(), del_order.end());
    vector<int> ans;
    for (int k = 0; k < n; k++)
    {
        int k_v = del_order[k];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int new_dist = dist[i][k_v] + dist[k_v][j];
                dist[i][j] = min(dist[i][j], new_dist);
            }
        }
        int sum = 0;
        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                sum += dist[del_order[i]][del_order[j]];
            }
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //   cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}