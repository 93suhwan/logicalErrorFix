#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000006;
const int INF = 0x3f3f3f3f;
template <typename T>
inline void read(T &WOW) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  WOW = flag * x;
}
int n, p[MAXN], ans[MAXN];
;
int dp[MAXN][2][2];
pair<int, int> from[MAXN][2][2];
void solve() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(p[i]);
    ans[i] = p[i];
  }
  dp[1][0][0] = dp[1][1][0] = -INF;
  dp[1][0][1] = dp[1][1][1] = INF;
  for (int i = 2; i <= n; ++i) {
    dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = INF;
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        int mx = dp[i - 1][j][k];
        if (mx == INF) continue;
        int mx2 = p[i - 1];
        if (j == 0) mx2 = -mx2;
        if (k == 0) swap(mx, mx2);
        for (int t = 0; t < 2; ++t) {
          int cur = p[i];
          if (t == 0) cur = -cur;
          if (cur > mx) {
            if (mx2 < dp[i][t][0]) {
              dp[i][t][0] = mx2;
              from[i][t][0] = make_pair(j, k);
            }
          } else if (cur > mx2) {
            if (mx < dp[i][t][1]) {
              dp[i][t][1] = mx;
              from[i][t][1] = make_pair(j, k);
            }
          }
        }
      }
    }
  }
  int nj = -1, nk = -1;
  for (int j = 0; j < 2; ++j) {
    for (int k = 0; k < 2; ++k) {
      if (dp[n][j][k] != INF) {
        nj = j;
        nk = k;
        break;
      }
    }
  }
  if (nj == -1) {
    puts("NO");
    return;
  }
  puts("YES");
  for (int i = n; i >= 1; --i) {
    if (nj == 0) ans[i] = -ans[i];
    nj = from[i][nj][nk].first;
    nk = from[i][nj][nk].second;
  }
  for (int i = 1; i < n; ++i) {
    printf("%d ", ans[i]);
  }
  printf("%d\n", ans[n]);
}
int main() {
  int T;
  read(T);
  while (T--) {
    solve();
  }
  return 0;
}
