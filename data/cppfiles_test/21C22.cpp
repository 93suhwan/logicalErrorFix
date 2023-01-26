#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int n, m, k, p;
int f[MAXN][MAXN][MAXN], g[MAXN], C[MAXN][MAXN];
int lim[MAXN];
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &p);
  if (n == 1) {
    if (m == 1 && k == 1)
      printf("%d\n", 1 % p);
    else
      printf("0");
    return 0;
  }
  C[0][0] = 1;
  for (int i = (1); i <= (100); i++) {
    C[i][0] = 1;
    for (int j = (1); j <= (i); j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
    }
  }
  g[0] = 1;
  for (int i = (1); i <= (n); i++) {
    for (int j = (0); j <= (i - 1); j++) {
      g[i] = (g[i] + 1LL * C[i - 1][j] * g[j] % p * g[i - j - 1] % p) % p;
    }
  }
  lim[1] = 1;
  for (int i = (2); i <= (n); i++) {
    lim[i] = min(101, lim[i - 1] * 2);
  }
  for (int depth = (1); depth <= (m); depth++) f[0][0][depth] = 1;
  f[1][1][1] = 1;
  for (int depth = (2); depth <= (m); depth++) f[1][0][depth] = 1;
  for (int i = (2); i <= (n); i++) {
    f[i][1][1] = g[i];
    for (int cnt = (0); cnt <= (k); cnt++) {
      if (cnt > i) break;
      for (int depth = (2); depth <= (m); depth++) {
        if (cnt > lim[depth]) continue;
        if (cnt && cnt + depth - 1 > i) break;
        for (int a = (0); a <= (i - 1); a++)
          for (int b = (0); b <= (cnt); b++) {
            if (b > lim[depth - 1]) break;
            if (f[a][b][depth - 1] == 0) continue;
            if (f[i - 1 - a][cnt - b][depth - 1] == 0) continue;
            long long ret = C[i - 1][a];
            ret = ret * f[a][b][depth - 1] % p;
            ret = ret * f[i - 1 - a][cnt - b][depth - 1] % p;
            f[i][cnt][depth] += ret;
            if (f[i][cnt][depth] >= p) f[i][cnt][depth] -= p;
          }
      }
    }
  }
  printf("%d", f[n][k][m]);
  return 0;
}
