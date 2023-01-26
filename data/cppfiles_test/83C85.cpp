#include <bits/stdc++.h>
using namespace std;
const int N = 5005, oo = 1e9 + 10;
int lcp[N][N], dp[N];
void solve() {
  int n;
  string s;
  cin >> n >> s;
  s = "#" + s;
  for (int i = 0; i <= n + 1; ++i) {
    for (int j = 0; j <= n + 1; ++j) {
      lcp[i][j] = 0;
    }
  }
  for (int L = n; L >= 1; --L) {
    for (int R = L; R <= n; ++R) {
      if (s[L] == s[R]) {
        lcp[L][R] = lcp[L + 1][R + 1] + 1;
      } else {
        lcp[L][R] = 0;
      }
    }
  }
  auto is_less = [&](int i, int j) -> bool {
    assert(i < j);
    int at_i = i + lcp[i][j];
    int at_j = j + lcp[i][j];
    if (at_j == n + 1) {
      return false;
    }
    return s[at_i] < s[at_j];
  };
  for (int i = 1; i <= n; ++i) {
    dp[i] = n - i + 1;
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      if (is_less(j, i)) {
        dp[i] = max(dp[i], dp[j] + (n - i + 1 - lcp[j][i]));
      }
    }
  }
  int best = 0;
  for (int i = 1; i <= n; ++i) {
    best = max(best, dp[i]);
  }
  cout << best << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
