#include <bits/stdc++.h>
void testcase() {
  int n;
  std::cin >> n;
  std::vector<int> a(n, 0);
  for (auto &x : a) {
    std::cin >> x;
  }
  int tot = 0;
  for (const auto &x : a) {
    tot += x;
  }
  int ans = 0;
  std::unordered_map<int, int> counts;
  for (const auto &x : a) {
    ans += counts[2 * tot - n * x];
    counts[n * x] += 1;
  }
  std::cout << ans << std::endl;
}
int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    testcase();
  }
  return 0;
}
