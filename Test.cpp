/*
Test.cpp
20 June 2025 
Fri 09:36 

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl  "\n"  
struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0),next(nullptr);
    ListNode(int x): val(x),next(nullptr);
    ListNode(int x,ListNode*next) : val(x), next(next);
}
void solve()
{

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