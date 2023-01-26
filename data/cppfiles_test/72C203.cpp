#include <bits/stdc++.h>
bool check(int32_t n, int32_t k) {
  int32_t mask = 0;
  while (n > 0) {
    mask |= 1 << (n % 10);
    n /= 10;
  }
  return __builtin_popcount(mask) <= k;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int32_t num_tests;
  std::cin >> num_tests;
  for (int32_t t = 0; t < num_tests; t++) {
    int32_t n, k;
    std::cin >> n >> k;
    std::vector<int32_t> digits;
    int32_t n2 = n;
    while (n2 > 0) {
      digits.push_back(n2 % 10);
      n2 /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    int64_t answer = 1;
    while (answer < n) answer = answer * 10 + 1;
    int64_t pref = 0;
    for (int32_t i = 0; i <= digits.size(); i++) {
      for (int32_t p1 = 0; p1 <= 10; p1++)
        for (int32_t p2 = 0; p2 <= 10; p2++) {
          int64_t new_num = pref;
          if (i == 0 && p1 == 0) continue;
          if (new_num >= n && check(new_num, k))
            answer = std::min(answer, new_num);
          new_num = new_num * 10 + p1;
          while (new_num < n) {
            new_num = new_num * 10 + p2;
          }
          if (new_num >= n && check(new_num, k))
            answer = std::min(answer, new_num);
        }
      pref *= 10;
      pref += digits[i];
    }
    std::cout << answer << "\n";
  }
  return 0;
}
