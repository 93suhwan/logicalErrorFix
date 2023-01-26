#include <bits/stdc++.h>
const int N = 105;
int f[N][N][N], n, m, q, Mod, C[N][N];
inline void Init() {
  scanf("%d %d %d %d", &n, &m, &q, &Mod);
  for (register int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (register int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
  }
  return;
}
inline int Dfs(const int i, const int j, const int k) {
  if (i < j) return 0;
  if (j * 2 > i + 1) return 0;
  if (f[i][j][k] != -1) return f[i][j][k];
  f[i][j][k] = 0;
  for (register int l = 0; l <= i - 1; l++)
    for (register int w = 0; w <= j - (k == m); w++)
      f[i][j][k] =
          (f[i][j][k] + 1ll * C[i - 1][l] * Dfs(l, w, k + 1) % Mod *
                            Dfs(i - l - 1, j - w - (k == m), k + 1) % Mod) %
          Mod;
  return f[i][j][k];
}
inline void Solve() {
  memset(f, -1, sizeof(f));
  memset(f[0], 0, sizeof(f[0]));
  memset(f[1], 0, sizeof(f[1]));
  for (register int k = 1; k <= n; k++) f[1][k == m][k] = f[0][0][k] = 1;
  printf("%d\n", Dfs(n, q, 1));
  return;
}
int main() {
  Init();
  Solve();
  return 0;
}
