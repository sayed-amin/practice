#include <bits/stdc++.h>
using namespace std;
int predicate(int mid, int target)
{
    if (mid < target)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> vec(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
        }
    }
    while (q--)
    {
        int target;
        cin >> target;
        int low = -1, high = n * m;

        while (low + 1 < high)
        {
            int mid = (low + high) / 2;
            int r = mid / m;
            int c = mid % m;
            if (predicate(vec[r][c], target) == 0)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        cout << high / m << " " << high % m << endl;
    }

    return 0;
}