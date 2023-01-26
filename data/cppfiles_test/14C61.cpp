#include <bits/stdc++.h>
using namespace std;
const int N = 2007;
const int INF = 1e9 + 7;
int n, k;
int arr[N];
int dp[N][N];
int solve(int i, int rem) {
  if (i < 0) return rem == 0 ? 0 : -INF;
  int& r = dp[i][rem];
  if (r != -1) return r;
  r = solve(i - 1, rem);
  if (rem > 0) r = max(r, solve(i - 1, rem - 1));
  int cur = i + 1 - rem;
  if (cur == arr[i]) {
    r = max(r, 1 + solve(i - 1, rem));
  }
  return r;
}
void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = -1;
    }
  }
  int ans = -1;
  for (int i = 0; i <= n; i++) {
    if (solve(n - 1, i) >= k) {
      ans = i;
      break;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
