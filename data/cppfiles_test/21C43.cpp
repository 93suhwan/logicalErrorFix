#include <bits/stdc++.h>
using namespace std;
int n, p, m, k, c[105][105];
long long f[105][105][105], fac[105];
inline long long dp(int x, int y, int z) {
  if (x <= z) return (y == 0) ? fac[x] : 0;
  if (x < y + z) return f[x][y][z] = 0;
  if (~f[x][y][z]) return f[x][y][z];
  long long res = 0;
  for (int i = 1; i <= x; i++)
    for (int j = 0; j <= i && j <= y; j++)
      (res += 1ll * dp(i - 1, j, z - 1) * dp(x - i, y - j, z - 1) % p *
              c[x - 1][i - 1]) %= p;
  return f[x][y][z] = res;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &p);
  memset(f, -1, sizeof(f));
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % p;
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p;
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) f[i][j][0] = (j == 1) * fac[i];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) f[0][i][j] = (i == 0);
  long long ans = dp(n, k, m - 1);
  printf("%lld", ans);
  return 0;
}
