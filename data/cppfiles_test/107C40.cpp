#include <bits/stdc++.h>
using namespace std;
inline long long readint() {
  long long x = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f ? -x : x;
}
const int maxn = 200 + 5;
int n, k, x[maxn], y[maxn];
long long S(int a, int b, int c) {
  return abs(1ll * (x[b] - x[a]) * (y[c] - y[a]) -
             1ll * (x[c] - x[a]) * (y[b] - y[a]));
}
int f[maxn][maxn];
long long g[maxn][maxn];
int main() {
  n = readint();
  k = readint();
  for (int i = 1; i <= n; i++) {
    x[i] = readint();
    y[i] = readint();
  }
  long long l = 0, r = 8e16;
  while (l < r) {
    long long mid = l + (r - l + 1) / 2;
    for (int i = n; i > 0; i--)
      for (int j = i + 1; j <= n; j++) {
        f[i][j] = 0;
        g[i][j] = 0;
        for (int k = i + 1; k < j; k++) g[i][j] += S(j, k, k - 1);
        auto upd = [i, j](int f2, long long g2) {
          if (f2 > f[i][j] || (f2 == f[i][j] && g2 > g[i][j])) {
            f[i][j] = f2;
            g[i][j] = g2;
          }
        };
        for (int k = i + 1; k < j; k++)
          if (S(i, j, k) + g[i][k] + g[k][j] >= mid)
            upd(f[i][k] + f[k][j] + 1, 0);
          else
            upd(f[i][k] + f[k][j], S(i, j, k) + g[i][k] + g[k][j]);
      }
    if (f[1][n] >= k + 1)
      l = mid;
    else
      r = mid - 1;
  }
  printf("%lld\n", r);
  return 0;
}
