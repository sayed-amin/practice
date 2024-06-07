#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, k, q;
    cin >> n >> k >> q;
    vector<int> vec(n + 1, 0);
    while (q--)
    {
        int t;
        cin >> t;
        vec[t] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        vec[i] += vec[i - 1];
    }
    int ans = __INT_MAX__;
    for (int i = k + 1; i <= n; i++)
    {
        ans = min(ans, vec[i] - vec[i - k]);
    }
    cout << ans << endl;
    return 0;
}