/*
ms.cpp
30 May 2025 
Fri 11:07 

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl  "\n"  

void solve()
{

    vector<string> group={"act","dog","cat","god","tac","tom"};
    
    /*
    map<string,vector<string>> result;
    foreach: 
        act: act
        dob: dog
        cat: act
        god: dog
        tac: act
        tom: mot
    
        key: right value : act, cat,

    */
   int n=group.size();
   unordered_map<string,vector<string>> result;
    for(int i=0;i<n;i+=){
        string temp=group[i];
        sort(temp[i].begin(),temp[i].end());
        result[temp].push_back(group[i]);
    }

    for(auto i: result){

        vector<string> groupAna=i->second;
        for(auto s: groupAna){
            cout<<s<<" ";
        }
    }
    //
    

}
int32_t main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int testcase=1;
cin>>testcase;
while(testcase--)
{
solve();
}
return 0;
}