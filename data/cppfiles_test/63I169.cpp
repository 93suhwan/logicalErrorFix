#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(), v.end()
#define repf(i, a, b) for (ll i = a; i < b; i++)
#define repb(i, a, b) for (ll i = a; i >= b; i--)
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define mod 1000000007
#define MOD 998244353

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<ll> ors;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
ld PI = 3.14159265359;

ll power(ll a, ll n, ll m)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans = (ans * a) % m;
        n >>= 1;
        a = (a * a) % m;
    }
    return ans;
}

ll invmod(ll a, ll m)
{
    return power(a, m - 2, m);
}

ll fac[1000001];

void init(ll m)
{
    fac[0] = fac[1] = 1;
    repf(i, 2, 1000001) fac[i] = (fac[i - 1] * i) % m;
}

ll nCr(ll n, ll r, ll m)
{
    if (n < r || r < 0)
        return 0;
    ll nr = fac[n];
    ll dr = (fac[n - r] * fac[r]) % m;
    dr = invmod(dr, m);
    ll res = (nr * dr) % m;
    return res;
}

ll par[2][10001], sz[2][10001];

ll find_par(ll id, ll x)
{
    if (par[id][x] == x)
        return x;
    return par[id][x] = find_par(id, par[id][x]);
}

void merge(ll id, ll x, ll y)
{
    if (sz[id][x] < sz[id][y])
        swap(x, y);
    sz[id][x] += sz[id][y];
    par[id][y] = par[id][x];
}

void solve(ll tt)
{
    ll n, m[2];
    cin >> n >> m[0] >> m[1];
    repf(i, 1, n + 1)
    {
        par[0][i] = par[1][i] = i;
        sz[0][i] = sz[1][i] = 1;
    }
    repf(j, 0, 2)
    {
        repf(i, 0, m[j])
        {
            ll x, y;
            cin >> x >> y;
            merge(j, x, y);
        }
    }
    vector<pair<ll, ll>> ans;
    repf(x, 1, n + 1)
    {
        repf(y, x + 1, n + 1)
        {
            ll px[2], py[2];
            repf(j, 0, 2)
            {
                px[j] = find_par(j, x);
                py[j] = find_par(j, y);
            }
            if (px[0] != py[0] && px[1] != py[1])
            {
                ans.pb({x, y});
                merge(0, px[0], py[0]);
                merge(1, px[1], py[1]);
            }
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i.fi << " " << i.se << endl;
}

int main()
{
    IOS;
    // init(mod);
    ll t = 1;
    // cin >> t;
    repf(tt, 1, t + 1)
    {
        solve(tt);
    }
}