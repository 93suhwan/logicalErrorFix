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
ll sum[10], Dp[10][10];
ll par[101];
ll n, k, kq;
void dfs(ll u) {
  dp[u][0] = 1;
  for (auto x : a[u])
    if (x != par[u]) {
      par[x] = u;
      dfs(x);
      for (ll i = 1; i <= n; i++) dp[u][i] += dp[x][i - 1];
    }
}
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
ll d[100006], dk[100006];
void init() {
  d[0] = d[1] = dk[0] = dk[1] = 1ll;
  for (ll i = 0; i <= 100000; i++) {
    dk[i] = powmod(i, mod - 2);
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
    for (ll i = 1; i <= n; i++) {
      a[i].clear();
    }
    for (ll i = 1; i <= n - 1; i++) {
      ll u, v;
      cin >> u >> v;
      a[u].push_back(v);
      a[v].push_back(u);
    }
    if (k == 2) {
      cout << ((n - 1) * n) / 2 << endl;
      continue;
    }
    kq = 0;
    for (ll i = 1; i <= n; i++)
      if (a[i].size() >= k) {
        for (ll j = 1; j <= n; j++) par[j] = j;
        for (ll j = 1; j <= n; j++)
          for (ll jj = 1; jj <= n; jj++) {
            dp[j][jj] = 0;
          }
        dfs(i);
        for (ll j = 0; j <= n - 1; j++) {
          vector<vector<ll>> Dp(n + 1, vector<ll>(n + 1));
          vector<ll> sum(k + 1, 0);
          for (auto x : a[i]) {
            Dp[x][1] = dp[x][j] % mod;
            sum[1] += dp[x][j];
            sum[1] %= mod;
          }
          for (ll jj = 2; jj <= k; jj++)
            for (auto jjj : a[i]) {
              Dp[jjj][jj] =
                  (((sum[jj - 1] * dk[jj - 1]) % mod - Dp[jjj][jj - 1]) % mod *
                   dp[jjj][j] % mod) %
                  mod;
              sum[jj] += Dp[jjj][jj];
              sum[jj] %= mod;
            }
          kq = (kq + (sum[k] * dk[k]) % mod) % mod;
        }
      }
    cout << kq << endl;
  }
}
