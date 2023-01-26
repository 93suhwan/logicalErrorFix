#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::string str;
    std::cin >> str;
    int b = 0;
    for (char &c : str) {
      b += c == 'B';
    }
    int len = (int)str.length();
    std::cout << (len % 2 == 0 && b == len / 2 ? "YES" : "NO") << '\n';
  }
  return 0;
}
