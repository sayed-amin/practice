#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int count = 0;
    for (int i = N - 1; i >= 2; --i)
    {
        int k = 0, j = i - 1;
        // Two pointers technique to find valid triangles
        while (k < j)
        {
            if (A[k] + A[j] > A[i])
            {
                // All pairs (A[k], A[j-1]), (A[k], A[j-2]), ..., (A[k], A[k+1]) will form valid triangles
                count += (j - k);
                --j;
            }
            else
            {
                ++k;
            }
        }
    }
    cout << count << endl;
    return 0;
}