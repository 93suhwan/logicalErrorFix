#include <bits/stdc++.h>
using namespace std;
long long a, b, d[200001], q, w, e, st[200001][21], sum[200001][31],
    mod = 1000000007, pw[31], fac[200001], inv[200001], s[200001][31];
long long get(long long qq, long long ww) {
  long long lg = log2(ww - qq + 1);
  return min(st[qq][lg], st[ww - (1 << lg) + 1][lg]);
}
long long C(long long qq, long long ww) {
  return fac[qq] * inv[ww] % mod * inv[qq - ww] % mod;
}
long long pow_(long long qq, long long ww) {
  long long ee = 1;
  while (ww) {
    if (ww & 1) ee *= qq, ee %= mod;
    qq *= qq, qq %= mod;
    ww >>= 1;
  }
  return ee % mod;
}
int main() {
  scanf("%lld%lld", &a, &b);
  fac[0] = 1;
  for (int i = 1; i <= 200000; i++) fac[i] = fac[i - 1] * i % mod;
  inv[200000] = pow_(fac[200000], mod - 2);
  for (int i = 199999; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  for (int i = 1; i <= a; i++) {
    long long tt = 1;
    for (int j = 0; j <= 30; j++) {
      s[i][j] = s[i - 1][j] + tt;
      s[i][j] %= mod;
      tt *= i;
      tt %= mod;
    }
  }
  for (int i = 1; i <= a; i++) {
    scanf("%lld", &d[i]);
    st[i][0] = d[i];
    long long tt = d[i];
    for (int j = 1; j <= 30; j++) {
      sum[i][j] = sum[i - 1][j] + tt, sum[i][j] %= mod;
      tt *= d[i], tt %= mod;
    }
  }
  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j + (1 << i) - 1 <= a; j++)
      st[j][i] = min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
  }
  for (int i = 1; i <= b; i++) {
    scanf("%lld%lld%lld", &q, &w, &e);
    if (q == w) {
      printf("Yes\n");
      continue;
    }
    long long fl = 1;
    long long tt =
        (sum[w][1] - sum[q - 1][1] -
         ((w - q + 1) * (w - q) % mod * e % mod * pow_(2, mod - 2) % mod)) %
        mod * pow_(w - q + 1, mod - 2) % mod;
    long long su = 0;
    pw[0] = 1;
    for (int j = 1; j <= 2; j++) pw[j] = pw[j - 1] * tt % mod;
    for (int j = 2; j <= 2; j++) {
      su = pw[j] * (w - q + 1) % mod;
      long long yy = e;
      for (int k = 1; k <= j; k++) {
        su += pw[j - k] * C(j, k) % mod * yy % mod * s[w - q][k] % mod;
        su %= mod;
        yy *= e;
        yy %= mod;
      }
      if (su != (sum[w][j] - sum[q - 1][j] + mod) % mod) fl = 0;
      if (!fl) break;
    }
    if (fl) {
      printf("Yes\n");
      continue;
    }
    fl = 1;
    e = mod - e;
    tt = (sum[w][1] - sum[q - 1][1] -
          ((w - q + 1) * (w - q) % mod * e % mod * pow_(2, mod - 2) % mod)) %
         mod * pow_(w - q + 1, mod - 2) % mod;
    pw[0] = 1;
    for (int j = 1; j <= 2; j++) pw[j] = pw[j - 1] * tt % mod;
    for (int j = 2; j <= 2; j++) {
      su = pw[j] * (w - q + 1) % mod;
      long long yy = e;
      for (int k = 1; k <= j; k++) {
        su += pw[j - k] * C(j, k) % mod * yy % mod * s[w - q][k] % mod;
        su %= mod;
        yy *= e;
        yy %= mod;
      }
      if (su != (sum[w][j] - sum[q - 1][j] + mod) % mod) fl = 0;
      if (!fl) break;
    }
    if (fl)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
