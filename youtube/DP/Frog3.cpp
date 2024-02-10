#include <bits/stdc++.h>
using namespace std;

struct Line
{
    long long m, c;
    Line(long long _m, long long _c) : m(_m), c(_c) {}
    long long eval(long long x)
    {
        return m * x + c;
    }
};

struct ConvexHullTrick
{
    vector<Line> lines;
    int ptr;

    ConvexHullTrick()
    {
        ptr = 0;
    }

    void addLine(long long m, long long c)
    {
        Line newLine(m, c);
        while (lines.size() >= 2)
        {
            int n = lines.size();
            if ((newLine.c - lines[n - 2].c) * (lines[n - 2].m - lines[n - 1].m) >=
                (lines[n - 1].c - lines[n - 2].c) * (lines[n - 2].m - m))
            {
                lines.pop_back();
            }
            else
            {
                break;
            }
        }
        lines.push_back(newLine);
    }

    long long query(long long x)
    {
        if (ptr >= lines.size())
        {
            ptr = lines.size() - 1;
        }
        while (ptr < lines.size() - 1 && lines[ptr + 1].eval(x) <= lines[ptr].eval(x))
        {
            ptr++;
        }
        return lines[ptr].eval(x);
    }
};

int main()
{
    int N;
    long long C;
    cin >> N >> C;

    vector<int> h(N);
    for (int i = 0; i < N; i++)
    {
        cin >> h[i];
    }

    ConvexHullTrick cht;
    cht.addLine(0, 0);

    for (int i = 1; i < N; i++)
    {
        long long dp = cht.query(h[i]) + h[i] * h[i] + C;
        cht.addLine(-2 * h[i], dp + h[i] * h[i]);
    }

    cout << cht.query(h[N - 1]) << endl;

    return 0;
}
