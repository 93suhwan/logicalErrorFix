#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt")
using ll = int64_t;
using namespace std;
template <class T, class U = T>
bool ckmax(T &a, U &&b) {
  return a < b ? a = std::forward<U>(b), true : false;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  cin >> t;
  for (int test = 1; test <= t; test++) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        ckmax(dp[i + 1][j], dp[i][j]);
        ckmax(dp[i + 1][j + 1], dp[i][j] + (a[i] == j + 1));
      }
    }
    int ans = -1;
    for (int i = 0; i <= n; ++i)
      if (dp[n][i] >= k) ans = n - i;
    cout << ans << '\n';
  }
}
