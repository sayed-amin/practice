/*
SquareOfSortedArray.cpp
05 June 2025 
Thu 12:27 

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl  "\n"  
void solve()
{
    int n;cin>>n;
    vector<int>a(n),ans(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int i=0,j=n-1, k=n-1;
    while(i<=j){
        int left_square= a[i]*a[i];
        int right_square= a[j]*a[j];
        if(left_square>right_square){
            ans[k--]=left_square;
            i++;
        }else{
            ans[k--]=right_square;
            j--;
            
        }
    }
    for(auto i: ans){
        cout<<i<<" ";
    }
}
int32_t main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int testcase=1;//in>>testcase;
while(testcase--)
{
solve();
}
return 0;
}