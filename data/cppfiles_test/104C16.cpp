#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int32_t num_tests;
  std::cin >> num_tests;
  for (int32_t t = 0; t < num_tests; t++) {
    int32_t n, m;
    std::cin >> n >> m;
    int32_t* a_arr = new int32_t[n];
    int32_t* b_arr = new int32_t[n];
    std::pair<int32_t, int32_t>* ans = new std::pair<int32_t, int32_t>[n];
    for (int32_t i = 0; i < n; i++) {
      int32_t a, b;
      std::cin >> a >> b;
      a_arr[i] = a;
      b_arr[i] = b;
      if (a >= m)
        ans[i] = {a - m, b};
      else
        ans[i] = {0, b - (m - a)};
    }
    int64_t sum1 = 0, sum2 = 0;
    for (int32_t i = 0; i < n; i++) sum1 += ans[i].first;
    for (int32_t i = 0; i < n; i++) sum2 += ans[i].second;
    for (int32_t i = 0; i < n; i++) {
      if (sum1 + 1 >= sum2) continue;
      int64_t max_moved = (sum2 - sum1) / 2;
      int32_t min_a = std::max(0, a_arr[i] - m);
      int32_t max_a = a_arr[i] - (b_arr[i] >= m ? 0 : m - b_arr[i]);
      int32_t max_from_here = max_a - min_a;
      int32_t really_moved = std::min(max_moved, (int64_t)max_from_here);
      ans[i].second -= really_moved;
      ans[i].first += really_moved;
      sum1 += really_moved;
      sum2 -= really_moved;
    }
    std::cout << std::abs(sum1 - sum2) << "\n";
    for (int32_t i = 0; i < n; i++)
      std::cout << a_arr[i] - ans[i].first << " " << b_arr[i] - ans[i].second
                << "\n";
    std::cout << "\n";
  }
  return 0;
}
