#include <bits/stdc++.h>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::map<char, int> m;
    std::cin >> s;
    for (char c : s) {
      m[c]++;
    }
    int ans = 0, cnt = 0;
    for (auto& it : m) {
      if (it.second == 1) {
        cnt++;
      } else {
        ans++;
      }
    }
    std::cout << ans + cnt / 2 << std::endl;
  }
}
