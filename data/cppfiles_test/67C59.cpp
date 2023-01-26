#include <bits/stdc++.h>
long long p0, p1, p2, p3, l, r, m, n, ans;
double p, c;
int check(long long x) {
  long long a = x, b = n - x;
  p0 = a * (a - 1) * (a - 2);
  p1 = a * (a - 1) * b;
  p2 = a * b * (b - 1);
  p3 = b * (b - 1) * (b - 2);
  if (2 * p0 + 6 * p1 + 3 * p2 >= c)
    return 1;
  else
    return 0;
}
int main() {
  scanf("%lld%lf", &n, &p);
  c = p * 2 * n * (n - 1) * (n - 2);
  l = 0;
  r = n;
  while (l <= r) {
    m = l + r >> 1;
    if (check(m))
      ans = m, r = m - 1;
    else
      l = m + 1;
  }
  printf("%lld\n", ans);
}
