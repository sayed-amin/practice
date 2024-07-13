/*
Deletion.cpp
10 June 2024
Mon 22:26

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
    }
};
void solve()
{

    Node *head = new Node(1);
    Node *first = new Node(2);
    Node *second = new Node(3);
    Node *third = new Node(4);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}