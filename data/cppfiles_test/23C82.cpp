#include <bits/stdc++.h>
long long read(long long x = 0, long long f = 0, char ch = getchar()) {
  while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
  while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
  return f ? -x : x;
}
const long long N = 1e6 + 5;
long long n, m, a[N];
std::vector<long long> solve(long long L, long long R) {
  std::vector<long long> res(R - L + 2, -1LL << 60);
  res[0] = 0;
  if (L > R) return res;
  long long pos = std::min_element(a + L, a + R + 1) - a;
  std::vector<long long> x = solve(L, pos - 1), y = solve(pos + 1, R);
  for (long long i = 0; i < x.size(); i++)
    for (long long j = 0; j < y.size(); j++) {
      res[i + j] = std::max(res[i + j], x[i] + y[j] - 2 * i * j * a[pos]);
      res[i + j + 1] = std::max(
          res[i + j + 1],
          x[i] + y[j] - (2 * (i + 1) * (j + 1) - 1) * a[pos] + m * a[pos]);
    }
  return res;
}
signed main() {
  n = read(), m = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  printf("%lld", solve(1, n)[m]);
  return 0;
}
