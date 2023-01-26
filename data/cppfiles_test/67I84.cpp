#include <bits/stdc++.h>
using i64 = long long;
using ld = long double;
const ld eps = 1e-9;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  ld p;
  std::cin >> n >> p;
  i64 total = n * (n - 1) * (n - 2) / 6;
  for (int ans = 1; ans <= n; ++ans) {
    i64 res = (i64)ans * (ans - 1) / 2;
    res *= n - 2;
    ld pp = 1.0 - (ld)res / total;
    if (pp - p >= 0) {
      std::cout << n - ans << '\n';
      return 0;
    }
  }
}
