/*
JumpPossibiliy.cpp
15 June 2025 
Sun 06:19 

*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl "\n"
// int jumpPosibility(int idx,int dest,vector<int>&jumps){
//     if(idx==jumps.size()-1|| idx==dest){
//         return 0;
//     }

//     int jumpsconsume= jumpPosibility(idx+1,dest,jumps)+a[i];

//     return jumpsconsume;
// }
void solve() {
     int n, s;
    cin >> n >> s;
    vector<int> jumps(n);
    
    for (int i = 0; i < n; i++) {
        cin >> jumps[i];
    }
    
    // 1D DP Solution
    vector<bool> dp(s + 1, false);
    dp[0] = true; // Base case: sum 0 is always possible (select nothing)
    
    // Process each element one by one
    for (int i = 0; i < n; i++) {
        // Iterate backwards to avoid using updated values from current iteration
        for (int j = s; j >= jumps[i]; j--) {
            // If we can make sum (j - jumps[i]), then we can make sum j
            // by including current element jumps[i]
            dp[j] = dp[j] || dp[j - jumps[i]];
        }
    }
    
    cout << (dp[s] ? "YES" : "NO") << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    cin >> testcase;
    while (testcase--) {
        solve();
    }
    return 0;
}