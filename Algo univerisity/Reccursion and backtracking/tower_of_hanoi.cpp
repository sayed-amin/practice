/*
tower_of_hanoi.cpp
02 June 2024
Sun 13:51

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void towerOfHanoi(int n, int source, int target, int auxillary, vector<vector<int>> &moves)
{
    if (n == 1)
    {
        moves.push_back({n, source, target});
        return;
    }

    towerOfHanoi(n - 1, source, auxillary, target, moves);
    moves.push_back({n, source, target});
    towerOfHanoi(n - 1, auxillary, target, source, moves);
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> moves;
    towerOfHanoi(n, 1, 2, 3, moves);
    cout << moves.size() << endl;
    for (auto &i : moves)
    {
        cout << i[0] << " " << i[1] << " " << i[2] << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    //   cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}