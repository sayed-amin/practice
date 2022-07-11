// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs(int v, int par, vector<vector<int>> &g, vector<int> &d, vector<int> &m)
    {

        for (auto child : g[v])
        {

            if (child == par)
                continue;
            d[child] += d[v] + 1;
            dfs(child, v, g, d, m);
            // m[v] = max(m[v], d[child]);
        }
    }
    void dfs2(int v, int par, vector<vector<int>> &g, vector<int> &d, vector<int> &m)
    {
        m[v] = d[v];
        for (auto child : g[v])
        {

            if (child == par)
                continue;
            dfs2(child, v, g, d, m);
            m[v] = max(m[v], m[child]);
        }
    }
    vector<int> solve(int n, int q, vector<vector<int>> &e,
                      vector<vector<int>> &query)
    {
        // code here
        vector<vector<int>> g(n);
        vector<int> d(n, 0);
        vector<int> m(n, 0);
        //  for (int i = 0; i < n - 1; i++)
        // {
        //     cout << e[i][0] << " " << e[i][1] << " ";
        // }
        for (int i = 0; i < n - 1; i++)
        {
            g[e[i][0]].push_back(e[i][1]);
            g[e[i][1]].push_back(e[i][0]);
        }

        d[0] = 0;
        dfs(0, -1, g, d, m);
        // for (auto i : m)
        //     cout << i << " ";
        dfs2(0, -1, g, d, m);
        // cout << m[4];
        vector<int> ans;
        for (int i = 0; i < q; i++)
        {
            int u = query[i][0];
            int v = query[i][1];
            if (d[u] > d[v])
                swap(u, v);
            // cout << u << " " << v;
            int maax = 0;
            for (auto child : g[u])
            {
                // cout << child;
                if (child == v)
                    continue;
                // cout << m[child];
                maax = max(m[u], m[child]);
            }
            ans.push_back(maax);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, Q;
        cin >> N >> Q;
        vector<vector<int>> Edge(N - 1, vector<int>(2));

        for (int i = 0; i < N - 1; i++)
            cin >> Edge[i][0] >> Edge[i][1];

        vector<vector<int>> query(Q, vector<int>(2));

        for (int i = 0; i < Q; i++)
            cin >> query[i][0] >> query[i][1];

        Solution ob;
        vector<int> annswer = ob.solve(N, Q, Edge, query);

        for (auto it : annswer)
            cout << it << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends