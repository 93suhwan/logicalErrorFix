#include <bits/stdc++.h>
using namespace std;
long long dp[100005][505];
int n;
long long a[100005];
long long get_sum(int l, int r) { return a[r] - a[l - 1]; }
void Solve() {
  cin >> n;
  for (int i = n; i >= 1; --i) cin >> a[i];
  for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
  for (int i = 0; i <= n; ++i) {
    for (int j = 1; j <= 500; ++j) dp[i][j] = -1;
  }
  dp[0][0] = 1e18;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = 1e18;
    for (int j = 1; j <= sqrt(2 * i); ++j) {
      int sum = get_sum(i - j + 1, i);
      if (dp[i - j][j - 1] > sum) dp[i][j] = sum;
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    }
  }
  for (int i = 500; i >= 1; --i)
    if (dp[n][i] != -1) {
      cout << i << '\n';
      return;
    }
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  if (fopen(""
            ".inp",
            "r")) {
    freopen(
        ""
        ".inp",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
  int t;
  cin >> t;
  while (t--) {
    Solve();
  }
  cerr << "Time collapse : " << fixed << setprecision(3)
       << 1.000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
