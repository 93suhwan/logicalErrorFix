#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.length() % 2 == 1) {
      cout << "NO\n";
      continue;
    } else {
      bool ok = true;
      int n = s.length();
      for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[i + n / 2]) {
          ok = false;
          break;
        }
      }
      cout << (ok ? "YES\n" : "NO\n");
    }
  }
  return 0;
}
