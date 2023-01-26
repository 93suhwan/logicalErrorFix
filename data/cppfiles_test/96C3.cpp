#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 50;
const long long mm = 998244353;
int n, m, T;
long long f[maxn][maxn], ans, sum = 1, a[maxn * 2], cnt, an[maxn * 2];
long long mi(long long x, long long y) {
  long long tot = 1;
  while (y) {
    if (y & 1) tot = tot * x % mm;
    x = x * x % mm;
    y = y >> 1;
  }
  return tot;
}
long long c(long long x, long long y) {
  return a[x] * an[y] % mm * an[x - y] % mm;
}
int main() {
  a[0] = 1;
  an[0] = 1;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= 1000; ++i)
    a[i] = a[i - 1] * i % mm, an[i] = mi(a[i], mm - 2);
  for (int i = 1; i <= m; ++i) f[1][i] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= i; ++j)
      for (int k = 1; k + i - 1 <= m; ++k) {
        f[i][k + i - 1] += f[j][k] * mi(i - 1, i - j) % mm * c(i, j) % mm;
        f[i][k + i - 1] %= mm;
      }
  }
  for (int i = 1; i <= m; ++i) ans = (ans + f[n][i]) % mm;
  for (int i = 1; i <= n; ++i) sum = sum * m % mm;
  printf("%lld\n", (sum - ans + mm) % mm);
  return 0;
}
