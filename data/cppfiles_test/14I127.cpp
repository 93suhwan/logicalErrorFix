#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 2e3 + 5;
const int inf = 0x3f3f3f3f;
int b[MAXN];
int pre[MAXN][MAXN];
int dp[MAXN][MAXN];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n + 1; i++) {
      for (int j = 0; j <= n; j++) {
        dp[i][j] = pre[i][j] = 0;
      }
    }
    for (int i = n; i >= 1; i--) {
      for (int j = 0; j <= n; j++) {
        pre[i][j] = pre[i + 1][j];
      }
      if (i - b[i] >= 0) {
        pre[i][i - b[i]]++;
      }
    }
    for (int i = n; i >= 1; i--) {
      for (int j = 0; j <= n - 1; j++) {
        dp[i][j] = max(dp[i][j], dp[i + 1][j] + (b[i] == i));
        if (j > 0) {
          dp[i][j] = max(dp[i][j], pre[i + 1][j]);
        }
      }
    }
    int ans = -1;
    for (int i = 0; i <= n - 1; i++) {
      if (dp[1][i] >= k) {
        ans = i;
        break;
      }
    }
    printf("%d\n", ans);
  }
}
