#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
inline namespace {
template <typename B, typename E>
inline B slow_pow(const B &b, const E &e) {
  assert(e >= 0);
  B res = 1;
  for (int q = 0; q < e; q++) res *= b;
  return res;
}
template <typename B, typename E>
inline B bin_pow(const B &b, const E &e) {
  assert(e >= 0);
  B res = 1;
  B a = b;
  for (E q = e; q; q >>= 1) {
    if (q & 1) res *= a;
    a *= a;
  }
  return res;
}
template <typename B, typename E>
inline B mod_pow(const B &b, const E &e) {
  assert(e >= 0);
  B res = 1;
  B a = b;
  for (E q = e; q; q >>= 1) {
    if (q & 1) res = (res * a) % mod;
    a = (a * a) % mod;
  }
  return res;
}
}  // namespace
int fact[200001];
void pre() {
  fact[0] = 1;
  for (ll x = 1; x <= 200000; x++) fact[x] = (fact[x - 1] * x) % mod;
}
ll mod_inv(const ll &x) { return mod_pow(x, mod - 2); }
ll choose(const int &n, const int &k) {
  return (((fact[n] * mod_inv(fact[k])) % mod) * mod_inv(fact[n - k])) % mod;
}
void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  ll ans;
  if (a[n - 1] == a[n - 2])
    ans = fact[n];
  else if (a[n - 1] == a[n - 2] + 1) {
    int cnt = 0;
    ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] + 1 == a[n - 1]) cnt++;
    }
    ans = (((choose(n, cnt + 1) * (fact[cnt + 1] - fact[cnt])) % mod) *
           fact[n - cnt - 1]) %
          mod;
  } else
    ans = 0;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  pre();
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
