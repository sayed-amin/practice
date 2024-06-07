#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> arr(1001, vector<int>(1001, 0));
    for (int i = 0; i < n; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j < x2; j++)
        {
            arr[j][y1]++;
            arr[j][y2]--;
        }
    }
    int ans = 0;
    for (int i = 0; i <= 1000; i++)
    {
        if (arr[i][0] == k)
        {
            ans++;
        }
        for (int j = 1; j <= 1000; j++)
        {
            arr[i][j] += arr[i][j - 1];
            if (arr[i][j] == k)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}