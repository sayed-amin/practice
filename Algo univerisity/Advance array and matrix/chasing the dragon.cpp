#include <bits/stdc++.h>
#define int long long
#define N 1000000
using namespace std;
int get_index(int t, int d, int n, int curr_pos)
{
    int final_pos;
    int temp = d % n;
    d = temp;
    if (t == 1)
    {
        final_pos = (curr_pos + d) % n;
        if (final_pos == 0)
            final_pos = n;
    }
    else
    {
        final_pos = (curr_pos - d + n) % n;
        if (final_pos == 0)
            final_pos = n;
    }
    return final_pos;
}
int forward_cost(vector<int> &path_sum, int curr_pos, int final_pos, int n, int c1)
{
    int total_cost = -1;
    if (final_pos >= curr_pos)
    {
        total_cost = path_sum[final_pos] - path_sum[curr_pos];
    }
    else
    {
        total_cost = path_sum[n] - path_sum[curr_pos];
        total_cost += path_sum[final_pos];
    }
    return total_cost;
}
int reverse_cost(vector<int> &path_sum, int curr_pos, int final_pos, int n, int c1)
{
    int total_cost = -1;
    if (final_pos <= curr_pos)
    {
        total_cost = path_sum[curr_pos] - path_sum[final_pos];
    }
    else
    {
        total_cost = path_sum[curr_pos];
        total_cost += path_sum[n] - path_sum[final_pos];
    }
    return total_cost;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, t;
    int d;
    cin >> n;
    vector<int> cost(n + 1, 0);
    vector<int> path_sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        path_sum[i] = cost[i] + path_sum[i - 1];
    }
    int curr_pos = 1;
    cin >> k;
    while (k--)
    {

        cin >> t;
        cin >> d;
        d = d % n;
        int final_pos = get_index(t, d, n, curr_pos);
        int f_cost = forward_cost(path_sum, curr_pos, final_pos, n, cost[1]);
        int r_cost = reverse_cost(path_sum, curr_pos, final_pos, n, cost[1]);
        int total_cost = min(f_cost, r_cost);
        cout << total_cost << "\n";
        curr_pos = final_pos;
    }
}