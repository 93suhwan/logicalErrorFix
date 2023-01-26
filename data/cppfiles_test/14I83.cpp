#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> a(2001);
  for (long long int i = 1; i <= n; ++i) cin >> a[i];
  vector<vector<long long int> > dp(n + 1, vector<long long int>(n + 1, -1));
  vector<long long int> d(n + 1, 0);
  for (long long int i = 1; i <= n; ++i) d[i] = a[i] - i;
  long long int cnt = 0;
  for (long long int i = n - 1; i >= 1; i--) {
    if (d[i] == 0) cnt++;
    dp[0][i] = cnt;
  }
  long long int mn = -1;
  for (long long int i = 1; i <= n; ++i) {
    for (long long int j = 1; j <= n; ++j) {
      dp[i][j] = max(dp[i][j - 1] + (d[j] + i == 0) - (d[j] + i == 1),
                     dp[i - 1][j - 1] + (d[j] + i - 1 == 0) - (d[j] + i == 1));
      if (dp[i][j] >= k) {
        mn = i;
        goto end_;
      }
    }
  }
end_:
  cout << mn << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
