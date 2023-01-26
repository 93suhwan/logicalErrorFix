#include <bits/stdc++.h>
void solve() {
  long long n;
  std::cin >> n;
  long long l = 1, r = 2 * n, a = 0;
  while (l < r) {
    long long num = n - (l * (l + 1)) / 2;
    if ((abs(num)) % (l + 1) == 0) {
      a = num / (l + 1);
      break;
    }
    l++;
  }
  std::cout << a << " " << a + l << "\n";
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long long t = 0;
  std::cin >> t;
  while (t--) {
    solve();
  }
}
