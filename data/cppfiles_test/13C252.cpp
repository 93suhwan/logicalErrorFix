#include <bits/stdc++.h>
int t, n, m, k;
char res[106][106];
int main() {
  for (scanf("%d", &t); t--;) {
    scanf("%d%d%d", &n, &m, &k);
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0) {
        puts("YES");
        int cnt = 0;
        for (int i = 0; i < n; i += 2)
          for (int j = 0; j < m; j += 2) {
            if (cnt < k) {
              cnt += 2;
              res[i][j] = res[i][j + 1] = (i / 2 % 2 ^ j / 2 % 2 ? 'a' : 'c');
              res[i + 1][j] = res[i + 1][j + 1] =
                  (i / 2 % 2 ^ j / 2 % 2 ? 'b' : 'd');
            } else {
              res[i][j] = res[i + 1][j] = (i / 2 % 2 ^ j / 2 % 2 ? 'a' : 'c');
              res[i][j + 1] = res[i + 1][j + 1] =
                  (i / 2 % 2 ^ j / 2 % 2 ? 'b' : 'd');
            }
          }
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) printf("%c", res[i][j]);
          puts("");
        }
      } else
        puts("NO");
    }
    if (n % 2 == 0 && m % 2 == 1) {
      if (k <= n * (m - 1) / 2 && k % 2 == n * (m - 1) / 2 % 2) {
        puts("YES");
        int cnt = 0;
        for (int i = 0; i < n; i += 2)
          res[i][m - 1] = res[i + 1][m - 1] = (i / 2 % 2 ? 'e' : 'f');
        for (int i = 0; i < n; i += 2)
          for (int j = 0; j < m - 1; j += 2) {
            if (cnt < k) {
              cnt += 2;
              res[i][j] = res[i][j + 1] = (i / 2 % 2 ^ j / 2 % 2 ? 'a' : 'c');
              res[i + 1][j] = res[i + 1][j + 1] =
                  (i / 2 % 2 ^ j / 2 % 2 ? 'b' : 'd');
            } else {
              res[i][j] = res[i + 1][j] = (i / 2 % 2 ^ j / 2 % 2 ? 'a' : 'c');
              res[i][j + 1] = res[i + 1][j + 1] =
                  (i / 2 % 2 ^ j / 2 % 2 ? 'b' : 'd');
            }
          }
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) printf("%c", res[i][j]);
          puts("");
        }
      } else
        puts("NO");
    }
    if (n % 2 == 1 && m % 2 == 0) {
      if (n * m / 2 - k <= (n - 1) * m / 2 && k % 2 == m / 2 % 2) {
        puts("YES");
        int cnt = 0;
        for (int j = 0; j < m; j += 2)
          res[n - 1][j] = res[n - 1][j + 1] = (j / 2 % 2 ? 'e' : 'f'), cnt++;
        for (int i = 0; i < n - 1; i += 2)
          for (int j = 0; j < m - 1; j += 2) {
            if (cnt < k) {
              cnt += 2;
              res[i][j] = res[i][j + 1] = (i / 2 % 2 ^ j / 2 % 2 ? 'a' : 'c');
              res[i + 1][j] = res[i + 1][j + 1] =
                  (i / 2 % 2 ^ j / 2 % 2 ? 'b' : 'd');
            } else {
              res[i][j] = res[i + 1][j] = (i / 2 % 2 ^ j / 2 % 2 ? 'a' : 'c');
              res[i][j + 1] = res[i + 1][j + 1] =
                  (i / 2 % 2 ^ j / 2 % 2 ? 'b' : 'd');
            }
          }
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) printf("%c", res[i][j]);
          puts("");
        }
      } else
        puts("NO");
    }
  }
}
