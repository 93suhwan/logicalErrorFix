#include <bits/stdc++.h>
int main() {
  int req_amount;
  std::cin >> req_amount;
  while (req_amount--) {
    std::string s;
    std::cin >> s;
    int counter = 0;
    for (const auto c : s) {
      counter -= ((c == 'B') ? -1 : 1);
    }
    std::cout << ((counter == 0) ? "YES" : "NO") << std::endl;
  }
  return 0;
}
