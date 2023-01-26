#include <bits/stdc++.h>
int min(int a, int b) { return a < b ? a : b; }
int main() {
  static char cc[2000][2000 + 1], cc_[2000 / 2];
  int n, i, j, k, c;
  scanf("%d", &n);
  if (n % 2 != 0) {
    printf("NONE\n");
    return 0;
  }
  for (i = 0; i < n; i++) scanf("%s", cc[i]);
  memset(cc_, -1, (n / 2) * sizeof *cc_);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (cc[i][j] != '.') {
        c = cc[i][j] == 'G' ? 0 : 1;
        if ((i + j) % 2 == 0) {
          if (i + j <= n - 2)
            c ^= j % 2, k = (i + j) / 2;
          else
            c ^= (n - 1 - i) % 2, k = ((n - 1) * 2 - (i + j)) / 2;
        } else {
          if (i > j)
            c ^= j % 2, k = (i - j) / 2;
          else
            c ^= i % 2, k = (j - i) / 2;
        }
        if (cc_[k] == -1)
          cc_[k] = c;
        else if (cc_[k] != c) {
          printf("NONE\n");
          return 0;
        }
      }
  for (i = 0; i < n; i++)
    if (cc_[i] == -1) {
      printf("MULTIPLE\n");
      return 0;
    }
  printf("UNIQUE\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      c = 0;
      if ((i + j) % 2 == 0) {
        if (i + j <= n - 2)
          c ^= j % 2, k = (i + j) / 2;
        else
          c ^= (n - 1 - i) % 2, k = ((n - 1) * 2 - (i + j)) / 2;
      } else {
        if (i > j)
          c ^= j % 2, k = (i - j) / 2;
        else
          c ^= i % 2, k = (j - i) / 2;
      }
      cc[i][j] = (c ^ cc_[k]) == 0 ? 'G' : 'S';
    }
  for (i = 0; i < n; i++) printf("%s\n", cc[i]);
  return 0;
}
