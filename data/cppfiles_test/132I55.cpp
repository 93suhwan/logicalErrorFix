#include <bits/stdc++.h>
constexpr int maxT = 5e3;
int t;
int b[7];
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> t;
  while (t--) {
    for (int i = 0; i < 7; i++) {
      std::cin >> b[i];
    }
    std::sort(b, b + 7);
    std::cout << b[0] << ' ' << b[1] << ' ' << b[2] << "\n";
  }
}
