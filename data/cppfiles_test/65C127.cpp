#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
const int mod = 998244353;
int f[60][100010], g[100010], sum[60][100010];
int x[60], y[60], l[60], r[60], n, m;
int sol(int gcd) {
  for (int i = 1; i <= n; i++) r[i] = y[i] / gcd, l[i] = (x[i] - 1) / gcd + 1;
  for (int i = 1; i <= n; i++)
    if (l[i] > r[i]) return 0;
  for (int i = 0; i <= m / gcd; i++) sum[0][i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m / gcd; j++) sum[i][j] = 0;
    for (int j = l[i]; j <= m / gcd; j++) {
      int x = j - r[i] - 1 < 0 ? 0 : sum[i - 1][j - r[i] - 1];
      f[i][j] = (sum[i - 1][j - l[i]] - x + mod) % mod;
      sum[i][j] = sum[i][j - 1] + f[i][j];
      sum[i][j] %= mod;
    }
  }
  return sum[n][m / gcd];
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) x[i] = read(), y[i] = read();
  for (int i = 1; i <= m; i++) {
    g[i] = sol(i);
  }
  for (int i = m; i; i--) {
    for (int j = 2; j * i <= m; j++) g[i] = (g[i] - g[i * j] + mod) % mod;
  }
  printf("%d", g[1]);
}
