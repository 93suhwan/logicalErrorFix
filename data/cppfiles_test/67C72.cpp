#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
inline long long read() {
  long long s = 0, w = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}
long long n;
double P;
inline long long S3(long long x) { return x * (x - 1) * (x - 2) / 6; }
inline long long S2(long long x) { return x * (x - 1) / 2; }
signed main() {
  scanf("%lld%lf", &n, &P);
  P = 1 - P;
  for (register long long i = 0; i <= n; i++) {
    if ((1.0 * S3(n - i) + 0.5 * S2(n - i) * i) / S3(n) <= P)
      return printf("%lld\n", i) & 0;
  }
  return 0;
}
