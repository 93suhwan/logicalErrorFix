#include <bits/stdc++.h>
// #define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), parent(n + 1, -1), sl(n + 1, -1);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (auto x : a)
        cout << x << " ";
    cout << endl;
    for (auto x : b)
        cout << x << " ";

    set<int> st;
    for (int i = -1; i <= n; i++)
        st.insert(i);
    queue<int> q;
    q.push(0);
    int ans = 0;
    cout << endl;
    while (q.size())
    {
        ans++;
        int sz = q.size();
        for (int qq = 0; qq < sz; qq++)
        {
            int i = q.front();
            if (i + a[i] >= n)
            {
                cout << ans << endl;
                vector<int> v;
                while (i != -1)
                {
                    v.push_back(n - sl[i]);
                    i = parent[i];
                }
                v.pop_back();
                reverse(v.begin(), v.end());
                v.push_back(0);
                for (auto x : v)
                    cout << x << " ";
                return;
            }
            q.pop();
            st.erase(i);
            auto start = st.lower_bound(i);
            while (*start <= i + a[i])
            {
                int x = *start - b[*start];
                if (st.find(x) != st.end())
                {
                    sl[x] = *start;
                    parent[x] = i;
                    q.push(x);
                }
                start++;
            }
        }
    }
    cout << -1 << endl;
}

int_fast32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout << setprecision(15);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}