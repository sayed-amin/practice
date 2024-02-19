#include <iostream>
#include <vector>

using namespace std;

string canDistributeWaterEqually(int n, vector<int> &waterAmounts)
{
    long long totalWater = 0;
    for (int i = 0; i < n; ++i)
    {
        totalWater += waterAmounts[i];
    }
    if (totalWater % n != 0)
    {
        return "NO";
    }
    long long target = totalWater / n;
    for (int i = 0; i < n; ++i)
    {
        if (waterAmounts[i] % n != 0)
        {
            return "NO";
        }
    }
    return "YES";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> waterAmounts(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> waterAmounts[i];
        }
        cout << canDistributeWaterEqually(n, waterAmounts) << endl;
    }
    return 0;
}
