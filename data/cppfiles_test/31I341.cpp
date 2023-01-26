#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
long long t, n, a[MAX];
long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); };
int main() {
  long long i, j, f1, f2, g1, g2, gg;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) scanf("%lld", a + i);
    if (n % 2 == 0) {
      for (i = 1; i <= n; i += 2) {
        f1 = f2 = 0;
        g1 = g2 = 1;
        if (a[i] < 0) a[i] = -a[i], f1 = 1;
        if (a[i + 1] < 0) a[i + 1] = -a[i + 1], f2 = 1;
        gg = gcd(a[i], a[i + 1]);
        if (f1 ^ f2)
          printf("%lld %lld ", a[i + 1] * g1 / gg, a[i] * g2 / gg);
        else
          printf("%lld %lld ", -a[i + 1] * g1 / gg, a[i] * g2 / gg);
      }
      printf("\n");
    } else {
      for (i = 1; i <= n - 3; i += 2) {
        f1 = f2 = 0;
        g1 = g2 = 1;
        if (a[i] < 0) a[i] = -a[i], f1 = 1;
        if (a[i + 1] < 0) a[i + 1] = -a[i + 1], f2 = 1;
        gg = gcd(a[i], a[i + 1]);
        if (f1 ^ f2)
          printf("%lld %lld ", a[i + 1] * g1 / gg, a[i] * g2 / gg);
        else
          printf("%lld %lld ", -a[i + 1] * g1 / gg, a[i] * g2 / gg);
      }
      a[i + 1] += a[i];
      i++;
      f1 = f2 = 0;
      g1 = g2 = 1;
      if (a[i] < 0) a[i] = -a[i], f1 = 1;
      if (a[i + 1] < 0) a[i + 1] = -a[i + 1], f2 = 1;
      gg = gcd(a[i], a[i + 1]);
      if (f1 ^ f2)
        printf("%lld %lld %lld ", a[i + 1] * g1 / gg, a[i + 1] * g1 / gg,
               a[i] * g2 / gg);
      else
        printf("%lld %lld %lld ", -a[i + 1] * g1 / gg, -a[i + 1] * g1 / gg,
               a[i] * g2 / gg);
      printf("\n");
    }
  }
  return 0;
}
