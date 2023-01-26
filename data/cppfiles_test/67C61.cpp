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
  for (int ans = 0; ans <= n; ++ans) {
    i64 c2 = (i64)(n - ans) * (n - ans - 1) / 2 * ans;
    i64 c1 = (i64)(n - ans) * ans * (ans - 1) / 2;
    i64 c0 = (i64)ans * (ans - 1) * (ans - 2) / 6;
    ld pp = (ld)(c0 + c1 + (ld)c2 / 2) / total;
    if (pp >= p) {
      std::cout << ans << '\n';
      return 0;
    }
  }
}
