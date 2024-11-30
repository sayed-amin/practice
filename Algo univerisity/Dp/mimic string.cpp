#include <bits/stdc++.h>
using namespace std;
// dp[i ][j] what is min
int numberOfOperation(string s, string t, int i, int j)
{
    if (i < 0)
    {
        return j + 1;
    }
    if (j < 0)
    {
        return i + 1;
    }
    int ans = INT_MAX;
    if (s[i] == t[j])
    {
        ans = min(numberOfOperation(s, t, i - 1, j - 1), ans);
    }
    else
    {

        // delete
        ans = min(ans, numberOfOperation(s, t, i - 1, j));

        // subsitute
        ans = min(ans, numberOfOperation(s, t, i - 1, j - 1));

        // insert
        ans = min(ans, numberOfOperation(s, t, i, j - 1));

        ans++;
    }
    return ans;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        cout << numberOfOperation(s, t, n - 1, m - 1) << endl;
        ;
    }

    return 0;
}