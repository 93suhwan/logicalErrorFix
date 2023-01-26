#include <bits/stdc++.h>
using LL = long long;
void solve() {
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << 1 << '\n';
    std::cout << 1 << '\n';
    return;
  }
  if (n % 2 == 1) --n;
  int x = 0, y = 0;
  if (n % 4 == 0) {
    x = n / 2;
  } else {
    x = n / 2;
    if (x == 1) {
      x = 2;
    } else {
      y = 2;
    }
  }
  int ans = n;
  if (x) --ans;
  if (y) --ans;
  std::cout << ans << '\n';
  for (int i = 1; i <= n; ++i)
    if (i != x && i != y) {
      std::cout << i << ' ';
    }
  std::cout << '\n';
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  while (cas--) {
    solve();
  }
  return 0;
}
