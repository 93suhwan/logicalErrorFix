#include <bits/stdc++.h>
using namespace std;
int n, m, k, mod, f[101][101][101], p[101][101], ss;
bool fl[101][101][101];
int add(int a, int b) {
  if (a + b >= mod) return a + b - mod;
  return a + b;
}
int del(int a, int b) {
  if (a - b < 0) return a - b + mod;
  return a - b;
}
int mul(int a, int b) { return ((int)(1ll * a * b % mod)); }
int dfs(int a, int b, int c) {
  if (fl[a][b][c]) return f[a][b][c];
  fl[a][b][c] = 1;
  if (b > m && c > 0) return 0;
  if (a < c) return 0;
  if (c != 0) {
    int s = m - b + 1, sc = c - 1;
    for (int i = 6; i >= 0; i--) {
      if (sc >= (1 << i)) {
        sc = sc - (1 << i);
        s = s + (1 << (i + 1)) - 1;
      }
    }
    if (s > a) return 0;
  }
  if (a == 0) {
    if (c == 0) {
      f[a][b][c] = 1;
      return 1;
    }
    return 0;
  }
  for (int i = 0; i < a; i++) {
    int len = c - ((int)(b == m));
    for (int j = 0; j <= len; j++) {
      f[a][b][c] = add(f[a][b][c],
                       mul(p[a - 1][i], mul(dfs(i, b + 1, j),
                                            dfs(a - i - 1, b + 1, len - j))));
    }
  }
  return f[a][b][c];
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &mod);
  p[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      p[i][j] = add(p[i - 1][j], p[i - 1][j - 1]);
    }
  }
  printf("%d\n", dfs(n, 1, k));
}
