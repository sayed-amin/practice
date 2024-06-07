/*
post_fix.cpp
31 May 2024
Fri 20:37

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    string post_fix;
    getline(cin, post_fix);
    stack<int> operands;
    for (char &c : post_fix)
    {
        if (isdigit(c))
        {
            operands.push(c - '0'); // Convert character to integer and push onto stack
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            int op2 = operands.top();
            operands.pop();
            int op1 = operands.top();
            operands.pop();

            // Perform operation based on the operator
            switch (c)
            {
            case '+':
                operands.push(op1 + op2);
                break;
            case '-':
                operands.push(op1 - op2);
                break;
            case '*':
                operands.push(op1 * op2);
                break;
            case '/':
                operands.push(op1 / op2);
                break;
            }
        }
    }
    cout << operands.top() << endl;
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