#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
const int MOD = 998244353;
int C[N][N], pw[N][N];
int f[N][N], n, k;
bool vis[N][N];
void init(int m = 5e2 + 1) {
  for (int i = 0; i <= m; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
  }
  for (int i = 1; i <= m; i++) {
    pw[i][0] = 1;
    for (int j = 1; j <= m; j++) pw[i][j] = (long long)pw[i][j - 1] * i % MOD;
  }
}
int dp(int p, int x) {
  if (vis[p][x]) return f[p][x];
  vis[p][x] = 1;
  if (p > x)
    f[p][x] = pw[x][p];
  else {
    f[p][x] = pw[p - 1][p];
    for (int i = 0; i < p; i++)
      f[p][x] = (f[p][x] + (long long)C[p][i] * dp(p - i, x - p + 1) % MOD *
                               pw[p - 1][i] % MOD) %
                MOD;
  }
  return f[p][x];
}
int main() {
  init();
  scanf("%d%d", &n, &k);
  printf("%d\n", dp(n, k));
  return 0;
}
