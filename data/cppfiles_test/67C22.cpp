#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const double eps = 1e-9;
int sgn(double x) {
  if (fabs(x) < eps) return 0;
  if (x < 0) return -1;
  return 1;
}
long long C(long long n, long long m) {
  if (n < m || m < 0) return 0;
  long long fenzi = 1, fenmu = 1;
  for (int i = 0; i < m; i++) {
    fenzi *= (n - i);
    fenmu *= i + 1;
  }
  return fenzi / fenmu;
}
double get(long long x, long long n) {
  double a, b, c, d;
  a = 0;
  b = 1.0 * C(n - x, 2) * C(x, 1) / C(n, 3) / 2;
  c = 1.0 * C(n - x, 1) * C(x, 2) / C(n, 3);
  d = 1.0 * C(x, 3) / C(n, 3);
  return a + b + c + d;
}
int main() {
  long long n;
  double p;
  scanf("%lld%lf", &n, &p);
  long long x;
  for (x = 0; x <= n; x++) {
    if (sgn(get(x, n) - p) >= 0) break;
  }
  printf("%lld\n", x);
  return 0;
}
