#include <bits/stdc++.h>
constexpr int MAXN = 1e5;
int main(const int argc, const char** argv) {
  std::ios::sync_with_stdio(false);
  std::cout.tie(nullptr);
  std::cin.tie(nullptr);
  std::vector<bool> eratos(MAXN + 1, true);
  for (int n = 2; n * n <= MAXN; ++n)
    if (eratos[n])
      for (int m = n * n; m <= MAXN; m += n) eratos[m] = false;
  int num_tests;
  std::cin >> num_tests;
  while (num_tests--) {
    int n;
    char c;
    std::string s;
    std::cin >> n >> c >> s;
    std::vector<int> opers;
    for (int i = 0; i < n; ++i) {
      if (eratos[i + 1] && s[i] != c) {
        opers.emplace_back(i + 1);
      }
    }
    int m = opers.size();
    std::cout << m << '\n';
    for (int i = 0; i < m; ++i)
      std::cout << opers[i] << (i + 1 != m ? ' ' : '\n');
  }
  return EXIT_SUCCESS;
}
