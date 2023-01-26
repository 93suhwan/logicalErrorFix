#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 1000 * 1000 + 13;
int n;
int p[N], a[N];
int dp[N][2], pr[N][2];
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < int(n); ++i) scanf("%d", &p[i]);
  for (int i = 0; i < int(n); ++i)
    for (int j = 0; j < int(2); ++j) dp[i][j] = INF;
  dp[0][0] = dp[0][1] = -INF;
  for (int i = 0; i < int(n - 1); ++i) {
    bool flag[2];
    flag[0] = flag[1] = false;
    for (int j = 0; j < int(2); ++j) {
      if (dp[i][j] != INF) {
        int x = j ? -p[i] : p[i];
        int y = dp[i][j];
        if (x < y) swap(x, y);
        for (int nj = 0; nj < int(2); ++nj) {
          int z = nj ? -p[i + 1] : p[i + 1];
          if (z > x) {
            if (dp[i + 1][nj] > y) {
              dp[i + 1][nj] = y;
              pr[i + 1][nj] = j;
              flag[nj] = true;
            }
          } else if (z > y && !flag[nj]) {
            if (dp[i + 1][nj] > x) {
              dp[i + 1][nj] = x;
              pr[i + 1][nj] = j;
            }
          }
        }
      }
    }
  }
  int j = -1;
  for (int i = 0; i < int(2); ++i)
    if (dp[n - 1][i] != INF) j = i;
  if (j == -1) {
    puts("NO");
    return;
  }
  for (int i = n - 1; i >= 0; i--) {
    a[i] = j ? -p[i] : p[i];
    j = pr[i][j];
  }
  puts("YES");
  for (int i = 0; i < int(n); ++i) printf("%d ", a[i]);
  puts("");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
