// dfs
#include <bits/stdc++.h>
using namespace std;
int ans = 0;
void dfs(string b[], int i, int j, int m, int n)
{
    if (i < 0 || j < 0)
        return;
    if (i >= n || j >= m)
        return;
    if (b[i][j] == '0')
        return;

    ans++;
    b[i][j] = '0';

    dfs(b, i - 1, j, m, n);
    dfs(b, i + 1, j, m, n);

    dfs(b, i, j - 1, m, n);
    dfs(b, i, j + 1, m, n);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    string b[n];

    for (int j = 0; j < n; j++)
    {
        cin >> b[j];
    }
    vector<int> components;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[i][j] == '0')
                continue;
            dfs(b, i, j, m, n);
            components.push_back(ans);
            ans = 0;
        }
    }
    ans = 0;
    if (components.size() == 1)
        cout << "0" << endl;
    else
    {
        sort(components.begin(), components.end(), greater<int>());
        for (int i = 1; i < components.size(); i = i + 2)
        {
            ans += components[i];
        }

        cout << ans << endl;
        ans = 0;
    }
}
int32_t main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}