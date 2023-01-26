#include <bits/stdc++.h>
void Solve() {
  int n = 0, k = 0;
  std::cin >> n >> k;
  std::vector<std::vector<int>> by_col(n);
  int c = 0;
  for (int i = 0; i < n * k; ++i) {
    std::cin >> c;
    by_col[c - 1].push_back(i);
  }
  std::vector<std::pair<int, int>> ans(n);
  for (int i = 0; i < n; i += k - 1) {
    std::vector<int> ptr(k - 1, 0);
    int last_right_end = 0;
    for (int round = 0; round < std::min(k - 1, n - i); ++round) {
      int min_right_end = n * k + 1;
      int argmax = -1;
      for (int j = 0; j < std::min(k - 1, n - i); ++j) {
        if (ptr[j] != -1) {
          while (by_col[i + j][ptr[j]] < last_right_end) {
            ++ptr[j];
          }
          if (min_right_end > by_col[i + j][ptr[j] + 1]) {
            min_right_end = by_col[i + j][ptr[j] + 1];
            argmax = j;
          }
        }
      }
      last_right_end = min_right_end;
      ans[i + argmax] = {by_col[i + argmax][ptr[argmax]],
                         by_col[i + argmax][ptr[argmax] + 1]};
      ptr[argmax] = -1;
    }
  }
  for (auto& interval : ans) {
    std::cout << interval.first + 1 << ' ' << interval.second + 1 << '\n';
  }
}
int main() { Solve(); }
