#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    if ((a == b && c % 2 == 0) || (a == c && b % 2 == 0) ||
        (b == c && a % 2 == 0)) {
      std::cout << "YES" << std::endl;
    } else {
      int x = a - b;
      int y = b - c;
      int z = a - c;
      if ((x == c || x == -c) || (y == a || y == -a) || (z == b || z == -b)) {
        std::cout << "YES" << std::endl;
      } else {
        std::cout << "NO" << std::endl;
      }
    }
  }
}
