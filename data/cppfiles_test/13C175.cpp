#include <bits/stdc++.h>
using namespace std;
int qr() {
  char ch = getchar();
  int s = 0;
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s;
}
int T, n, m, k, nn, nm, tmp;
char ans[102][102];
int main() {
  T = qr();
  while (T--) {
    nn = n = qr();
    nm = m = qr();
    k = qr();
    if (m & 1) nm--;
    if (n & 1) {
      nn--;
      k -= (m >> 1);
    }
    if (k >= 0 && (k << 1) <= nn * nm && (k & 1) == 0) {
      printf("YES\n");
      tmp = 1;
      if (m & 1)
        for (int i = 1; i <= n >> 1; i++)
          ans[i * 2 - 1][m] = ans[i << 1][m] = 'a' + (i & 1);
      if (n & 1)
        for (int i = 1; i <= m >> 1; i++)
          ans[n][i * 2 - 1] = ans[n][i << 1] = 'a' + (i & 1);
      for (int i = 1; i <= nn >> 1; i++)
        for (int j = 1; j <= nm >> 1; j++) {
          if (tmp <= k >> 1) {
            tmp++;
            ans[i * 2 - 1][j * 2 - 1] = ans[i * 2 - 1][j << 1] = 'g' + (j & 1);
            ans[i << 1][j * 2 - 1] = ans[i << 1][j << 1] = 'i' + (j & 1);
          } else {
            ans[i * 2 - 1][j * 2 - 1] = ans[i << 1][j * 2 - 1] = 'c' + (i & 1);
            ans[i * 2 - 1][j << 1] = ans[i << 1][j << 1] = 'e' + (i & 1);
          }
        }
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) printf("%c", ans[i][j]);
        printf("\n");
      }
    } else
      printf("NO\n");
  }
  return 0;
}
