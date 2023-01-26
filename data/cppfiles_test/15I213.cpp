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

int lg[N], up[N][7], dep[N];
int d[N][N], f[N], rf[N];
int tin[N], tout[N], tmr;
vector < int > g[N];

int binpow(int a, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1) res *= a;
        a *= a;
        res %= mod;
        a %= mod;
        n /= 2;
    }
    return res;
}

void dfs(int v, int p)
{
    tin[v] = ++tmr;
    dep[v] = dep[p] + 1;
    up[v][0] = p;
    for (int j = 1; j < 7; ++j)
        up[v][j] = up[up[v][j - 1]][j - 1];
    for (int to : g[v])
        if (to != p) dfs(to, v);
    tout[v] = ++tmr;
}

bool upper(int u, int v){
    return (tin[u] < tin[v] && tout[v] < tout[u]);
}

int lca(int u, int v)
{
    if (upper(u, v)) return u;
    if (upper(v, u)) return v;

    for (int j = 6; j >= 0; --j)
        if (up[u][j] && !upper(up[u][j], v)) u = up[u][j];
    return up[u][0];
}

int dist(int u, int v)
{
    if (u == v) return 0;
    int w = lca(u, v);
    return dep[u] - dep[w] + dep[v] - dep[w];
}

int cnk(int n, int k)
{
    if (n < k) return 0;
    int res = f[n] * rf[k] % mod;
    res = res * rf[n - k] % mod;
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
        g[i].clear();

    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    if (k == 2)
    {
        cout << n * (n - 1) / 2 << '\n';
        return;
    }

    lg[1] = 0;
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i / 2] + 1;
    dep[0] = -1;
    dfs(1, 0);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            d[i][j] = dist(i, j);

    int ans = 0;
    for (int v = 1; v <= n; ++v)
    {
        for (int dst = 1; dst <= n; ++dst)
        {
            int cnt = 0;
            for (int u = 1; u <= n; ++u)
                if (d[v][u] == dst) cnt++;
            ans += cnk(cnt, k);
            ans %= mod;
        }
    }

    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(time(NULL));
    f[0] = rf[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        f[i] = f[i - 1] * i % mod;
        rf[i] = binpow(f[i], mod - 2);
    }

    int q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}






















