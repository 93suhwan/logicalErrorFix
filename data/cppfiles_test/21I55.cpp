#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
inline void Solve() {
  for (register int k = 1; k <= n; k++) f[1][k == m][k] = f[0][0][k] = 1;
  for (register int i = 2; i <= n; i++)
    for (register int j = 0; j <= q && j <= (i + 1) / 2; j++)
      for (register int k = i; k; k--)
        for (register int l = 0; l <= i - 1; l++)
          for (register int w = 0; w <= j - (k == m); w++)
            f[i][j][k] =
                (f[i][j][k] + 1ll * C[i - 1][l] * f[l][w][k + 1] % Mod *
                                  f[i - 1 - l][j - w - (k == m)][k + 1] % Mod) %
                Mod;
  printf("%d\n", f[n][q][1]);
  return;
}
int main() {
  Init();
  Solve();
  return 0;
}
