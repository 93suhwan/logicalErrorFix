#include <bits/stdc++.h>
int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int testCase = 1;
  std::cin >> testCase;
  while (testCase--) {
    std::string A;
    std::cin >> A;
    std::vector<int> c(3, 0);
    for (auto x : A) ++c[x - 'A'];
    puts((c[0] + c[2] == c[1]) ? "YES" : "NO");
  }
  return 0;
}
