#include <bits/stdc++.h>
std::vector<std::string> v;
int n;
const int MAX_N = 20;
int sum[MAX_N + 3];
int min[MAX_N + 3];
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
    for (auto c : v[i]) {
      if (c == ')')
        S--;
      else
        S++;
      m = std::min(m, S);
      if (S == m) cnt_pos[i][MAX_M + S]++;
    }
    sum[i] = S, min[i] = m;
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
        int new_res = cnt_pos[i][MAX_M - total_sum[mask]];
        if (total_sum[mask] + min[i] <= 0)
          res = std::max(res, dp[mask] + new_res);
        if (total_sum[mask] + min[i] >= 0)
          dp[mask ^ (1 << i)] =
              std::max(dp[mask ^ (1 << i)], dp[mask] + new_res);
      }
    }
  }
  std::cout << res << "\n";
}
