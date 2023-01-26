#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <class T>
bool uin(T& a, const T& b) {
  return a >= b ? a = b, 1 : 0;
}
template <class T>
bool uax(T& a, const T& b) {
  return a <= b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr int inf = 1e9;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  vector<int> sum(n), low(n);
  for (auto i = (0); i < (n); ++i) {
    string s;
    cin >> s;
    a[i].assign(int((s).size()) + 1, 0);
    for (auto j = (0); j < (int((s).size())); ++j) {
      sum[i] += s[j] == '(' ? +1 : -1;
      if (uax(low[i], -sum[i])) ++a[i][low[i]];
    }
  }
  vector<int> dp(1 << n, -inf);
  dp[0] = 0;
  int ans = 0;
  for (auto S = (0); S < (1 << n); ++S) {
    uax(ans, dp[S]);
    int count = 0;
    for (auto i = (0); i < (n); ++i)
      if (S >> i & 1) count += sum[i];
    for (auto i = (0); i < (n); ++i) {
      if (S >> i & 1) continue;
      int del = 0 <= count && count < int((a[i]).size()) ? a[i][count] : 0;
      uax(count < low[i] ? ans : dp[S | 1 << i], dp[S] + del);
    }
  }
  cout << ans << '\n';
}
