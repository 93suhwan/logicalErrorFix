#include <bits/stdc++.h>
int main() {
  int32_t num_tests;
  std::cin >> num_tests;
  for (int32_t t = 0; t < num_tests; t++) {
    int32_t n, m, k;
    std::cin >> n >> m >> k;
    if (m % 2 == 0)
      std::cout << (((n * m) / 2 - k) % 2 == 0 ? "YES" : "NO") << "\n";
    else {
      bool answer = k % 2 == 0;
      answer = answer && k <= n * (m - 1) / 2;
      std::cout << (answer ? "YES" : "NO") << "\n";
    }
  }
  return 0;
}
