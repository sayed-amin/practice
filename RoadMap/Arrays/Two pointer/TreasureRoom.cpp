/*
TreasureRoom.cpp
06 June 2025 
Fri 11:37 

*/
#include<bits/stdc++.h>
using namespace std;

#define endl  "\n"  
void solve()
{
    int n,w;
    cin>>n>>w;
    unordered_map<int

    map<int,int>mp;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        int needed=w-x;
        if(mp.count(x)){
            cout<<mp[needed]+1<<" "<<i+1<<endl;
        return ;        }
        if(!mp.count(x)){
            mp[x]=i;
        }
    }
    cout<<-1<<endl;
    
}
int32_t main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int testcase=1;
//cin>>testcase;
while(testcase--)
{
solve();
}
return 0;
}