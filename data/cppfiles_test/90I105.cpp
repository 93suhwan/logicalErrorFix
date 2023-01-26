#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long T, n, m, ans;
long long l[400005], r[400005], a[400005], dp[4][400005];
int main() {
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    ans = INF;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (long long i = 1; i <= n; i++) l[i] = r[i] = a[i];
    a[0] = -INF;
    a[n + 1] = INF;
    for (long long tl, tr, pl, pr, i = 1; i <= m; i++) {
      cin >> tl >> tr;
      pl = lower_bound(a + 1, a + 1 + n + 1, tl) - a;
      pr = upper_bound(a + 1, a + 1 + n + 1, tr) - a - 1;
      if (pl <= pr) continue;
      l[pl] = min(l[pl], tr);
      r[pr] = max(r[pr], tl);
    }
    dp[0][0] = 0;
    dp[1][0] = dp[2][0] = dp[3][0] = INF;
    for (long long i = 1; i <= n; i++) {
      dp[0][i] = min(dp[2][i - 1], dp[3][i - 1]);
      dp[1][i] = min(min(dp[0][i - 1], dp[1][i - 1]),
                     min(dp[2][i - 1], dp[3][i - 1])) +
                 (a[i] - l[i]);
      dp[2][i] = min(dp[2][i - 1], dp[3][i - 1]) + (r[i] - a[i]);
      dp[3][i] = min(min(dp[0][i - 1], dp[1][i - 1]),
                     min(dp[2][i - 1], dp[3][i - 1])) +
                 min(r[i] - a[i], a[i] - l[i]) + r[i] - l[i];
    }
    cout << min(dp[2][n], dp[3][n]) << '\n';
  }
  return 0;
}
