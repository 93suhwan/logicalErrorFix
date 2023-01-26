#include <bits/stdc++.h>
using namespace std;
const int mo = 998244353;
inline int read() {
  int x = 0, w = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    w |= ch == '-';
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return w ? -x : x;
}
int T, n, m, x;
int a[1000005];
int pre[2][1000005], suf[2][1000005];
int ok[1000005];
int l[1000005], r[1000005];
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &x);
      a[(i - 1) * m + j - 1] = x;
    }
  for (int i = 1; i <= n; i++) {
    pre[0][0] = 0x3f3f3f3f, pre[1][0] = 0;
    for (int j = 1; j <= m; j++) {
      pre[0][j] = min(pre[0][j - 1], a[(i - 1) * m + j - 1]);
      pre[1][j] = max(pre[1][j - 1], a[(i - 1) * m + j - 1]);
    }
    suf[0][m + 1] = 0x3f3f3f3f, suf[1][m + 1] = 0;
    for (int j = m; j >= 1; j--) {
      suf[0][j] = min(suf[0][j + 1], a[(i - 1) * m + j - 1]);
      suf[1][j] = max(suf[1][j + 1], a[(i - 1) * m + j - 1]);
    }
    for (int j = 1; j < m; j++) {
      ok[(i - 1) * m + j - 1] = -1;
      if (pre[0][j] > suf[1][j + 1]) {
        ok[(i - 1) * m + j - 1] = 0;
        l[(i - 1) * m + j - 1] = pre[0][j];
        r[(i - 1) * m + j - 1] = suf[1][j + 1];
      }
      if (pre[1][j] < suf[0][j + 1]) {
        ok[(i - 1) * m + j - 1] = 1;
        l[(i - 1) * m + j - 1] = pre[1][j];
        r[(i - 1) * m + j - 1] = suf[0][j + 1];
      }
    }
  }
  for (int i = 1; i < m; i++) {
    int flag = 1, lmn = 0x3f3f3f3f, lmx = 0, rmn = 0x3f3f3f3f, rmx = 0;
    for (int j = 1; j <= n; j++) {
      if (ok[(j - 1) * m + i - 1] == -1) flag = 0;
      if (ok[(j - 1) * m + i - 1] == 0) {
        lmn = min(lmn, l[(j - 1) * m + i - 1]);
        rmx = max(rmx, r[(j - 1) * m + i - 1]);
      } else {
        rmn = min(rmn, r[(j - 1) * m + i - 1]);
        lmx = max(lmx, l[(j - 1) * m + i - 1]);
      }
    }
    if (lmn <= rmx || lmx >= rmn) flag = 0;
    if (flag) {
      printf("YES\n");
      for (int j = 1; j <= n; j++) {
        if (ok[(j - 1) * m + i - 1])
          printf("B");
        else
          printf("R");
      }
      printf(" %d\n", i);
      return;
    }
  }
  printf("NO\n");
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
