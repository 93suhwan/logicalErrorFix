#include <bits/stdc++.h>
using namespace std;
const int N = 501234, M = 998244353;
int dp[N], p2[N], cnt[N], sum[N], a[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n + 10; i++) {
    dp[i] = 0;
    cnt[i] = 0;
    sum[i] = 0;
  }
  for (int i = n - 1; i >= 0; i--) {
    cnt[a[i]]++;
    dp[i] += p2[cnt[a[i] + 2]];
    dp[i] += sum[a[i] + 1];
    dp[i] += sum[a[i]];
    dp[i] %= M;
    sum[a[i]] += dp[i];
    sum[a[i]] %= M;
  }
  int ans = sum[0] + p2[cnt[1]] - 1;
  ans += M;
  ans %= M;
  cout << ans << ' ';
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  p2[0] = 1;
  for (int i = 1; i < N; i++) {
    p2[i] = p2[i - 1] * 2;
    if (p2[i] >= M) p2[i] -= M;
  }
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
