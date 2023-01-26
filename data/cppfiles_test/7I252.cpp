#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x * f;
}
long long t, n;
long long a[200010];
long long c[200010][20];
long long lg[200010];
inline long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long ask(long long a, long long b) {
  long long lo = lg[b - a + 1];
  long long po = 1 << lo;
  return gcd(c[a][lo], c[b - po + 1][lo]);
}
bool check(long long r) {
  for (register long long i = 1; i <= n; ++i) {
    long long x = i, y = (i + r) - 1;
    if (y > n) break;
    if (ask(x, y) > 1) return 1;
  }
  return 0;
}
int main() {
  lg[0] = -1;
  for (register long long i = 1; i <= 200000; ++i) lg[i] = lg[i >> 1] + 1;
  t = rd();
  while (t--) {
    long long res = 0;
    n = rd();
    for (register long long i = 1; i <= n; ++i) a[i] = rd();
    for (register long long i = 1; i <= n; ++i) c[i][0] = (a[i] - a[i - 1]);
    for (long long i = 1; i <= lg[n]; i++)
      for (long long j = 1; j + (1 << i) - 1 <= n; j++) {
        long long po = 1 << (i - 1);
        c[j][i] = gcd(c[j][i - 1], c[j + po][i - 1]);
      }
    long long l = 1, r = n;
    while (l + 1 < r) {
      long long mid = (l + r) / 2;
      if (check(mid))
        l = mid;
      else
        r = mid;
    }
    printf("%lld\n", l + 1);
  }
  return 0;
}
