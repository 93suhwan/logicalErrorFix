#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void _debug() { std::cerr << std::endl; }
template <typename T, typename... U>
void _debug(T t, U... args) {
  std::cerr << " " << t;
  _debug(args...);
}
const int maxn = 1e6 + 10;
const int mod = 998244353;
int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * a * ans % mod;
    b >>= 1;
    a = 1ll * a * a % mod;
  }
  return ans;
}
int fac[maxn], inv[maxn];
int C(int i, int j) {
  42;
  if (i < j || j < 0) return 0;
  return 1ll * fac[i] * inv[j] % mod * inv[i - j] % mod;
}
void init() {
  fac[0] = 1;
  for (int i = 1; i < maxn; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[maxn - 1] = qpow(fac[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}
int n;
char s[maxn][6];
int b[2], c[2];
int main() {
  init();
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for (int j = 0; j < 2; j++) {
      if (s[i][j] == '?') c[j]++;
    }
    if (s[i][0] == 'B') b[0]++;
    if (s[i][1] == 'W') b[1]++;
  }
  ll ans = 0;
  for (int i = 0; i <= c[0]; i++) {
    int bm = b[0] + i;
    ll way = C(c[0], i);
    if (bm - b[1] > c[1]) break;
    ans += way * C(c[1], bm - b[1]) % mod;
    ans %= mod;
  }
  ll sub = 1;
  int q = 0, w = 0, e = 0;
  for (int i = 0; i < n; i++) {
    if (s[i][0] == s[i][1]) {
      if (s[i][0] == '?')
        e++, sub = sub * 2 % mod;
      else
        sub = 0;
    } else {
      if (s[i][0] == '?' || s[i][1] == '?') {
        if (s[i][0] == 'B') q++;
        if (s[i][0] == 'W') w++;
        if (s[i][1] == 'B') w++;
        if (s[i][1] == 'W') q++;
      } else {
        if (s[i][0] == 'B') q++;
        if (s[i][0] == 'W') w++;
      }
    }
  }
  ans = (ans - sub % mod + mod) % mod;
  if ((q == 0 || w == 0) && sub != 0) ans++;
  cout << ans % mod;
}
