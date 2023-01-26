#include <bits/stdc++.h>
using namespace std;
int t, n, m, k;
char ans[111][111];
bool check(int x, int y) { return y >= x && (y - x) % 2 == 0; }
int main() {
  for (cin >> t; t; --t) {
    cin >> n >> m >> k;
    if (!check(n % 2 ? m / 2 : 0, k) ||
        !check(m % 2 ? n / 2 : 0, n * m / 2 - k)) {
      puts("NO");
      continue;
    }
    if (n % 2) {
      for (int j = 2; j <= m; j += 2) {
        if ((j - 1) % 4 <= 2) {
          ans[n][j - 1] = 'i';
          ans[n][j] = 'i';
        } else {
          ans[n][j - 1] = 'j';
          ans[n][j] = 'j';
        }
        --k;
      }
    }
    if (m % 2) {
      for (int i = 2; i <= n; i += 2) {
        if ((i - 1) % 4 <= 2) {
          ans[i - 1][m] = 'i';
          ans[i][m] = 'i';
        } else {
          ans[i - 1][m] = 'j';
          ans[i][m] = 'j';
        }
      }
    }
    for (int j = 2; j <= m; j += 2) {
      for (int i = 2; i <= n; i += 2) {
        if (k) {
          if ((j - 1) % 4 <= 2) {
            ans[i - 1][j - 1] = 'a';
            ans[i - 1][j] = 'a';
            ans[i][j - 1] = 'b';
            ans[i][j] = 'b';
          } else {
            ans[i - 1][j - 1] = 'c';
            ans[i - 1][j] = 'c';
            ans[i][j - 1] = 'd';
            ans[i][j] = 'd';
          }
          k -= 2;
        } else {
          if ((i - 1) % 4 <= 2) {
            ans[i - 1][j - 1] = 'e';
            ans[i][j - 1] = 'e';
            ans[i - 1][j] = 'f';
            ans[i][j] = 'f';
          } else {
            ans[i - 1][j - 1] = 'g';
            ans[i][j - 1] = 'g';
            ans[i - 1][j] = 'h';
            ans[i][j] = 'h';
          }
        }
      }
    }
    puts("YES");
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        putchar(ans[i][j]);
      }
      putchar('\n');
    }
  }
  return 0;
}
