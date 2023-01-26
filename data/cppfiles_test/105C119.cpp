#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <typename T>
int smin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
int smax(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}
mt19937_64 rng;
const int MX = 2e5 + 10;
const char nl = '\n';
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  vector<vector<int>> pos(n);
  for (int i = 0; i < n; i++) {
    pos[a[i]].push_back(i);
  }
  vector<vector<int>> dp(n, vector<int>(n));
  for (int l = n - 1; l >= 0; --l) {
    for (int r = l; r < n; r++) {
      if (l == r) {
        dp[l][r] = 1;
      } else {
        dp[l][r] = dp[l + 1][r] + 1;
        for (int mid : pos[a[l]]) {
          if (l <= mid && mid <= r) {
            int left = l + 1 < mid ? dp[l + 1][mid - 1] : 0;
            int right = dp[mid][r];
            dp[l][r] = min(dp[l][r], left + right);
          }
        }
      }
    }
  }
  cout << dp[0][n - 1] - 1 << nl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int te = 1;
  cin >> te;
  while (te--) {
    solve();
  }
  return 0;
}
