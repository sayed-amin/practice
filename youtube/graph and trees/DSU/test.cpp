// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int n, w;
//     cin >> n >> w;
//     vector<int> present(1e6 + 10, -1);
//     vector<int> num(n);
//     for (int i = 0; i < n; i++)
//     {
//         int j;
//         cin >> j;
//         num[i] = j;
//         present[j] = i + 1;
//     }
//     pair<int, int> ans;
//     ans = {-1, -1};
//     for (int i = 0; i < n; i++)
//     {
//         int pair1 = num[i];
//         int pair2 = w - pair1;
//         if (pair2 < 0)
//             continue;
//         if (present[pair2] != -1)
//         {
//             // cout << pair1 << " " << pair2 << endl;
//             ans = {present[pair1], present[pair2]};
//             break;
//         }
//     }
//     if (ans.first == -1)
//     {
//         cout << -1 << endl;
//     }
//     else
//     {
//         cout << ans.first << " " << ans.second << endl;
//     }

//     return 0;
// }

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
        present[j] = i + 1;
    }

    pair<int, int> ans = {-1, -1};
    for (int i = 0; i < n; i++)
    {
        int pair1 = num[i];
        int pair2 = w - pair1;

        if (pair2 < 0)
            continue;
        cout << "pair 1 and pair2 " << pair1 << " " << pair2 << endl;
        if (present.count(pair2) && present[pair2] != i + 1)
        {
            cout << "pair2 count " << present.count(pair2) << " " << present[pair2] << " " << i << endl;
            ans = {i + 1, present[pair2]};
            break;
        }
    }

    if (ans.first == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}
