#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
inline int inc(int x, int y) { return x += y - mod, x += x >> 31 & mod; }
inline int dec(int x, int y) { return x -= y, x += x >> 31 & mod; }
inline int mul(int x, int y) { return long long(x) * y % mod; }
inline int sed(int x, int y) { return y ? x & 1 ? mod - y : y : 0; }
int qpow(int a, int b) {
  b += b >> 31 & (mod - 1);
  int c = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) c = mul(a, c);
  }
  return c;
}
const int maxn = 2e5 + 5;
int T, n, k;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &k);
    int a = qpow(2, n);
    int A = qpow(a, k);
    int I = qpow(a, mod - 2);
    int c = 1;
    int s = 0;
    for (int i = int(0); i <= int(k - 1); i++) {
      int p = dec((mod + 1) / 2, (n & 1 ? I : 0));
      int q = n & 1 ? 0 : I;
      s = inc(s, mul(c, p));
      c = mul(c, dec(1, inc(p, q)));
    }
    printf("%d\n", mul(dec(1, s), A));
  }
  return 0;
}
