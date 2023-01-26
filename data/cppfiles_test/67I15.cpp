#include <bits/stdc++.h>
struct Solver {
  void solve() {
    int n;
    double P;
    std::cin >> n >> P;
    auto c2 = [](int n) {
      if (n <= 1) {
        return 0;
      }
      return n * (n - 1) / 2;
    };
    auto c3 = [](int n) { return n * (n - 1) * (n - 2) / 6; };
    auto total = c3(n);
    ;
    for (int x = 0; x <= n; ++x) {
      ;
      double p = (c3(x) + c2(x) * (n - x) + x * c2(n - x) * 4 / 9.0) /
                 static_cast<double>(total);
      ;
      if (p >= P) {
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
