#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
char a[105][105];
int main() {
  int t, n, m, k, i, j;
  scanf("%d", &t);
  while (t--) {
    int f = 0;
    scanf("%d%d%d", &n, &m, &k);
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0) {
        printf("YES\n");
        for (i = 1; i <= n; i += 2) {
          for (j = 1; j <= m; j += 2) {
            char aa = 'a' + (i + j) % 26;
            char bb = 'a' + (i + j + 1) % 26;
            if (k > 0) {
              a[i][j] = aa;
              a[i][j + 1] = aa;
              a[i + 1][j] = bb;
              a[i + 1][j + 1] = bb;
            } else {
              a[i][j] = aa;
              a[i][j + 1] = bb;
              a[i + 1][j] = aa;
              a[i + 1][j + 1] = bb;
            }
            k -= 2;
          }
        }
        for (i = 1; i <= n; i++) {
          for (j = 1; j <= m; j++) {
            printf("%c", a[i][j]);
          }
          printf("\n");
        }
      } else
        printf("NO\n");
    } else if (n % 2 == 1 && m % 2 == 0) {
      int x = m, y = n;
      int kk = (x * y) / 2 - k;
      if (kk <= x * (y / 2) && kk % 2 == 0) {
        printf("YES\n");
        k = kk;
        for (i = 1; i <= x; i += 2) {
          for (j = 1; j <= y - 1; j += 2) {
            char aa = 'a' + (i + j) % 26;
            char bb = 'a' + (i + j + 1) % 26;
            if (k > 0) {
              a[i][j] = aa;
              a[i][j + 1] = aa;
              a[i + 1][j] = bb;
              a[i + 1][j + 1] = bb;
            } else {
              a[i][j] = aa;
              a[i][j + 1] = bb;
              a[i + 1][j] = aa;
              a[i + 1][j + 1] = bb;
            }
            k -= 2;
          }
        }
        for (i = 1; i <= x; i += 2) {
          char aa = 'a' + (i + j) % 26;
          a[i][y] = aa;
          a[i + 1][y] = aa;
        }
        for (i = 1; i <= y; i++) {
          for (j = 1; j <= x; j++) {
            printf("%c", a[j][i]);
          }
          printf("\n");
        }
      } else
        printf("NO\n");
    } else {
      if (k <= n * (m / 2)) {
        if (k % 2 == 0) {
          printf("YES\n");
          for (i = 1; i <= n; i += 2) {
            for (j = 1; j <= m - 1; j += 2) {
              char aa = 'a' + (i + j) % 26;
              char bb = 'a' + (i + j + 1) % 26;
              if (k > 0) {
                a[i][j] = aa;
                a[i][j + 1] = aa;
                a[i + 1][j] = bb;
                a[i + 1][j + 1] = bb;
              } else {
                a[i][j] = aa;
                a[i][j + 1] = bb;
                a[i + 1][j] = aa;
                a[i + 1][j + 1] = bb;
              }
              k -= 2;
            }
          }
          for (i = 1; i <= n; i += 2) {
            char aa = 'a' + (i + j) % 26;
            a[i][m] = aa;
            a[i + 1][m] = aa;
          }
          for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
              printf("%c", a[i][j]);
            }
            printf("\n");
          }
        } else
          printf("NO\n");
      } else
        printf("NO\n");
    }
  }
  return 0;
}
