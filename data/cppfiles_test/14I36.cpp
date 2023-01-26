#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-8;
const long long INF = 1e9;
const long long N = 2e3 + 5;
const long long mod = 1e9 + 7;
int n, k;
int arr[N];
int dp[N][N];
int solve(int idx, int good, int shift) {
  if (good >= k) return 0;
  if (idx == n + 1) {
    if (good >= k)
      return 0;
    else
      return INF;
  }
  if (dp[idx][shift] != -1) {
    return dp[idx][shift];
  }
  int ans = INF;
  for (int i = idx; i <= n; i++) {
    if (arr[i] == i - shift) ans = min(ans, solve(i + 1, good + 1, shift));
    ans = min(ans, solve(i + 1, good, shift + 1) + 1);
  }
  return dp[idx][shift] = ans;
}
void testCase() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int good = 0;
  for (int i = 1; i <= n; i++) good = good + arr[i] == i;
  int ans = 0;
  if (good >= k) {
    cout << 0 << '\n';
    return;
  }
  memset(dp, -1, sizeof dp);
  ans = solve(1, 0, 0);
  if (ans > n)
    cout << -1 << '\n';
  else
    cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tests = 1;
  cin >> tests;
  while (tests--) testCase();
}
