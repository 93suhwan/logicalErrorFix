#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, t, res;
long long a[100500];
void chk(long long x, long long y, long long z) {
  long long sb, a, b, c = 1;
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() + 1);
  uniform_int_distribution<int> lim(-10000, 10000);
  while (1) {
    a = lim(rng);
    b = lim(rng);
    if ((a * x + b * y) % z) goto aaa;
    c = (-(a * x + b * y) / z);
    if (c && c >= -10000 && c <= 10000) {
      printf("%lld %lld %lld\n", a, b, c);
      return;
    }
  aaa:;
    a = lim(rng);
    c = lim(rng);
    if ((a * x + c * z) % y) goto bbb;
    b = (-(a * x + c * z) / y);
    if (b && b >= -10000 && b <= 10000) {
      printf("%lld %lld %lld\n", a, b, c);
      return;
    }
  bbb:;
    b = lim(rng);
    c = lim(rng);
    if ((b * y + c * z) % x) goto bbb;
    a = (-(a * y + c * z) / x);
    if (a && a >= -10000 && a <= 10000) {
      printf("%lld %ld %lld\n", a, b, c);
      return;
    }
  }
}
int main() {
  cin.tie(0);
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
    }
    if (!(n & 1)) {
      for (i = 1; i <= n; i++) {
        if (i & 1) {
          printf("%lld ", a[i + 1]);
        } else {
          printf("%lld ", -a[i - 1]);
        }
      }
      puts("");
      continue;
    } else {
      for (i = 1; i <= n - 3; i++) {
        if (i & 1) {
          printf("%lld ", a[i + 1]);
        } else {
          printf("%lld ", -a[i - 1]);
        }
      }
      chk(a[n - 2], a[n - 1], a[n]);
      puts("");
      continue;
    }
  }
}
