#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = ' ';
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = -1;
  }
  while (isdigit(ch)) x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
const int mod = 1e9 + 7;
int n, a[15], f[1 << 14], g[1 << 14];
int ni[15][15];
int P(int s, int t) {
  int res = 1;
  for (int i = 0; i < n; i++) {
    if (!(s & (1 << i))) continue;
    for (int j = 0; j < n; j++) {
      if (!(t & (1 << j))) continue;
      res = 1ll * res * ni[i][j] % mod;
    }
  }
  return res;
}
int fpow(int n) {
  int res = 1, m = mod - 2;
  while (m) {
    if (m & 1) res = 1ll * res * n % mod;
    n = 1ll * n * n % mod;
    m >>= 1;
  }
  return res;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) a[i] = read();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ni[i][j] = 1ll * a[i] * fpow(a[i] + a[j]) % mod;
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    long long s = (1 << n) - 1 - i;
    g[i] = P(i, s);
  }
  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    int cur = g[i];
    for (int j = (i - 1) & i; j; j = (j - 1) & i) {
      int res = 1;
      for (int p = 0; p < n; p++) {
        if (!((i - j) & (1 << p))) continue;
        for (int q = 0; q < n; q++) {
          if (!(j & (1 << q))) continue;
          res = 1ll * res * ni[p][q] % mod;
        }
      }
      cur -= 1ll * f[j] * g[i - j] % mod * fpow(res) % mod;
      if (cur < 0) cur += mod;
    }
    f[i] = cur;
    ans += 1ll * cur * __builtin_popcount(i) % mod;
    if (ans > mod) ans -= mod;
  }
  cout << ans;
}
