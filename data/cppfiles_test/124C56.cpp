#include <bits/stdc++.h>
using namespace std;
int T, n;
char a[3333], b[3333];
long long f[2005][4005];
long long g[2005][4005];
const int MOD = 1e9 + 7;
void sol() {
  scanf("%d%s%s", &n, a + 1, b + 1);
  for (int i = 0; i <= n; ++i)
    memset(f[i], 0, sizeof f[i]), memset(g[i], 0, sizeof g[i]);
  f[0][n] = 0;
  g[0][n] = 1;
  for (int i = 1; i <= n; ++i) {
    long long F, G;
    for (int j = 0; j <= n + n; ++j)
      if (G = g[i - 1][j]) {
        F = f[i - 1][j];
        for (int p = '0'; p <= '1'; ++p) {
          if (isdigit(a[i]) && p != a[i]) continue;
          for (int q = '0'; q <= '1'; ++q) {
            if (isdigit(b[i]) && q != b[i]) continue;
            int dt = 0;
            if (p != q) {
              dt += ((p ^ i) & 1) * 2 - 1;
            }
            (g[i][j + dt] += G) %= MOD;
            (f[i][j + dt] += F + abs(j - n) * G) %= MOD;
          }
        }
      }
  }
  long long ans = f[n][n];
  ans = (ans % MOD + MOD) % MOD;
  printf("%d\n", int(ans));
}
int main() {
  scanf("%d", &T);
  while (T--) sol();
}
