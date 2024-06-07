#include <bits/stdc++.h>
using namespace std;
int a, b, n, k = 0;
void print(int x, int y, vector<vector<int>> &mat, int m)
{

    if (x >= 0 && y >= 0 && x < mat.size() && y < mat[0].size() && mat[x][y])
    {

        cout << x << " " << y << " " << mat[x][y] << " " << m << endl;
        k++;
    }
}
void drive(int x, int y, vector<vector<int>> &mat)
{
    int i = 1, coun = 1, m;
    while (k < n)
    {
        m = coun % 4;
        for (int j = 0; j < i; j++)
        {
            switch (m)
            {
            case 1:
            {
                x = x + 1;
                print(x, y, mat, m);
                break;
            }
            case 2:
            {
                y = y + 1;
                print(x, y, mat, m);
                break;
            }
            case 3:
            {
                x = x - 1;
                print(x, y, mat, m);
                break;
            }
            case 0:
            {
                y = y - 1;
                print(x, y, mat, 4);
                break;
            }
            }
        }
        if (coun % 2 == 0)
            i = i + 1;
        coun++;
    }
}
int main()
{
    cin >> a;
    cin >> b;
    cin >> n;
    vector<vector<int>> mat(a, vector<int>(b, 0));
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x;
        cin >> y;
        cin >> mat[x][y];
    }
    int start[2];
    cin >> start[0];
    cin >> start[1];
    print(start[0], start[1], mat, 1);
    drive(start[0], start[1], mat);
}