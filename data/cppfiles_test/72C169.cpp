#include <bits/stdc++.h>
int64_t n, k, i;
std::string s, y;
std::set<char> st;
std::string solve() {
  st.clear();
  n = s.length();
  y = "";
  for (i = 0; i < n && st.size() <= k; ++i) {
    y += s[i];
    st.insert(s[i]);
  }
  if (i == n && st.size() <= k) return y;
  s = std::to_string(std::stoi(y) + 1) + std::string(n - y.size(), '0');
  return solve();
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    std::cin >> s >> k;
    std::cout << solve() << '\n';
  }
  return 0;
}
