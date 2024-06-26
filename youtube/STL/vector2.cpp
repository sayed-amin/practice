#include <iostream>
#include <vector>

using namespace std;

int findFirstMissingNumber(int N, vector<int> &A)
{
    // Initialize a boolean array to keep track of presence of natural numbers
    vector<bool> present(N + 1, false);

    // Mark the presence of each element of A
    for (int i = 0; i < N; ++i)
    {
        if (A[i] > 0 && A[i] <= N)
        {
            present[A[i]] = true;
        }
    }

    // Find the first missing natural number
    for (int i = 1; i <= N; ++i)
    {
        if (!present[i])
        {
            return i;
        }
    }

    // If all natural numbers are present, return N + 1
    return N + 1;
}

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    int firstMissing = findFirstMissingNumber(N, A);
    cout << firstMissing << endl;

    return 0;
}
