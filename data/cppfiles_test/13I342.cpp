#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char ans[N][N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(ans, '#', sizeof ans);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int mn = (n % 2 == 1 ? m / 2 : 0),
        mx = n * m / 2 - (m % 2 == 1 ? n / 2 : 0);
    if (mn <= k && k <= mx && (k - mn) % 2 == 0) {
      puts("YES");
      int cnt = 0;
      for (int j = 1; j + 1 <= m; j += 2) {
        if (cnt >= k) break;
        for (int i = 1; i <= n; ++i) {
          int _ = 0;
          while (1) {
            bool ok = 1;
            for (int dx = -1; dx <= 1; ++dx)
              for (int dy = -1; dy <= 1; ++dy) {
                if (ans[i + dx][j + dy] - 'a' == _) {
                  ++_;
                  ok = 0;
                }
              }
            if (ok) break;
          }
          ans[i][j] = ans[i][j + 1] = 'a' + _;
          if (++cnt == k) break;
        }
      }
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
          if (ans[i][j] != '#') continue;
          int _ = 0;
          while (1) {
            bool ok = 1;
            for (int dx = -1; dx <= 1; ++dx)
              for (int dy = -1; dy <= 1; ++dy) {
                if (ans[i + dx][j + dy] - 'a' == _) {
                  ++_;
                  ok = 0;
                }
              }
            if (ok) break;
          }
          ans[i][j] = ans[i + 1][j] = 'a' + _;
        }
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) printf("%c", ans[i][j]);
        puts("");
      }
    } else
      puts("NO");
  }
  return 0;
}
