#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long inv(long long x) { return powmod(x, mod - 2); }
void solve() {
  int n, m, r1, c1, r2, c2, p, dr = 1, dc = 1;
  cin >> n >> m >> r1 >> c1 >> r2 >> c2 >> p;
  int tot = 0;
  if (r1 + dr == n + 1 || r1 + dr == 0) dr *= -1;
  if (c1 + dc >= m + 1 || c1 + dc == 0) dc *= -1;
  auto state = make_tuple(r1, c1, dr, dc);
  long long ans = 0;
  vector<int> v(1, 0);
  while (1) {
    v.push_back(v.back() + (r1 == r2 || c1 == c2));
    r1 += dr;
    c1 += dc;
    if (r1 + dr == n + 1 || r1 + dr == 0) dr *= -1;
    if (c1 + dc >= m + 1 || c1 + dc == 0) dc *= -1;
    tot++;
    if (make_tuple(r1, c1, dr, dc) == state) {
      long long T = tot, q = powmod((100 - p) * inv(100), v.back());
      for (int i = 0; i < T; i++) {
        long long p_i =
            powmod((100 - p) * inv(100), v[i]) * (p * inv(100) % mod) % mod;
        if (v[i + 1] == v[i]) p_i = 0;
        ans += p_i * ((T * q - i * q + i) % mod) % mod *
               inv((mod + 1 - q) * (mod + 1 - q)) % mod;
      }
      cout << (ans % mod + mod) % mod << '\n';
      return;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
