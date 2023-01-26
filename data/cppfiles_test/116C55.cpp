#include <bits/stdc++.h>
const double PI = acos(-1);
const int N = 1e5 + 10;
const int M = 998244353;
long long add(long long a, long long b) { return ((a + b) % M + M) % M; }
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int> > dp(n + 3, vector<int>(3));
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    int val[] = {1, 1, 1};
    if (a[i] == 0) {
      val[0] = add(val[0], dp[a[i]][0]);
      val[1] = 0;
      val[2] = add(dp[a[i]][2], dp[a[i] + 2][1]);
    } else if (a[i] == 1) {
      val[0] = add(dp[a[i]][0], dp[a[i] - 1][0]);
      val[1] = add(val[1], dp[a[i]][1]);
      val[2] = add(dp[a[i]][2], dp[a[i] + 2][1]);
    } else {
      val[0] = add(dp[a[i]][0], dp[a[i] - 1][0]);
      val[1] = add(dp[a[i]][1], dp[a[i] - 2][0]);
      val[1] = add(val[1], dp[a[i] - 2][2]);
      val[2] = add(dp[a[i]][2], dp[a[i] + 2][1]);
    }
    for (int k = 0; k < 3; ++k) {
      ans = add(ans, val[k]);
      dp[a[i]][k] = add(dp[a[i]][k], val[k]);
    }
  }
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
