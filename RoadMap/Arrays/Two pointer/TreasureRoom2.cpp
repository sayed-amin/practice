/*
TreasureRoom2.cpp
07 June 2025 
Sat 16:14 

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl  "\n"  
void solve()
{
int n,w;cin>>n>>w;
vector<int>a(n);
for(int i=0;i<n;i++){
        cin>>a[i];
}

vector<int>ans;
unordered_map<int,int>umap;
for(int i=0;i<n;i++){
    int j=i+1,k=n-1;
    if(i>0 && a[i]==a[i-1])
    continue;
   for(int j=i+1;j<n;j++){
    
        int third_value=w-a[i]-a[j];
       if(umap.find(third_value)!=umap.end() && umap[third_value]!=i && umap[third_value]!=j){
       cout << i+1 << " " << j+1 << " " << umap[third_value]+1 << endl;
return;
        break;
       }

    }
    if(!ans.empty()){
        break;;
    }
    umap[a[i]]=i;

}
if(ans.size()==0){
cout<<-1<<endl;
return;
}


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