#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 100005;
int n, x, y, a, b, jc[N], ans;
char s[10];
int ksm(int a, int k) {
  int ret = 1;
  while (k) {
    if (k & 1) ret = 1ll * ret * a % mod;
    a = 1ll * a * a % mod;
    k >>= 1;
  }
  return ret;
}
int C(int n, int m) {
  return 1ll * jc[n] * ksm(1ll * jc[n - m] * jc[m] % mod, mod - 2) % mod;
}
int main() {
  scanf("%d", &n);
  jc[0] = 1;
  bool f1 = 0, f2 = 0;
  for (int i = 1; i < N; ++i) jc[i] = 1ll * jc[i - 1] * i % mod;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s);
    if (s[0] == 'W') ++x;
    if (s[0] == '?') ++y;
    if (s[1] == 'B') ++a;
    if (s[1] == '?') ++b;
    if (s[0] == s[1] && s[0] != '?') f2 = 1;
    if (s[0] == 'W' && s[1] != 'W') f1 = 1;
    if (s[1] == 'B' && s[1] != 'B') f1 = 1;
  }
  for (int i = max(a, x); i <= min(x + y, a + b); ++i)
    (ans += 1ll * C(y, i - x) * C(b, i - a) % mod) %= mod;
  printf("%d", ans - (f1 && (!f2)));
  return 0;
}
