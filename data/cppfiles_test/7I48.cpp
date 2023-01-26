#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 7, M = 2e3 + 1;
const int MOD = 1e9 + 7;
const int oo = 1e9 + 7;
int n, m, k, t;
int _dp[N][N][N];
int nxt[N][2];
int a[N][2];
void upd(int &a, int b) { a = min(a, b); }
signed main() {
  scanf("%d%d\n", &n, &m);
  char s[n + 1], t[m + 1];
  scanf("%s\n%s", &s, &t);
  for (int i = 1; i <= n; i++) {
    a[i][0] = s[i - 1] - '0';
  }
  for (int i = 1; i <= m; i++) {
    a[i][1] = t[i - 1] - '0';
  }
  k = n - m + 2;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int l = 0; l <= k; l++) {
        _dp[i][j][l] = oo;
      }
    }
  }
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j < 2; j++) {
      nxt[i][j] = 0;
      for (int l = min(i + 1, m); l > 0; l--) {
        if (j != a[l][1]) continue;
        bool ok = 1;
        for (int p = l - 1; p > 0; p--) {
          if (a[i - l + 1 + p][1] != a[p][1]) {
            ok = 0;
            break;
          }
        }
        if (ok) {
          nxt[i][j] = l;
          break;
        }
      }
    }
  }
  int nw = 0;
  for (int l = m - 1; l > 0; l--) {
    if (a[m][1] != a[l][1]) continue;
    bool ok = 1;
    for (int p = l - 1; p > 0; p--) {
      if (a[m - l + 1 + p][1] != a[p][1]) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      nw = l;
      break;
    }
  }
  _dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int l = 0; l <= k; l++) {
        if (_dp[i][j][l] == oo) continue;
        int d1 = nxt[j][a[i + 1][0]];
        int d2 = nxt[j][1 - a[i + 1][0]];
        bool t1 = (d1 == m), t2 = (d2 == m);
        if (t1) d1 = nw;
        if (t2) d2 = nw;
        upd(_dp[i + 1][d1][l + t1], _dp[i][j][l]);
        upd(_dp[i + 1][d2][l + t2], _dp[i][j][l] + 1);
      }
    }
  }
  for (int l = 0; l <= k; l++) {
    int ans = oo;
    for (int i = 0; i <= m; i++) {
      upd(ans, _dp[n][i][l]);
    }
    if (ans == oo) ans = -1;
    printf("%d ", ans);
  }
  return 0;
}
