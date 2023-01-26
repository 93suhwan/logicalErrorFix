#include <bits/stdc++.h>
using namespace std;
long long max(long long x, long long y) { return x > y ? x : y; }
long long min(long long x, long long y) { return x > y ? y : x; }
inline long long read() {
  long long a = 0;
  long long f = 0;
  char p = getchar();
  while (!isdigit(p)) {
    f |= p == '-';
    p = getchar();
  }
  while (isdigit(p)) {
    a = (a << 3) + (a << 1) + (p ^ 48);
    p = getchar();
  }
  return f ? -a : a;
}
inline void print(long long x) {
  if (!x) return;
  if (x) print(x / 10);
  putchar(x % 10 + '0');
}
long long T, n, a[1000010];
signed main() {
  T = read();
  while (T--) {
    n = read();
    long long ans = -1;
    for (long long i = 1; i <= n; ++i) a[i] = read();
    for (long long i = 1; i <= n; ++i) {
      long long x = a[i];
      for (long long j = 1; j <= n; ++j) {
        if (i == j) continue;
        x &= a[j];
      }
      ans = max(ans, x);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
