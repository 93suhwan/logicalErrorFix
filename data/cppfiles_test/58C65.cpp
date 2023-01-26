#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10, MX = 2e5;
const long long mod = 998244353;
int bit[N];
void add(int x, int v) {
  for (int i = x; i <= MX; i += (i & -i)) bit[i] += v;
}
int find_pos(int v) {
  v--;
  int pos = 0;
  for (int i = (1 << 17); i; i >>= 1)
    if ((pos | i) <= MX && bit[pos | i] <= v) pos |= i, v -= bit[pos];
  return pos + 1;
}
long long fact[N], inv[N], ifact[N];
void precal(int n) {
  inv[1] = ifact[0] = ifact[1] = fact[0] = fact[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = mod - mod / i * inv[mod % i] % mod;
    ifact[i] = ifact[i - 1] * inv[i] % mod;
    fact[i] = fact[i - 1] * i % mod;
  }
}
long long C(int t, int h) {
  return fact[h] * ifact[t] % mod * ifact[h - t] % mod;
}
int x[N], y[N], n, m;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  precal(4e5);
  for (int i = 1; i <= MX; ++i) add(i, 1);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> x[i] >> y[i];
    map<int, int> a;
    for (int i = m; i; --i) {
      int pos = find_pos(y[i]);
      add(pos, -1);
      a[pos] = x[i];
    }
    for (pair<int, int> p : a) add(p.first, 1);
    for (pair<int, int> p : a)
      if (a.count(p.first + 1) && a[p.first + 1] > p.second) m--;
    cout << C(n, 2 * n - 1 - m) << "\n";
  }
  return 0;
}
