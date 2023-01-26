#include <bits/stdc++.h>
using namespace std;
long long a, b, T, d[1000001], v[1000001], o, h[1000001],
    mod = 998244353, fac[1000001], inv[1000001];
string s;
struct p {
  long long q, w;
} l[2000001];
void add(long long qq, long long ww) {
  o++;
  l[o].q = ww;
  l[o].w = h[qq];
  h[qq] = o;
}
long long pow_(long long qq, long long ww) {
  long long ee = 1;
  while (ww) {
    if (ww & 1) {
      ee *= qq;
      ee %= mod;
    }
    ww >>= 1;
    qq *= qq;
    qq %= mod;
  }
  return ee % mod;
}
long long C(long long qq, long long ww) {
  return fac[qq] * inv[ww] % mod * inv[qq - ww] % mod;
}
bool ch(long long qq) {
  for (int i = 2; i <= sqrt(qq); i++) {
    if (qq % i == 0) return 0;
  }
  return 1;
}
long long an = 0;
int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= 1000000; i++) {
    fac[i] = fac[i - 1] * i % mod;
    inv[i] = pow_(fac[i], mod - 2);
  }
  T = 1;
  for (int i = 2; i <= 100000; i++) {
    if (ch(i)) {
      v[i] = 1;
    }
  }
  scanf("%lld", &T);
  for (int ii = 1; ii <= T; ii++) {
    an = 0;
    scanf("%lld", &a);
    cin >> s;
    bool fl = 0;
    for (int i = 0; i < a; i++) {
      if (!v[s[i] - '0']) {
        an = s[i] - '0';
        fl = 1;
        break;
      }
    }
    if (fl) {
      printf("1\n%lld\n", an);
      continue;
    }
    for (int i = 0; i < a; i++) {
      for (int j = i + 1; j < a; j++) {
        long long tt = (s[i] - '0') * 10 + s[j] - '0';
        if (!v[tt]) {
          fl = 1;
          an = tt;
          break;
        }
      }
      if (fl) break;
    }
    if (fl) {
      printf("2\n%lld\n", an);
      continue;
    }
    for (int i = 0; i < a; i++) {
      for (int j = i + 1; j < a; j++) {
        for (int k = j + 1; k < a; k++) {
          long long tt = (s[i] - '0') * 100 + (s[j] - '0') * 10 + s[k] - '0';
          if (!v[tt]) {
            fl = 1;
            an = tt;
            break;
          }
        }
        if (fl) break;
      }
      if (fl) break;
    }
    printf("3\n%lld\n", an);
  }
  return 0;
}
