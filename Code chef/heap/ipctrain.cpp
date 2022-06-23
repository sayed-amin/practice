// practice heap certificate topic 1 "multiset"
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct trainers
{
    /* data */
    int arrival_day, lectures, sadness;
};

void solve()
{
    int total_tranier, total_day;
    cin >> total_tranier >> total_day;
    vector<trainers> person(total_tranier);
    for (int i = 0; i < total_tranier; i++)
    {
        cin >> person[i].arrival_day >> person[i].lectures >> person[i].sadness;
    }
    sort(person.begin(), person.end(), [](trainers t1, trainers t2)
         { return t1.arrival_day < t2.arrival_day; });
    multiset<pair<int, int>> st;
    int index = 0;
    for (int i = 1; i <= total_day; i++)
    {
        while (index < total_tranier and person[index].arrival_day == i)
        {
            st.insert({person[index].sadness, person[index].lectures});
            index++;
        }
        if ((int)(st.size()) == 0)
            continue;
        auto v = st.end();
        v--;
        pair<int, int> intial_person = *v;
        intial_person.second -= 1;
        st.erase(v);
        if (intial_person.second > 0)
            st.insert(intial_person);
    }
    int total_sadness = 0;
    for (auto i : st)
    {
        total_sadness += (i.first * i.second);
    }
    cout << total_sadness << endl;
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