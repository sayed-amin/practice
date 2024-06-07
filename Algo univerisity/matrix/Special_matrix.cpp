#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll maxi = 0;

    while (t--)
    {
        ll n;
        cin >> n;
        int a[n][n];
        ll sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            ll sum = 0;
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                sum += a[i][j];
            }
            sum2 += sum;
            maxi = max(maxi, sum);
        }
        for (int i = 0; i < n; i++)
        {
            ll sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += a[j][i];
            }

            maxi = max(maxi, sum);
        }
        cout << maxi * n - sum2 << endl;
    }
}