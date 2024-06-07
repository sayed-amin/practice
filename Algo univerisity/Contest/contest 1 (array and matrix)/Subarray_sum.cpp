#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findMaxSubarrayLength(vector<int> &arr)
{
    int n = arr.size();
    int max_length = 0;
    vector<int> remainder_index(7, -1); // Initialize remainder_index array with -1

    int prefix_sum = 0;
    for (int i = 0; i < n; ++i)
    {
        prefix_sum = (prefix_sum + arr[i]) % 7;

        if (remainder_index[prefix_sum] != -1)
        {
            max_length = max(max_length, i - remainder_index[prefix_sum]);
        }
        else
        {
            remainder_index[prefix_sum] = i;
        }
    }

    return max_length;
}

int main()
{
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    int max_subarray_length = findMaxSubarrayLength(arr);
    cout << max_subarray_length << endl;

    return 0;
}
