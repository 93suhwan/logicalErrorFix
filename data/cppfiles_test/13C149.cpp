#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int a[n + 5][m + 5];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        a[i][j] = 0;
      }
    }
    int num1 = 0, num2 = 0, num = n * m / 2, t = 1;
    if (n % 2 == 0) {
      for (int i = 1; i + 1 <= m; i += 2) {
        for (int j = 1; j <= n; j++) {
          if (k == 0) {
            break;
            i = m + 1;
          } else {
            while (a[j - 1][i] == t || a[j - 1][i + 1] == t ||
                   a[j + 1][i] == t || a[j + 1][i + 1] == t ||
                   a[j][i - 1] == t || a[j][i + 2] == t)
              t = t % 26 + 1;
            a[j][i] = t;
            a[j][i + 1] = t;
            k--;
            num--;
          }
        }
      }
      for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
          if (a[i][j] == 0 && a[i + 1][j] == 0) {
            while (a[i - 1][j] == t || a[i + 2][j] == t ||
                   a[i + 1][j - 1] == t || a[i + 1][j + 1] == t ||
                   a[i][j - 1] == t || a[i][j + 1] == t)
              t = t % 26 + 1;
            a[i][j] = t;
            a[i + 1][j] = t;
            num--;
          }
        }
      }
      if (num <= 0 && k == 0) {
        puts("YES");
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= m; j++) {
            printf("%c", 'a' + a[i][j] - 1);
          }
          puts("");
        }
      } else
        puts("NO");
    } else {
      t = 1;
      for (int i = 1; i + 1 <= m; i += 2) {
        a[1][i] = t, a[1][i + 1] = t, k--, num--;
        t = t % 26 + 1;
      }
      for (int i = 1; i + 1 <= m; i += 2) {
        for (int j = 2; j <= n; j++) {
          if (k == 0) {
            break;
            i = m + 1;
          } else {
            while (a[j - 1][i] == t || a[j - 1][i + 1] == t ||
                   a[j + 1][i] == t || a[j + 1][i + 1] == t ||
                   a[j][i - 1] == t || a[j][i + 2] == t)
              t = t % 26 + 1;
            a[j][i] = t;
            a[j][i + 1] = t;
            k--;
            num--;
          }
        }
      }
      for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
          if (a[i][j] == 0 && a[i + 1][j] == 0) {
            while (a[i - 1][j] == t || a[i + 2][j] == t ||
                   a[i + 1][j - 1] == t || a[i + 1][j + 1] == t ||
                   a[i][j - 1] == t || a[i][j + 1] == t)
              t = t % 26 + 1;
            a[i][j] = t;
            a[i + 1][j] = t;
            num--;
          }
        }
      }
      if (num <= 0 && k == 0) {
        puts("YES");
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= m; j++) {
            printf("%c", 'a' + a[i][j] - 1);
          }
          puts("");
        }
      } else
        puts("NO");
    }
  }
}
