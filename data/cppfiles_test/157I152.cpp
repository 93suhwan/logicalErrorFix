#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll minf = 0xc0c0c0c0c0c0c0c0;
const ll mod = 998244353;
const ll MAXN = 5050;
ll dp[5050][5050];
signed cnt[5050][5050];
ll mn[5050];
signed comb[5050][5050];
ll fact[MAXN] = {1, 1}, inv[MAXN] = {1, 1}, fact_inv[MAXN] = {1, 1};
void init() {
  for (ll i = 2; i < MAXN; i++) {
    fact[i] = ll(fact[i - 1]) * i % mod;
  }
  for (ll i = 2; i < MAXN; i++) {
    inv[i] = ll(inv[mod % i]) * (mod - mod / i) % mod;
  }
  for (ll i = 2; i < MAXN; i++) {
    fact_inv[i] = ll(fact_inv[i - 1]) * inv[i] % mod;
  }
}
ll nCr(ll n, ll r) {
  return n >= r && r >= 0
             ? ll(fact[n]) * fact_inv[n - r] % mod * fact_inv[r] % mod
             : 0;
}
ll nPr(ll n, ll r) {
  return n >= r && r >= 0 ? ll(fact[n]) * fact_inv[n - r] % mod : 0;
}
void add(ll &x, ll y) {
  x += y;
  if (x >= mod) {
    x -= mod;
  }
  if (x < 0) {
    x += mod;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(20);
  init();
  comb[0][0] = 1;
  for (ll i = 1; i < 5050; i++) {
    comb[i][0] = 1;
    for (ll j = 1; j <= i; j++) {
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
      if (comb[i][j] >= mod) {
        comb[i][j] -= mod;
      }
    }
  }
  0xF;
  ll n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << 1 << '\n';
    return 0;
  }
  string s;
  cin >> s;
  for (ll i = 0; i < n; i++) {
    cnt[i][i] = s[i] == '1';
  }
  for (ll i = 0; i < n; i++) {
    for (ll j = i + 1; j < n; j++) {
      cnt[i][j] = cnt[i][j - 1] + cnt[j][j];
    }
  }
  memset(mn, -1, sizeof(mn));
  for (ll i = 0; i < n; i++) {
    for (ll j = i; j >= 0; j--) {
      if (cnt[j][i] == k) {
        mn[i] = j;
      }
    }
  }
  for (ll l = 1; l <= n; l++) {
    for (ll i = 0; i + l <= n; i++) {
      ll j = i + l - 1;
      if (cnt[i][j] < k) {
        dp[i][j] = 1;
      } else if (cnt[i][j] == k) {
        dp[i][j] = comb[l][k];
      } else {
        dp[i][j] = dp[i][j - 1];
        char r = s[j];
        ll L = mn[j];
        if (r == '0') {
          dp[i][j] += dp[i][L - 1] * comb[j - L][k - 1] % mod;
        } else {
          dp[i][j] += dp[i][L - 1] * comb[j - L][k] % mod;
        }
      }
      dp[i][j] %= mod;
      if (dp[i][j] < 0) {
        dp[i][j] += mod;
      }
      0xF;
    }
  }
  cout << dp[0][n - 1] % mod << '\n';
  return 0;
}
