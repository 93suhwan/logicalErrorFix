#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<string> s(2);
    std::cin >> s[0] >> s[1];
    bool flag = 1;
    auto check = [&](int x, int y) {
      return x >= 0 && y >= 0 && x < 2 && y < n && s[x][y] == '1';
    };
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        if (s[0][j] == s[1][j] && s[0][j] == '1') {
          flag = false;
          break;
        }
      }
    }
    if (flag)
      std::cout << "YES"
                << "\n";
    else
      std::cout << "NO"
                << "\n";
  }
  return 0;
}
