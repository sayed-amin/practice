#include <iostream>
#include <vector>

using namespace std;
int findFirstMissingNumber(int N, vector<int> &A)
{
    vector<bool> present(N + 1, false);
    for (int i = 0; i < N; i++)
    {
        if (A[i] > 0 && A[i] <= N)
        {
            present[A[i]] = true;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (!present[i])
        {
            return i;
        }
    }
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
