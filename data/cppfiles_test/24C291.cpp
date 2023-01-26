#include <bits/stdc++.h>
const int P = 998244353;
void solve() {
  int n;
  std::cin >> n;
  std::cout << n / 10 + (n % 10 == 9) << '\n';
}
signed main() {
  std::cin.sync_with_stdio(false), std::cin.tie(nullptr);
  int T = 1;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
