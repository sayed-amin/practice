#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> blocks(n);
    for (int i = 0; i < n; i++)
    {
        cin >> blocks[i];
    }
    sort(blocks.begin(), blocks.end());
    unordered_map<int, int> blockIndex;
    for (int i = 0; i < n; i++)
    {
        blockIndex[blocks[i]] = i;
    }
    vector<int> ans;
}