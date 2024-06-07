
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, w;
    cin >> n >> w;

    map<int, int> present;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        num[i] = j;
        present[j] = i;
    }

    pair<int, int> ans = {-1, -1};
    for (int i = 0; i < n; i++)
    {
        int pair1 = num[i];
        int pair2 = w - pair1;
        if (present.count(pair2) && present[pair2] != i)
        {
            ans = {i, present[pair2]};
            break;
        }
    }

    if (ans.first == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans.first + 1 << " " << ans.second + 1 << endl;
    }

    return 0;
}
