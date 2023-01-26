#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char s[N][N];
int L[N][N], R[N][N], st[N][N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) L[i][j] = R[i][j] = st[i][j] = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        if (s[i][j] != '*') continue;
        L[i][j] = L[i - 1][j - 1] + 1;
        R[i][j] = R[i - 1][j + 1] + 1;
      }
    for (int d = k; d <= n; ++d) {
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
          if (min(L[i][j], R[i][j]) - 1 < d) continue;
          int ci = i, cj = j;
          for (int _ = 0; _ <= d; ++_) {
            st[ci][cj] = 1;
            --ci;
            --cj;
          }
          ci = i;
          cj = j;
          for (int _ = 0; _ <= d; ++_) {
            st[ci][cj] = 1;
            --ci;
            ++cj;
          }
        }
    }
    bool ok = 1;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (s[i][j] == '*' && !st[i][j]) ok = 0;
    if (ok)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
