#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
ll mod = 1e9 + 7;
int const N = 3e5 + 100;
mt19937 rnd;
ll random(ll limit) {
  uniform_int_distribution<ll> uniform_dist(0, limit);
  return uniform_dist(rnd);
}
ll bpow(ll a, ll p) {
  ll res = 1;
  while (p > 0) {
    if (p % 2) {
      res = res * a % mod;
    }
    a = a * a % mod;
    p /= 2;
  }
  return res;
}
ll inv(ll a) { return bpow(a, mod - 2); }
void solve() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  ll M = 2 * x[max_element(x.begin(), x.end()) - x.begin()];
  vector<ll> kek(M + 1, 1e9);
  kek[0] = 0;
  for (int i = 0; i < n; i++) {
    vector<ll> nkek(M + 1, 1e9);
    for (int j = 0; j <= M; j++) {
      int nl, nr;
      if (x[i] <= j) {
        nl = j - x[i];
        nr = kek[j] + x[i];
      } else {
        nl = 0;
        nr = kek[j] + x[i];
      }
      nkek[nl] = min(nkek[nl], (ll)nr);
      if (x[i] <= kek[j]) {
        nr = kek[j] - x[i];
        nl = j + x[i];
      } else {
        nr = 0;
        nl = j + x[i];
      }
      if (nl <= M) {
        nkek[nl] = min(nkek[nl], (ll)nr);
      }
    }
    kek = nkek;
  }
  ll ans = 1e9;
  for (int i = 0; i <= M; i++) {
    ans = min(ans, i + kek[i]);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  rnd = mt19937(956231);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
