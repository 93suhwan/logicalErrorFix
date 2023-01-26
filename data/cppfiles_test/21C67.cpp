#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, k, P, c[N][N], jc[N], f[N][N][N];
int M(int x) {
  if (x >= P) x -= P;
  return x;
}
int F(int u, int v, int w) {
  if (~f[u][v][w]) return f[u][v][w];
  int &r = f[u][v][w];
  r = 0;
  if (!u && !w) return r = 1;
  if (w && w + w - 1 > u) return 0;
  if (v < 7 && (1 << v) < w) return 0;
  if (v == 1) {
    if (w == 1)
      r = jc[u];
    else
      r = 0;
    return r;
  }
  for (int x = 0, i; x < u; x++) {
    i = 0;
    for (int y = 0; y <= w; y++)
      i = M(1ll * F(x, v - 1, y) * F(u - 1 - x, v - 1, w - y) % P + i);
    r = M(r + 1ll * c[u - 1][x] * i % P);
  }
  return r;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &P);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++) f[i][j][k] = -1;
  c[0][0] = jc[0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1;
    jc[i] = 1ll * i * jc[i - 1] % P;
    for (int j = 1; j <= i; j++) c[i][j] = M(c[i - 1][j - 1] + c[i - 1][j]);
  }
  printf("%d\n", F(n, m, k));
  return 0;
}
