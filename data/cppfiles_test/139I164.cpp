#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int l = s.size(), c = 0;
    if (l % 2 != 0) {
      cout << "NO"
           << "\n";
      continue;
    }
    if (l % 2 == 0) {
      for (int i = 0; i < (l / 2); i++)
        if (s[i] == s[i + (l / 2)]) {
          c++;
        }
    }
    if (c == (l / 2)) {
      cout << "YES"
           << "\n";
      continue;
    } else if (c == 0 || l == 1) {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
