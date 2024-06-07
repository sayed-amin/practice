#include <bits/stdc++.h>
using namespace std;

int main()
{

    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        //   cout << ceil(n / 2.0) << endl;
        cout << ceil(log2(n)) << endl;
    }

    return 0;
}