//
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr){} * ListNode(int x, ListNode *next) : val(x), next(next){}
                                                                                                                                     *
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        multiset<int> s;

        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *temp = lists[i];
            while (temp)
            {
                s.insert(temp->val);
                temp = temp->next;
            }
        }
        ListNode *ans = new ListNode(), *temp;
        temp = ans;

        while (!s.empty())
        {
            ListNode *n = new ListNode(s.top());
            temp->next = n;
            temp = temp->next;
            s.pop();
        }
        return ans->next;
    }
};
void solve()
{
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}