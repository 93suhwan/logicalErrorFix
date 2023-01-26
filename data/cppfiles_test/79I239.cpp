#include <bits/stdc++.h>
using LL = long long;
std::string solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  std::cerr << ("n") << " is " << (n) << '\n';
  ;
  std::cerr << ("s") << " is " << (s) << '\n';
  ;
  for (int i = 0; i < n; ++i) {
    if (std::string("4689").find(s[i]) != std::string::npos)
      return std::string(1, s[i]);
  }
  for (int i = 1; i < n; ++i) {
    if (std::string("25").find(s[i]) != std::string::npos)
      return std::string(1, s[0]) + std::string(1, s[i]);
  }
  if (std::count(s.begin(), s.end(), '3') > 1) return std::string("33");
  for (auto it = s.begin(); it != s.end(); ++it)
    if (*it == '3') {
      s.erase(it);
      break;
    }
  if (s[0] == '2' || s[0] == '5') return {s.begin(), s.begin() + 2};
  return {s.begin(), s.begin() + 3};
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    auto s = solve();
    std::cout << s.size() << '\n' << s << '\n';
  }
  return 0;
}
