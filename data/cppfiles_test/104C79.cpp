#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 9;
const long long MOD = 1e9 + 7;
const int mod = 998244353;
inline long long qpow(long long b, long long e, long long m) {
  long long a = 1;
  for (; e; e >>= 1, b = b * b % m)
    if (e & 1) a = a * b % m;
  return a;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, x, y);
  long long z = x;
  x = y, y = z - y * (a / b);
  return d;
}
int a[maxn], b[maxn], aa[maxn], bb[maxn];
int main() {
  int _;
  scanf("%d", &_);
  while (_--) {
    int n, m;
    scanf("%d%d", &n, &m);
    long long B = 0, A = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &a[i], &b[i]);
      A += a[i] - b[i];
      long long tm = min(m, a[i]);
      B += tm - (m - tm);
    }
    for (int i = 1; i <= n; i++) {
      long long tm = min(a[i], m);
      if (B > A) {
        if ((min(m, b[i]) - (m - tm)) * 2 <= B - A) {
          bb[i] = min(m, b[i]);
          aa[i] = m - bb[i];
          B -= (min(m, b[i]) - (m - tm)) * 2;
        } else {
          long long orz = (B - A + 1) / 2;
          bb[i] = (m - tm) + orz;
          aa[i] = m - bb[i];
          B -= orz * 2;
        }
      } else {
        aa[i] = tm, bb[i] = m - tm;
      }
    }
    printf("%lld\n", abs(B - A));
    for (int i = 1; i <= n; i++) {
      printf("%d %d\n", aa[i], bb[i]);
    }
  }
}
