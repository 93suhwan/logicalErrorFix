#include <bits/stdc++.h>
constexpr bool test_cases = true;
void solve() {
  std::string s;
  std::cin >> s;
  int n = s.length();
  int ab = 0, ba = 0;
  for (int i = 0; i < n; ++i) {
    if (i + 1 < n) {
      if (s[i] == 'a' and s[i + 1] == 'b')
        ab += 1;
      else if (s[i] == 'b' and s[i + 1] == 'a')
        ba += 1;
    }
  }
  if (ab == ba)
    std::cout << s << '\n';
  else {
    if (std::abs(ab - ba) != 1) throw std::runtime_error("retard");
    if (ab > ba) {
      int last = -1;
      for (int i = 0; i < n; ++i)
        if (s[i] == 'b') last = i;
      s[last] = 'a';
    } else {
      int last = -1;
      for (int i = 0; i < n; ++i)
        if (s[i] == 'a') last = i;
      s[last] = 'b';
    }
    std::cout << s << '\n';
  }
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
