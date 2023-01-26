#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
#define vpll vector<pll>
#define vpii vector<pii>
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define ff first
#define ss second
#define br cout << "\n";
#define printv(v)         \
    for (auto x : v)      \
        cout << x << ' '; \
    br;
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define forn(i, n) for (ll i = 0; i < n; i++)

#define FORR(i, b, a) for (ll i = b; i >= a; i--)
#define fornr(i, n) for (ll i = n - 1; i >= 0; i--)

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

#define basP 233
#define INF INT_MAX
#define INFL LLONG_MAX
#define puts(n) cout << n;
#define setbits(x) __builtin_popcount(x)

#define mset(m, v) memset(m, v, sizeof(m))
#define N 1e6 + 5
#define vl2d vector<vector<ll>>
#define vi2d vector<vector<int>>

ll dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

#define mod 1000000007
#define mod1 998244353

int solve()
{
    ll n;
    cin >> n;

    vl2d adj(n);

    vpll a(n);
    vll ans(n, 0);
    forn(i, n)
    {
        ll t;
        cin >> t;
        a[i] = {t, i};
    }

    sort(all(a));

    forn(i, n - 1)
    {
        adj[a[i].ss].pb(a[i + 1].ss);
    }

    ans[a[n - 1].ss] = 1;

    forn(i, n)
    {
        ll t;
        cin >> t;
        a[i] = {t, i};
    }

    sort(all(a));

    forn(i, n - 1)
    {
        if (adj[a[i].ss].size() > 0 && adj[a[i].ss][0] != a[i + 1].ss)
            adj[a[i].ss].pb(a[i + 1].ss);
    }

    ans[a[n - 1].ss] = 1;

    queue<ll> q;

    forn(i, n) if (ans[i]) q.push(i);

    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();

        for (auto i : adj[cur])
        {
            if (!ans[i])
            {
                ans[i] = 1;
                q.push(i);
            }
        }
    }

    forn(i, n) cout << ans[i];
    br;

    return 0;
}

int main()
{
    fast;
    ll t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}