#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,tune=native")
template <typename T>
using Prior = std::priority_queue<T>;
template <typename T>
using prior = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using namespace std;
void pre() {}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<long long> arr(n);
  for (auto& x : arr) cin >> x;
  vector<vector<long long>> dp(n, vector<long long>(n + 1));
  for (int j = 1; j <= n; ++j)
    dp[0][j] = dp[0][j - 1] + (bool)(arr[j - 1] == j);
  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      dp[i][j] =
          max(dp[i - 1][j - 1], dp[i][j - 1] + (bool)(arr[j - 1] == j - i));
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (dp[i][j] == k) return cout << i << '\n', void();
  cout << -1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  pre();
  int _ = 1;
  cin >> _;
  vector<long long> __(_);
  iota(begin(__), end(__), 1);
  for (auto i : __) {
    solve();
  }
  return 0;
}
