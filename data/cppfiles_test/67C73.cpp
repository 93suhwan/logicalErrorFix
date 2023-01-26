#include <bits/stdc++.h>
struct Solver {
  void solve() {
    int64_t n;
    double P;
    std::cin >> n >> P;
    auto c2 = [](int n) {
      if (n <= 1) {
        return 0;
      }
      return n * (n - 1) / 2;
    };
    auto c3 = [](int64_t n) { return n * (n - 1) * (n - 2) / 6; };
    double total = c3(n);
    ;
    for (int64_t x = 0; x <= n; ++x) {
      double p =
          (c3(x) + c2(x) * (n - x) + x * c2(n - x) * (1.0 / 3.0 + 1.0 / 6.0)) /
          static_cast<double>(total);
      if (p + 1e-9 >= P) {
        std::cout << x << '\n';
        return;
      }
    }
    if (!(false)) {
      ;
      assert(false);
    };
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int t = 1;
  while (t--) {
    Solver{}.solve();
  }
  return 0;
}
