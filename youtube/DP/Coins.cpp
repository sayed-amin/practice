#include <iostream>
#include <vector>
#include <iomanip> // for setprecision
using namespace std;

double probability(int idx, int heads, int tails, const vector<double> &p)
{
    // Base case: if we have tossed all coins
    if (idx == p.size())
    {
        // Check if the number of heads is greater than the number of tails
        return (heads > tails) ? 1.0 : 0.0;
    }

    // Probability when the current coin lands heads
    double prob_heads = p[idx] * probability(idx + 1, heads + 1, tails, p);

    // Probability when the current coin lands tails
    double prob_tails = (1 - p[idx]) * probability(idx + 1, heads, tails + 1, p);

    // Sum the probabilities for both cases
    return prob_heads + prob_tails;
}

int main()
{
    int N;
    cin >> N;

    vector<double> p(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> p[i];
    }

    // Start with the first coin at index 0, and initially, heads and tails are both 0
    double result = probability(0, 0, 0, p);

    // Print the result with precision up to 9 decimal places
    cout << fixed << setprecision(9) << result << endl;

    return 0;
}
