#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define ln '\n'
#define pb push_back
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define mod 1000000007

struct edge
{

    ll a;
    ll b;
    ll w;
};
edge ar[100005];
ll par[100005];
ll rnk[100005];

bool comp(edge a, edge b)
{
    return a.w < b.w;
}

ll find(ll a)
{
    if (par[a] == -1)
        return a;
    else
        return par[a] = find(par[a]);
}

void merge(ll a, ll b)
{
    if (rnk[a] < rnk[b])
        swap(a, b);
    par[b] = a;
    // if(rnk[a]==rnk[b]) rnk[a]++;
    rnk[a] += rnk[b];
}

int main()
{

    ll tt = 1;
    // cin>>tt;
    while (tt--)
    {

        ll n, m;
        cin >> n;
        m = n - 1;
        ll c = 0, s = 0, t = 0;

        for (ll i = 0; i <= n; i++)
        {
            par[i] = -1;
            rnk[i] = 1;
        }

        for (ll i = 0; i < m; i++)
        {
            cin >> ar[i].a >> ar[i].b >> ar[i].w;
        }
        sort(ar, ar + m, comp);

        for (ll i = 0; i < m; i++)
        {

            ll a1 = find(ar[i].a);
            ll b1 = find(ar[i].b);

            c += ar[i].w;
            s += (ll)rnk[a1] * rnk[b1] * ar[i].w;
            t += (ll)rnk[a1] * rnk[b1];
            if (a1 != b1)
            {
                merge(a1, b1);
            }
        }
        // cout<<t<<ln;
        cout << fixed << setprecision(4) << (double)((double)c - (double)s / (double)t) << ln;
    }
    return 0;
}