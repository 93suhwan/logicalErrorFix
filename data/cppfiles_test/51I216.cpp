#include <bits/stdc++.h>
int nw[52], d[52], sz[52][52], fa[52];
bool bk[52][52];
int getv(int x) { return x == fa[x] ? x : fa[x] = getv(fa[x]); }
bool merge(int x, int y) {
  x = getv(x);
  y = getv(y);
  if (x == y) return false;
  fa[x] = y;
  return true;
}
int random(int n) {
  int he = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) bk[i][j] = 0;
    nw[i] = 0;
  }
  for (int i = 1; i < n; i++) he += sz[i][n], bk[i][n] = 1, nw[i] = 1;
  int ans = he;
  nw[n] = n - 1;
  double T = 50 * n;
  for (int s = 0; s < 10000; s++) {
    int od = he, oa, ob;
    while (1) {
      int a = rand() % (n - 1) + 1, b = rand() % (n - a) + a + 1;
      if (bk[a][b]) {
        bk[a][b] = false;
        oa = a;
        ob = b;
        nw[a] -= 1;
        nw[b] -= 1;
        he -= sz[a][b];
        break;
      }
    }
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (bk[i][j]) merge(i, j);
      }
    }
    int a, b;
    while (1) {
      a = rand() % (n - 1) + 1;
      b = rand() % (n - a) + a + 1;
      if (nw[a] < d[a] && nw[b] < d[b] && merge(a, b)) {
        he += sz[a][b];
        bk[a][b] = 1;
        nw[a] += 1;
        nw[b] += 1;
        break;
      }
    }
    if (he < ans) ans = he;
    if (he > od && rand() % 1000000000 >= exp((od - he) / T) * 1e9) {
      he = od;
      bk[a][b] = 0;
      bk[oa][ob] = 1;
      nw[a] -= 1;
      nw[b] -= 1;
      nw[oa] += 1;
      nw[ob] += 1;
    }
    T *= 0.995;
  }
  return ans;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i++) scanf("%d", &d[i]);
  for (int i = k + 1; i <= n; i++) d[i] = 1e9;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      scanf("%d", &sz[i][j]);
      sz[j][i] = sz[i][j];
    }
  }
  int ans = random(n);
  printf("%d", ans);
  return 0;
}
