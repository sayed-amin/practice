#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    cin >> n >> target;

    unordered_map<int, int> blockIndex;
    vector<int> blocks(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> blocks[i];
        blockIndex[blocks[i]] = i;
    }

    vector<int> answer;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int thirdBlock = target - (blocks[i] + blocks[j]);
            if (blockIndex.count(thirdBlock) && blockIndex[thirdBlock] != i && blockIndex[thirdBlock] != j)
            {
                answer.push_back(i);
                answer.push_back(j);
                answer.push_back(blockIndex[thirdBlock]);
                break;
            }
        }
        if (!answer.empty())
            break;
    }

    if (answer.empty())
    {
        cout << -1 << "\n";
    }
    else
    {
        for (int index : answer)
        {
            cout << index + 1 << " "; // Output 1-indexed block indices
        }
        cout << "\n";
    }

    return 0;
}
