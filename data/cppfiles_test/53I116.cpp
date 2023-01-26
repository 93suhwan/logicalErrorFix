#include <bits/stdc++.h>
int main(const int argc, const char** argv) {
  std::ios::sync_with_stdio(false);
  std::cout.tie(nullptr);
  std::cin.tie(nullptr);
  int num_tests;
  std::cin >> num_tests;
  while (num_tests--) {
    int n;
    char c;
    std::string s;
    std::cin >> n >> c >> s;
    if (std::count(s.begin(), s.end(), c) == n)
      std::cout << "0\n";
    else {
      if (s.back() == c)
        std::cout << "1\n" << n << '\n';
      else {
        if (std::count(s.begin(), s.end() - 1, c) == (n - 1)) {
          std::cout << "1\n" << n - 1 << '\n';
        } else {
          std::cout << "2\n";
          std::cout << n - 1 << ' ' << n << '\n';
        }
      }
    }
  }
  return EXIT_SUCCESS;
}
