#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 998244353;
constexpr int N = 400000;
ll fac[N + 1], ifac[N + 1];
ll qpow(ll x, ll y, ll p = mod) {
  ll res = 1;
  x %= p;
  while (y) {
    if (y & 1) res = res * x % p;
    x = x * x % p;
    y >>= 1;
  }
  return res;
}
ll inv(ll x, ll p = mod) { return qpow(x, p - 2, p); }
ll comb(int x, int y) {
  assert(x >= y);
  return fac[x] * ifac[x - y] % mod * ifac[y] % mod;
}
int t[N];
void add(int x, int v) {
  while (x <= 200000) {
    t[x] += v;
    x += x & -x;
  }
}
int kth(int k) {
  int cnt = 0, num = 0;
  for (int i = 17; i >= 0; i--) {
    num += 1 << i;
    if (num >= 200000 || cnt + t[num] >= k) {
      num -= 1 << i;
    } else {
      cnt += t[num];
    }
  }
  return num + 1;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  fac[0] = 1;
  for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i % mod;
  ifac[N] = inv(fac[N]);
  for (int i = N; i > 0; i--) ifac[i - 1] = ifac[i] * i % mod;
  for (int i = 1; i <= 200000; i++) add(i, 1);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m);
    for (int i = 0; i < m; i++) {
      cin >> x[i] >> y[i];
    }
    set<int> S;
    for (int i = m - 1; i >= 0; i--) {
      S.insert(kth(y[i] + 1));
      y[i] = kth(y[i]);
      add(y[i], -1);
    }
    for (int i = 0; i < m; i++) {
      add(y[i], 1);
    }
    ll ans = comb(2 * n - 1 - S.size(), n);
    cout << ans << '\n';
  }
  return 0;
}
