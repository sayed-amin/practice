#include <bits/stdc++.h>
using namespace std;

struct Lamp
{
    int x, y, r;
};

bool overlap(const Lamp &a, const Lamp &b)
{
    long long distSq = (long long)(a.x - b.x) * (a.x - b.x) + (long long)(a.y - b.y) * (a.y - b.y);
    long long radSumSq = (long long)(a.r + b.r) * (a.r + b.r);
    return distSq <= radSumSq;
}

bool canReach(const vector<Lamp> &lamps, int M)
{
    int n = lamps.size();
    vector<vector<int>> adj(n);

    // Build the graph
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (overlap(lamps[i], lamps[j]))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // Identify lamps touching the left and right side
    vector<int> leftLamps, rightLamps;
    for (int i = 0; i < n; ++i)
    {
        if (lamps[i].x - lamps[i].r <= 0)
            leftLamps.push_back(i);
        if (lamps[i].x + lamps[i].r >= M)
            rightLamps.push_back(i);
    }

    // BFS or DFS to check connectivity
    vector<bool> visited(n, false);
    queue<int> q;

    for (int start : leftLamps)
    {
        q.push(start);
        visited[start] = true;
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    // Check if any right-side lamp is visited
    for (int end : rightLamps)
    {
        if (visited[end])
            return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int M, N;
        cin >> M >> N;

        vector<Lamp> lamps(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> lamps[i].x >> lamps[i].y >> lamps[i].r;
        }

        if (canReach(lamps, M))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
