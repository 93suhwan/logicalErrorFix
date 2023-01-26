#include <bits/stdc++.h>
using std::cin;
using std::cout;
int main() {
  int t = 0;
  cin >> t;
  while (t--) {
    std::string s;
    cin >> s;
    if (s.size() % 2) {
      cout << "NO\n";
      continue;
    }
    int l1 = s.size() - 1;
    int l2 = s.size() / 2 - 1;
    char ok = 1;
    while (l1 > s.size() / 2 - 1 && l2 > -1) {
      if (s[l1--] != s[l2--]) {
        ok = 0;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}
