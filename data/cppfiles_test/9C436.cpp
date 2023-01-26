#include <bits/stdc++.h>
int main() {
  int t, l, eq, ueq;
  std::string s;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int a[26] = {0};
    eq = 0;
    ueq = 0;
    std::cin >> s;
    l = s.length();
    for (int j = 0; j < l; j++) {
      a[(s[j] - 97)] += 1;
    }
    for (int j = 0; j < 26; j++) {
      if (a[j] >= 2) {
        eq++;
      } else if (a[j] == 1) {
        ueq++;
      }
    }
    std::cout << (eq + ueq / 2) << std::endl;
  }
  return 0;
}
