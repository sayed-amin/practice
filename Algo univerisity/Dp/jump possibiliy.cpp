#include <bits/stdc++.h>
using namespace std;
/*
max happiness -> namespace

include and dont include
*/
// try to think element of an array ( once , consider or not consider, included multiple time) perspective from element of array
// dp[i] what can max happiness can i get ?
int totalHappinessfun(int n, vector<int> &happiness)
{
    if (n <= 0)
    {
        return 0;
    }

    int ans = 0;
    // all the possiblity of inclusion mutiple time
    // Try to find the statem
    for (int i = 1; i <= n; i++)
    {
        ans = max(totalHappinessfun(n - i, happiness) + happiness[i], ans);
    }

    return ans;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> happiness(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> happiness[i];
        }
        int ans = totalHappinessfun(n, happiness);
        cout << ans << endl;
    }
    return 0;
}