#include <bits/stdc++.h>
int main() {
  int t;
  std::cin >> t;
  while (t > 0) {
    std::string str;
    std::cin >> str;
    bool a = false;
    bool b = false;
    bool c = false;
    int last = 2;
    for (char i : str) {
      if (i == '1') {
        a = true;
        last = 1;
        continue;
      }
      if (i == '0') {
        if (b && last == 1) {
          c = true;
        }
        b = true;
        last = 0;
      }
    }
    if (a && !b) std::cout << "0" << '\n';
    if (a && b && !c || !a && b) std::cout << "1" << '\n';
    if (a && b && c) std::cout << "2" << '\n';
    t--;
  }
}
