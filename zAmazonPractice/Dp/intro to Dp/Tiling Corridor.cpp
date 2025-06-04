#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int first_tile = 1;
    int second_tile = 2;
    int final_ans = -1;
    int modulo = 1e7;
    for (int i = 3; i <= n; i++)
    {
        final_ans = (first_tile + second_tile) % modulo;
        first_tile = second_tile;
        second_tile = final_ans;
    }
    if (n > 2)
        cout << final_ans;
    else
    {
        cout << (n == 1 ? first_tile : second_tile);
    }

    return 0;
}