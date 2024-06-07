#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<int> matrix;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            matrix.push_back(temp);
        }
    }

    auto it = matrix.begin();
    if (n * m != r * c)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << *it << " ";
                it++;
            }
            cout << endl;
        }
        return 0;
    }
    int x = 0, y = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << *it << " ";
            it++;
        }
        cout << endl;
    }

    return 0;
}