#include <bits/stdc++.h>
int min(int a, int b) { return a < b ? a : b; }
int color(int m, int i, int j) {
  int c = ((i / m) + (j / m)) % 2;
  i %= m, j %= m;
  return min(min(i, m - 1 - i), min(j, m - 1 - j)) % 2 ^ c;
}
int main() {
  static char cc[2000][2000 + 1];
  int n, m, m_, i, j;
  scanf("%d", &n);
  if (n % 2 != 0) {
    printf("NONE\n");
    return 0;
  }
  for (i = 0; i < n; i++) scanf("%s", cc[i]);
  m_ = -1;
  for (m = 2; m <= n; m += 2)
    if (n % m == 0) {
      int c_ = -1;
      for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
          if (cc[i][j] != '.') {
            int c = (cc[i][j] == 'S') == color(m, i, j);
            if (c_ == -1)
              c_ = c;
            else if (c_ != c) {
              c_ = -2;
              goto out;
            }
          }
    out:
      if (c_ == -1) {
        printf("MULTIPLE\n");
        return 0;
      }
      if (c_ != -2) {
        if (m_ != -1) {
          printf("MULTIPLE\n");
          return 0;
        }
        m_ = m;
      }
    }
  if (m_ == -1)
    printf("NONE\n");
  else {
    int c;
    printf("UNIQUE\n");
    c = -1;
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        if (cc[i][j] != '.') {
          c = (cc[i][j] == 'S') == color(m_, i, j);
          goto out_;
        }
  out_:
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) cc[i][j] = (color(m_, i, j) ^ c) ? 'G' : 'S';
    for (i = 0; i < n; i++) printf("%s\n", cc[i]);
  }
  return 0;
}
