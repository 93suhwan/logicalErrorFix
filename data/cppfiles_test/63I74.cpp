#include <bits/stdc++.h>
using namespace std;
void solve_problem() {
  const int offset = 4 * 1e5 + 10;
  int n;
  cin >> n;
  vector<vector<int>> b(n), lvp(n), m(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int prev_b = 0;
    b[i].resize(s.size(), 0);
    lvp[i].resize(1e6, 0);
    m[i].resize(s.size(), 0);
    m[i][0] = 2;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '(') {
        b[i][j] = prev_b + 1;
      } else {
        b[i][j] = prev_b - 1;
      }
      prev_b = b[i][j];
      m[i][j] = min(m[i][j - 1], b[i][j]);
      if (m[i][j] == b[i][j]) {
        ++lvp[i][b[i][j] + offset];
      }
    }
  }
  vector<pair<array<int, 2>, int>> dp(
      (1 << n), make_pair(array<int, 2>{int(-1e9), int(-1e9)}, 0));
  int max_num = 0;
  for (int mask = 1; mask < (1 << n); mask++) {
    for (int j = 0; j < n; j++) {
      if (mask & (1 << j)) {
        int sub_mask = mask ^ (1 << j);
        int cur_balance = dp[sub_mask].second;
        int cur_num = lvp[j][offset - cur_balance];
        int size = m[j].size() - 1;
        dp[mask].second = cur_balance + b[j][size];
        dp[mask].first[0] = max(dp[mask].first[0], dp[sub_mask].first[0]);
        if (cur_balance + m[j][size] < 0) {
          if (sub_mask != 0) {
            dp[mask].first[0] =
                max(dp[mask].first[0], dp[sub_mask].first[1] + cur_num);
          } else {
            dp[mask].first[0] = max(dp[mask].first[0], cur_num);
          }
        } else {
          if (sub_mask != 0) {
            dp[mask].first[1] =
                max(dp[mask].first[1], dp[sub_mask].first[1] + cur_num);
          } else {
            dp[mask].first[1] = max(dp[mask].first[1], cur_num);
          }
        }
        max_num = max(max_num, dp[mask].first[0]);
        max_num = max(max_num, dp[mask].first[1]);
      }
    }
  }
  cout << max(max_num, 0) << endl;
}
int main() {
  int t = 1;
  for (int i = 0; i < t; i++) {
    solve_problem();
  }
  return 0;
}
