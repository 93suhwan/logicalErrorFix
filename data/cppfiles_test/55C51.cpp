#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
const long long p = 1e9 + 7;
long long qp(long long x, long long y) {
  long long res = 1;
  for (long long t = x; y; y >>= 1, t = t * t % p)
    if (y & 1) res = res * t % p;
  return res;
}
signed main() {
  long long n = 1ll << read();
  --n, --n;
  printf("%lld\n", qp(4, n) * 6 % p);
  return 0;
}
