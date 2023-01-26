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
      std::vector<int> eratos(n + 1, true);
      for (int u = 1; u <= n; ++u)
        if (s[u - 1] != c) {
          eratos[u] = false;
          int sqrt_u = std::sqrt(u);
          for (int i = 2; i <= sqrt_u; ++i)
            if (u % i == 0) {
              eratos[i] = false;
              eratos[u / i] = false;
            }
        }
      auto found = std::find(eratos.begin() + 2, eratos.end(), true);
      if (found != eratos.end())
        std::cout << "1\n" << found - eratos.begin() << '\n';
      else {
        std::cout << "2\n";
        std::cout << n << " " << n - 1 << '\n';
      }
    }
  }
  return EXIT_SUCCESS;
}
