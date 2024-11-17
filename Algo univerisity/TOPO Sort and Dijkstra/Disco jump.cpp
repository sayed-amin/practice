#include <bits/stdc++.h> // For standard libraries
using namespace std;

#define speed                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define pb push_back
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define setp(x) fixed << setprecision(x)
#define endl "\n"
#define INF LLONG_MAX // Changed to use LLONG_MAX for clarity

const ll N = 2000005; // Maximum number of nodes

vector<pair<ll, ll>> adj[N]; // Adjacency list for graph
ll d[N];                     // Distance array
pair<ll, ll> par[N];         // Parent array for tracking paths

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<char>> vc[n]; // 2D grid of characters

    // Read the grid input
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            char a, b, c, d;
            cin >> a >> b >> c >> d;
            vc[i].pb({a, b, c, d});
        }
    }

    // Initialize distances to infinity
    fill(d, d + N, INF);

    // Build the adjacency list based on the grid
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll curNode = i * m + j;
            ll newNode;

            // Right move
            if (j + 1 < m)
            {
                newNode = i * m + j + 1;
                char valNewNode = vc[i][j + 1][3];
                if (vc[i][j][0] == valNewNode)
                    adj[curNode].pb({newNode, 1});
                else if (vc[i][j][1] == valNewNode)
                    adj[curNode].pb({newNode, 0});
                else if (vc[i][j][2] == valNewNode)
                    adj[curNode].pb({newNode, 3});
                else if (vc[i][j][3] == valNewNode)
                    adj[curNode].pb({newNode, 2});
            }

            // Down move
            if (i + 1 < n)
            {
                newNode = (i + 1) * m + j;
                char valNewNode = vc[i + 1][j][0];
                if (vc[i][j][0] == valNewNode)
                    adj[curNode].pb({newNode, 2});
                else if (vc[i][j][1] == valNewNode)
                    adj[curNode].pb({newNode, 1});
                else if (vc[i][j][2] == valNewNode)
                    adj[curNode].pb({newNode, 0});
                else if (vc[i][j][3] == valNewNode)
                    adj[curNode].pb({newNode, 3});
            }

            // Up move
            if (i - 1 >= 0)
            {
                newNode = (i - 1) * m + j;
                char valNewNode = vc[i - 1][j][2];
                if (vc[i][j][0] == valNewNode)
                    adj[curNode].pb({newNode, 0});
                else if (vc[i][j][1] == valNewNode)
                    adj[curNode].pb({newNode, 3});
                else if (vc[i][j][2] == valNewNode)
                    adj[curNode].pb({newNode, 2});
                else if (vc[i][j][3] == valNewNode)
                    adj[curNode].pb({newNode, 1});
            }

            // Left move
            if (j - 1 >= 0)
            {
                newNode = i * m + j - 1;
                char valNewNode = vc[i][j - 1][1];
                if (vc[i][j][0] == valNewNode)
                    adj[curNode].pb({newNode, 3});
                else if (vc[i][j][1] == valNewNode)
                    adj[curNode].pb({newNode, 2});
                else if (vc[i][j][2] == valNewNode)
                    adj[curNode].pb({newNode, 1});
                else if (vc[i][j][3] == valNewNode)
                    adj[curNode].pb({newNode, 0});
            }
        }
    }

    // Dijkstra's algorithm to find shortest path
    set<pair<ll, ll>> se;
    se.insert({0, 0});
    par[0] = {-1, -1};
    d[0] = 0;

    while (!se.empty())
    {
        auto it = *se.begin();
        ll dis = it.first;
        ll v = it.second;
        se.erase(se.begin());

        for (auto edge : adj[v])
        {
            ll nextNode = edge.first;
            ll weight = edge.second;
            if (d[nextNode] > d[v] + weight)
            {
                par[nextNode] = {v, weight};
                if (se.find({d[nextNode], nextNode}) != se.end())
                {
                    se.erase({d[nextNode], nextNode});
                }
                d[nextNode] = d[v] + weight;
                se.insert({d[nextNode], nextNode});
            }
        }
    }

    cout << d[n * m - 1] << endl;
}

int main()
{
    speed;
    ll kk = 1; // Number of test cases
    while (kk--)
    {
        solve();
    }
    return 0;
}
