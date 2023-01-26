#include <bits/stdc++.h>
using namespace std;
char s[10 + 5];
const int mod = 998244353;
int jc[100000 + 5], jcn[100000 + 5];
int ksm(int a, int k) {
  int s = 1;
  while (k) {
    if (k & 1) s = 1ll * s * a % mod;
    k >>= 1;
    a = 1ll * a * a % mod;
  }
  return s;
}
int C(int x, int y) {
  if (x < y) return 0;
  return 1ll * jc[x] * jcn[y] % mod * jcn[x - y] % mod;
}
int main() {
  int T = 1, i;
  jc[0] = 1;
  for (i = 1; i <= 100000; i++) jc[i] = 1ll * jc[i - 1] * i % mod;
  jcn[100000] = ksm(jc[100000], mod - 2);
  for (i = 99999; i >= 0; i--) jcn[i] = 1ll * jcn[i + 1] * (i + 1) % mod;
  while (T--) {
    int n, lw = 0, lb = 0, rw = 0, rb = 0, bw = 0, wb = 0, ans = 0;
    bool flag = false;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%s", s + 1);
      if (s[1] == 'W') lw++;
      if (s[1] == 'B') lb++;
      if (s[2] == 'W') rw++;
      if (s[2] == 'B') rb++;
      if (s[1] == 'W' && s[2] == 'W') flag = true;
      if (s[1] == 'B' && s[2] == 'B') flag = true;
      if (s[1] == 'B' && s[2] == 'W') bw++;
      if (s[1] == 'W' && s[2] == 'B') wb++;
    }
    for (i = lw; i <= n - lb; i++) {
      if (i + rw > n) continue;
      if (i < rb) continue;
      ans =
          (ans + 1ll * C(n - rb - rw, i - rb) * C(n - lw - lb, i - lw) % mod) %
          mod;
    }
    if (!flag) {
      lw -= wb;
      rb -= wb;
      lb -= bw;
      rw -= bw;
      wb += lw;
      wb += rb;
      bw += lb;
      bw += rw;
      for (i = max(bw, 1); i <= min(n - wb, n - 1); i++)
        ans = (ans + mod - C(n - bw - wb, i - bw)) % mod;
    }
    printf("%d\n", ans);
  }
}
