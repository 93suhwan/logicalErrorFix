#include <bits/stdc++.h>
bool check(int32_t n, int32_t m, int32_t k) {
  bool answer = k % 2 == 0;
  answer = answer && k <= n * (m - 1) / 2;
  return answer;
}
int main() {
  int32_t num_tests;
  std::cin >> num_tests;
  for (int32_t t = 0; t < num_tests; t++) {
    int32_t n, m, k;
    std::cin >> n >> m >> k;
    if (n == 1) {
      std::cout << (k == m / 2 ? "YES" : "NO") << "\n";
    } else if (m % 2 == 0) {
      if (n % 2 == 0)
        std::cout << (((n * m) / 2 - k) % 2 == 0 ? "YES" : "NO") << "\n";
      else
        std::cout << (check(m, n, (m * n) / 2 - k) ? "YES" : "NO") << "\n";
    } else {
      std::cout << (check(n, m, k) ? "YES" : "NO") << "\n";
    }
  }
  return 0;
}
