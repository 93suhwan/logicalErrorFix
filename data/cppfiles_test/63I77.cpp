#include <bits/stdc++.h>
std::vector<std::string> v;
int n;
const int MAX_N = 20;
int sum[MAX_N + 3];
int min[MAX_N + 3];
int cnt_min[MAX_N + 3];
const int MAX_MASK = (1 << 20);
int total_sum[MAX_MASK + 3];
int dp[MAX_MASK + 5];
const int MAX_M = 4e5;
int cnt_pos[MAX_N + 3][2 * MAX_M + 3];
bool is_bit(int mask, int pos) { return (mask & (1 << pos)) != 0; }
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(NULL);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::string s;
    std::cin >> s;
    v.push_back(s);
  }
  for (int i = 0; i < n; i++) {
    int S = 0;
    int m = INT_MAX;
    int cnt = 1;
    int min_found = INT_MAX;
    for (auto c : v[i]) {
      if (c == ')')
        S--;
      else
        S++;
      if (S < m)
        m = S, cnt = 1;
      else if (S == m)
        cnt++;
      if (S <= min_found) cnt_pos[i][MAX_M + S]++;
      min_found = std::min(min_found, S);
    }
    sum[i] = S, min[i] = m, cnt_min[i] = cnt;
  }
  for (int mask = 0; mask < (1 << n); mask++) {
    total_sum[mask] = 0;
    for (int i = 0; i < n; i++)
      if (is_bit(mask, i)) total_sum[mask] += sum[i];
  }
  int res = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if (!is_bit(mask, i)) {
        if (total_sum[mask] + min[i] < 0) {
          res =
              std::max(res, dp[mask] + cnt_pos[i][(-total_sum[mask]) + MAX_M]);
        } else if (total_sum[mask] + min[i] == 0) {
          res = std::max(res, dp[mask] + cnt_min[i]);
          dp[mask ^ (1 << i)] =
              std::max(dp[mask ^ (1 << i)], dp[mask] + cnt_min[i]);
        } else
          dp[mask ^ (1 << i)] = std::max(dp[mask ^ (1 << i)], dp[mask]);
      }
    }
  }
  std::cout << res << "\n";
}
