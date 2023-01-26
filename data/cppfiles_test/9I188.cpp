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
    for (auto t = m.begin(); t != m.end(); t++) {
      if (t->second == 1) {
        ans++;
      } else {
        cnt++;
      }
    }
    std::cout << ans + cnt / 2 << std::endl;
  }
}
