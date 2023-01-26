#include <bits/stdc++.h>
void testcase() {
  int n;
  std::cin >> n;
  std::vector<int> a(n, 0);
  for (auto &x : a) {
    std::cin >> x;
  }
  float mean = 0.0;
  for (const auto &x : a) {
    mean += x;
  }
  mean /= n;
  std::unordered_map<float, int> diffs;
  for (const auto &x : a) {
    diffs[mean - x] += 1;
  }
  int ans = 0;
  for (const auto &[k, v] : diffs) {
    if (k == 0.) {
      if (v >= 2) {
        ans += v * (v - 1);
      }
    } else {
      ans += diffs[k] * diffs[-k];
    }
  }
  std::cout << ans / 2 << std::endl;
}
int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    testcase();
  }
  return 0;
}
