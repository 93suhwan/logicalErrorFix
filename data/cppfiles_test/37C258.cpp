#include <bits/stdc++.h>
using namespace std;
long long a, b, c, T, an, o, h[500001], d[500001], v[500001], fac[1000001],
    inv[1000001], mod = 1000000007, gg, q, w, e;
string s, s1, s2;
struct p {
  long long q, w, e;
} l[1000001];
void add(long long qq, long long ww) {
  l[++o].q = ww;
  l[o].w = h[qq];
  h[qq] = o;
}
long long pow_(long long qq, long long ww) {
  long long ee = 1;
  while (ww) {
    if (ww & 1) ee = ee * qq % mod;
    qq *= qq;
    qq %= mod;
    ww >>= 1;
  }
  return ee % mod;
}
long long C(long long qq, long long ww) {
  return fac[qq] * inv[ww] % mod * inv[qq - ww] % mod;
}
void init() {
  fac[0] = 1;
  for (int i = 1; i <= 1000000; i++) fac[i] = fac[i - 1] * i % mod;
  inv[1000000] = pow_(fac[1000000], mod - 2);
  for (int i = 999999; i >= 0; i--) inv[i] = inv[i] * (i + 1) % mod;
}
int main() {
  init();
  scanf("%lld", &T);
  for (int ii = 1; ii <= T; ii++) {
    an = 0;
    scanf("%lld%lld", &a, &b);
    for (int i = 1; i <= a; i++) v[i] = 0;
    for (int i = 1; i <= b; i++) {
      scanf("%lld%lld%lld", &q, &w, &e);
      v[w] = 1;
    }
    long long ff = 0;
    for (int i = 1; i <= a; i++) {
      if (!v[i]) ff = i;
    }
    for (int i = 1; i <= a; i++) {
      if (ff == i) continue;
      printf("%d %lld\n", i, ff);
    }
  }
  return 0;
}
