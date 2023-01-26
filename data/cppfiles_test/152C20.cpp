#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, p[N], dp[N][2][2];
array<int, 3> pre[N][2][2];
void reset(int a[][2]) {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) a[i][j] = INT_MAX;
}
inline bool Min(int &x, int y) {
  if (x > y) {
    x = y;
    return true;
  }
  return false;
}
void echo(int a, int b, int c) {
  if (!a) return;
  echo(pre[a][b][c][0], pre[a][b][c][1], pre[a][b][c][2]);
  printf("%d%c", (c ? -p[a] : p[a]), " \n"[a == n]);
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", p + i);
  reset(dp[1]);
  dp[1][0][0] = -n;
  dp[1][0][1] = -n;
  for (int i = 2; i <= n; i++) {
    reset(dp[i]);
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) {
        if (dp[i - 1][j][k] == INT_MAX) continue;
        int x = p[i - 1], y = dp[i - 1][j][k];
        if (k) x = -x;
        if (j) swap(x, y);
        if (p[i] >= x) {
          if (Min(dp[i][0][0], y)) {
            pre[i][0][0] = {i - 1, j, k};
          }
        } else if (p[i] >= y) {
          if (Min(dp[i][1][0], x)) {
            pre[i][1][0] = {i - 1, j, k};
          }
        }
        if (-p[i] >= x) {
          if (Min(dp[i][0][1], y)) {
            pre[i][0][1] = {i - 1, j, k};
          }
        } else if (-p[i] >= y) {
          if (Min(dp[i][1][1], x)) {
            pre[i][1][1] = {i - 1, j, k};
          }
        }
      }
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      if (dp[n][i][j] < INT_MAX) {
        puts("YES");
        echo(n, i, j);
        return;
      }
    }
  puts("NO");
}
int main() {
  int _;
  scanf("%d", &_);
  while (_--) solve();
  return 0;
}
