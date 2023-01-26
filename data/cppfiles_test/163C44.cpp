#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int ksm(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod, y >>= 1;
  }
  return res;
}
int inv(int x) { return ksm(x, mod - 2); }
int T, n, m, rb, cb, rd, cd, p;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    p = (1 - 1ll * p * inv(100) % mod + mod) % mod;
    int dr = -1, dc = -1, u = 0, v = 1;
    for (int i = 1; i <= 4 * (n - 1) * (m - 1); i++) {
      if (rb + dr < 1 || rb + dr > n) dr = -dr;
      if (cb + dc < 1 || cb + dc > m) dc = -dc;
      rb += dr, cb += dc;
      u = (u + 1) % mod;
      if (rb == rd || cb == cd) {
        u = 1ll * u * p % mod;
        v = 1ll * v * p % mod;
      }
    }
    v = (1 - v + mod) % mod;
    cout << 1ll * u * inv(v) % mod << '\n';
  }
  return 0;
}
