#include <bits/stdc++.h>
using namespace std;
const int MAXN = 114514;
int m, n, t, k;
bool dp[105][105][5005];
char a[105][105];
int main() {
  scanf("%d", &t);
  for (int j = 0; j <= 100; j += 2) {
    for (int i = 1; i <= 100; i++) {
      if ((i * j) % 2 == 1) continue;
      int maxn = (i * j) / 2;
      int minn = (i % 2) * (j / 2);
      for (int l = maxn; l >= minn; l -= 2) {
        dp[i][j][l] = true;
        dp[i][j + 1][l] = true;
      }
    }
  }
  for (int q = 1; q <= t; q++) {
    scanf("%d%d%d", &n, &m, &k);
    if (dp[n][m][k]) {
      memset(a, 0, sizeof(a));
      printf("YES\n");
      int x = n, y = m, z = k;
      if (n % 2 == 1) {
        for (int j = 1; j <= m; j += 2) {
          if (((j + 1) / 2) % 2 == 1)
            a[n][j] = a[n][j + 1] = 'y';
          else
            a[n][j] = a[n][j + 1] = 'z';
          z--;
        }
        x = n - 1;
      }
      if (m % 2 == 1) {
        for (int i = 1; i <= n; i += 2) {
          if (((i + 1) / 2) % 2 == 1)
            a[i][m] = a[i + 1][m] = 'y';
          else
            a[i][m] = a[i + 1][m] = 'z';
        }
        y = m - 1;
      }
      char ch = 'a';
      for (int i = 1; i <= x; i += 2) {
        for (int j = 1; j <= y; j += 2) {
          if (z) {
            a[i][j] = a[i][j + 1] = ch++;
            if (ch == 'x') ch = 'a';
            a[i + 1][j] = a[i + 1][j + 1] = ch++;
            if (ch == 'x') ch = 'a';
            z -= 2;
          } else {
            a[i][j] = a[i + 1][j] = ch++;
            if (ch == 'x') ch = 'a';
            a[i][j + 1] = a[i + 1][j + 1] = ch++;
            if (ch == 'x') ch = 'a';
          }
        }
      }
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          putchar(a[i][j]);
        }
        putchar('\n');
      }
    } else
      printf("NO\n");
  }
  return 0;
}
