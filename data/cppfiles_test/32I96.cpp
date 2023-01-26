#include <bits/stdc++.h>
const double eps = 1e-5;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
using namespace std;
int s[maxn], n;
long long dp[maxn][550], sum[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
    reverse(s + 1, s + n + 1);
    int k = 1;
    while (k * (k + 1) / 2 <= n) k++;
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + s[i];
      for (int j = 0; j < k; j++) dp[i][j] = 0;
      dp[i][1] = s[i];
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < k; j++) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        if (dp[i - j][j - 1] > (sum[i] - sum[i - j])) {
          dp[i][j] = max(dp[i][j], sum[i] - sum[i - j]);
          ans = max(ans, j);
        }
      }
    }
    cerr << "ans"
         << ":" << ans << endl;
    printf("%d\n", ans);
  }
  return 0;
}
