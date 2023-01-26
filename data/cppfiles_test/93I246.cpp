#include <bits/stdc++.h>
using ll = long long;
int main() {
  int t, a, b;
  std::cin >> t;
  while (t--) {
    std::cin >> a >> b;
    std::vector<int> v{a - 1, 1, a, 0};
    int c{v[(a - 1) % 4]};
    if (c != b) {
      std::cout << a + 1 + (c == 0 && b <= a) << std::endl;
    } else {
      std::cout << a << std::endl;
    }
  }
}
