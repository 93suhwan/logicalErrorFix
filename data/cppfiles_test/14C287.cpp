#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool compare(pair<long long int, long long int> a,
             pair<long long int, long long int> b) {
  if (a.first > b.first) return true;
  if (a.first == b.first) return a.second < b.second;
  return false;
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
void solve() {
  int n, k;
  cin >> n >> k;
  int a[n + 1];
  for (int i = 0; i < n; i++) cin >> a[i + 1];
  int dp[n + 1][n + 1];
  memset(dp, 0, sizeof(dp));
  int idx = INT_MAX;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = max(dp[i - 1][j - 1] + (a[i] == j), dp[i - 1][j]);
      if (dp[i][j] >= k) idx = min(idx, i - j);
    }
  }
  if (idx == INT_MAX)
    cout << -1 << "\n";
  else
    cout << idx << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
