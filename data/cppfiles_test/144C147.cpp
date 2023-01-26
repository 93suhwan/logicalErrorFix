#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U>
inline bool chmax(T &a, U b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T, class U>
inline bool chmin(T &a, U b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
constexpr int INF = 1000000000;
constexpr ll llINF = 3000000000000000000;
constexpr int mod = 998244353;
constexpr double eps = 1e-10;
vector<int> prime_list(int n) {
  vector<int> v(n + 1), res;
  for (int i = n; i >= 2; i--) {
    for (int j = i; j <= n; j += i) v[j] = i;
  }
  for (int i = 2; i <= n; i++) {
    if (v[i] == i) res.push_back(i);
  }
  return res;
}
vector<int> next_divisor(int n) {
  vector<int> v(n + 1);
  for (int i = n; i >= 2; i--) {
    for (int j = i; j <= n; j += i) v[j] = i;
  }
  return v;
}
ll modpow(ll a, ll b, ll m = mod) {
  ll res = 1;
  while (b) {
    if (b & 1) {
      res *= a;
      res %= m;
    }
    a *= a;
    a %= m;
    b >>= 1;
  }
  return res;
}
vector<ll> inv, fact, factinv;
void init_fact(int n) {
  inv.resize(n + 1);
  fact.resize(n + 1);
  factinv.resize(n + 1);
  inv[0] = 0;
  inv[1] = 1;
  fact[0] = 1;
  factinv[0] = 1;
  for (ll i = 1; i <= n; i++) {
    if (i >= 2) inv[i] = mod - ((mod / i) * inv[mod % i] % mod);
    fact[i] = (fact[i - 1] * i) % mod;
    factinv[i] = factinv[i - 1] * inv[i] % mod;
  }
}
ll modinv(ll a, ll m = mod) {
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}
ll comb(int a, int b) {
  if (a < b) return 0;
  if (a < 0) return 0;
  return fact[a] * factinv[a - b] % mod * factinv[b] % mod;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int st = 0, ac = 0;
  for (int i = 0; i < k; i++) {
    st = ac;
    for (int j = 0; j < m; j++) {
      if (j < n % m) {
        cout << n / m + 1;
        for (int _ = 0; _ < n / m + 1; _++) {
          cout << " " << st + 1;
          st++;
          if (st == n) st = 0;
        }
        ac = st;
      } else {
        cout << n / m;
        for (int _ = 0; _ < n / m; _++) {
          cout << " " << st + 1;
          st++;
          if (st == n) st = 0;
        }
      }
      cout << endl;
    }
  }
  cout << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
