#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 1e6 + 10;
int n, a[N][2], dp[N][2][2], ans[N];
pair<int, int> pre[N][2][2];
inline void solve() {
  n = read();
  for (int i = (1); i <= (n); i++) a[i][0] = read(), a[i][1] = -a[i][0];
  if (n == 1) return puts("YES\n1\n"), void(0);
  for (int i = (1); i <= (n); i++)
    for (int j = (0); j <= (1); j++)
      for (int k = (0); k <= (1); k++)
        dp[i][j][k] = n + 1, pre[i][j][k] = make_pair(-1, -1);
  for (int j = (0); j <= (1); j++) dp[1][j][0] = -n - 1;
  for (int i = (1); i < (n); i++)
    for (int j = (0); j <= (1); j++)
      for (int k = (0); k <= (1); k++)
        if (dp[i][j][k] < n + 1) {
          for (int l = (0); l <= (1); l++) {
            int x = 0, y = 0;
            if (k == 0)
              x = a[i][j], y = dp[i][j][k];
            else
              y = a[i][j], x = dp[i][j][k];
            int z = a[i + 1][l];
            if (z < y) continue;
            if (z > x) {
              if (y < dp[i + 1][l][0])
                dp[i + 1][l][0] = y, pre[i + 1][l][0] = make_pair(j, k);
            } else {
              if (x < dp[i + 1][l][1])
                dp[i + 1][l][1] = x, pre[i + 1][l][1] = make_pair(j, k);
            }
          }
        }
  int x = -1, y = -1;
  for (int j = (0); j <= (1); j++)
    for (int k = (0); k <= (1); k++)
      if (pre[n][j][k].first != -1) x = j, y = k;
  if (x == -1) return puts("NO"), void(0);
  for (int i = (n); i >= (1); i--) {
    ans[i] = a[i][x];
    auto tmp = pre[i][x][y];
    x = tmp.first, y = tmp.second;
  }
  puts("YES");
  for (int i = (1); i <= (n); i++) printf("%d ", ans[i]);
  puts("");
}
int main() {
  int T = read();
  while (T--) solve();
}
