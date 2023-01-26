#include <bits/stdc++.h>
constexpr bool test_cases = true;
void solve() {
  std::string s;
  std::cin >> s;
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    if (i + 1 < n) {
      if (s[i] == 'a' and s[i + 1] == 'b') {
        if (i + 2 < n) {
          if (s[i + 2] == 'a')
            ;
          else
            s[i + 2] = 'a';
        } else
          s[i + 1] = 'a';
      } else if (s[i] == 'b' and s[i + 1] == 'a') {
        if (i + 2 < n) {
          if (s[i + 2] == 'b')
            ;
          else
            s[i + 2] = 'b';
        } else
          s[i + 1] = 'b';
      }
    }
  }
  std::cout << s << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.precision(10);
  std::cerr.precision(10);
  std::cout << std::fixed << std::boolalpha;
  std::cerr << std::fixed << std::boolalpha;
  int32_t cases = 1;
  if (test_cases) std::cin >> cases;
  while (cases--) solve();
  return 0;
}
