#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll minf = 0xc0c0c0c0c0c0c0c0;
const ll mod = 998244353;
const ll MAXN = 5050;
ll dp[5050];
ll mx[5050];
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
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(20);
  init();
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (k == 0) {
    cout << 1 << '\n';
    return 0;
  }
  for (ll l = 0, r = -1, c = 0;;) {
    while (r < n - 1 && c + (s[r + 1] == '1') <= k) {
      ++r;
      c += s[r] == '1';
    }
    if (c < k) {
      break;
    }
    mx[l] = r;
    c -= s[l] == '1';
    ++l;
  }
  for (ll i = n - 1; i >= 0; i--) {
    if (mx[i] == 0) {
      dp[i] = 1;
    } else if (mx[i] == n - 1) {
      dp[i] = nCr(n - i, k);
    } else {
      dp[i] = dp[i + 1];
      ll R = mx[i];
      if (s[i] == '0') {
        dp[i] += nCr(R - i, k - 1);
        if (dp[i] >= mod) {
          dp[i] -= mod;
        }
      } else {
        dp[i] += nCr(R - i, k);
        if (dp[i] >= mod) {
          dp[i] -= mod;
        }
      }
    }
  }
  cout << dp[0] << '\n';
  return 0;
}
