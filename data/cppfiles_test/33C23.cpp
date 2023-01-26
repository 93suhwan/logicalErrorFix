#include <bits/stdc++.h>
int main() {
  int32_t num_tests;
  num_tests = 1;
  std::mt19937 rng;
  for (int32_t t = 0; t < num_tests; t++) {
    int32_t n;
    std::cin >> n;
    int32_t* arr = new int32_t[n];
    for (int32_t i = 0; i < n; i++) std::cin >> arr[i];
    int32_t* min_end_to_reach = new int32_t[512];
    for (int32_t i = 1; i < 512; i++) min_end_to_reach[i] = INT32_MAX;
    min_end_to_reach[0] = 0;
    for (int32_t i = 0; i < n; i++) {
      for (int32_t j = 0; j < 512; j++) {
        int32_t want_prev = arr[i] ^ j;
        if (min_end_to_reach[want_prev] < arr[i])
          min_end_to_reach[j] = std::min(min_end_to_reach[j], arr[i]);
      }
    }
    std::vector<int32_t> ans;
    for (int32_t i = 0; i < 512; i++)
      if (min_end_to_reach[i] != INT32_MAX) ans.push_back(i);
    std::cout << ans.size() << "\n";
    for (int32_t i = 0; i < ans.size(); i++) std::cout << ans[i] << " ";
    std::cout << "\n";
  }
  return 0;
}
