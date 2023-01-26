#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll A = 26;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll BASE = 10000;
double q;
using ll = long long;
inline ll bit(ll x, ll y) { return (x & (1ll << y)); }
vector<ll> a[101];
ll dp[101][101];
ll Dp[101][101];
ll par[101];
ll n, k;
void dfs(ll u) {
  dp[u][0] = 1;
  for (auto x : a[u])
    if (x != par[u]) {
      par[x] = u;
      dfs(x);
      for (ll i = 1; i <= 100; i++) dp[u][i] += dp[x][i - 1];
    }
}
ll d[100006], dk[100006];
inline ll powmod(ll a, ll b) {
  ll res = 1ll;
  a %= mod;
  while (b) {
    if (b & 1ll) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1ll;
  }
  return res % mod;
}
void init() {
  d[0] = d[1] = dk[0] = dk[1] = 1;
  for (ll i = 2; i <= 100000; i++) {
    d[i] = d[i - 1] * i;
    d[i] %= mod;
    dk[i] = powmod(d[i], mod - 2);
  }
}
inline ll C(ll n, ll k) {
  if (n < k) return 0;
  return (((d[n] * dk[k]) % mod) * dk[n - k]) % mod;
}
ll kq;
void Dfs(ll u) {
  Dp[u][0] = 1;
  if (k == 2) kq += a[u].size() - ((par[u] == u) ? 0 : 1);
  for (auto x : a[u])
    if (x != par[u]) {
      for (ll i = 1; i <= 100; i++) {
        Dp[x][i] += Dp[u][i - 1];
        Dp[x][i] += (dp[u][i - 1]);
        if (i == 1) Dp[x][i]--;
        if (i >= 2) Dp[x][i] -= dp[x][i - 2];
      }
      for (ll i = 1; i <= 100; i++) {
        kq += C(dp[x][i] + Dp[x][i], k) - C(dp[x][i], k) - C(Dp[x][i], k) +
              3 * mod;
        kq %= mod;
      }
      Dfs(x);
    }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  ll t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    memset(dp, 0, sizeof dp);
    memset(Dp, 0, sizeof Dp);
    for (ll i = 1; i <= n; i++) {
      a[i].clear();
      par[i] = i;
    }
    for (ll i = 1; i <= n - 1; i++) {
      ll u, v;
      cin >> u >> v;
      a[u].push_back(v);
      a[v].push_back(u);
    }
    dfs(1);
    kq = 0;
    for (ll j = 1; j <= 100; j++) {
      kq += C(dp[1][j], k);
      kq %= mod;
    }
    Dfs(1);
    cout << kq << endl;
  }
}
