#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define pb push_back
#define ff first
#define ss second
#define ld long double
#define sz(x) (int)((x).size())

using namespace std;
using namespace __gnu_pbds;

// order_of_key, find_by_order
template < class T >
using ordered_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;

mt19937 rnd(time(0));

const int N = 105, inf = 1e18 + 100;
const int mod = 1e9 + 7;

void solve()
{
    string s, t;
    cin >> s >> t;

    int n = sz(s), m = sz(t), j = 0;
    for (int i = 0; i < n; ++i)
        if (j < m && s[i] == t[j]) j++;

    if (j < m)
    {
        cout << "NO" << '\n';
        return;
    }

    map < char, vector < int > > p;
    for (int i = 0; i < n; ++i)
        p[s[i]].pb(i);

    j = 1;
    int p1 = p[t[0]][0], l = p1;
    for (int i = p1 + 1; i < n; ++i)
    {
        if (s[i] == t[j])
        {
            if ((i - l) % 2 == 1) j++, l = i;
            if (j == m) break;
        }
    }

    if (j == m)
    {
        cout << "YES" << '\n';
        return;
    }

    if (sz(p[t[0]]) > 1)
    {
        int ok = 0;
        for (int i = 1; i < sz(p[t[0]]); ++i)
        {
            if (p[t[0]][i] % 2 != p1 % 2)
            {
                p1 = p[t[0]][i];
                ok = 1;
                break;
            }
        }

        if (ok)
        {
            j = 1, l = p1;
            for (int i = p1 + 1; i < n; ++i)
            {
                if (s[i] == t[j])
                {
                    if ((i - l) % 2 == 1) j++, l = i;
                    if (j == m) break;
                }
            }

            if (j == m)
            {
                cout << "YES" << '\n';
                return;
            }
        }
    }

    cout << "NO" << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(NULL));
    int q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}






















