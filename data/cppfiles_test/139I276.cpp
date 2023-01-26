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
      cout << "NO" << t << "\n";
      continue;
    }
    if (l % 2 == 0) {
      for (int i = 0; i < (l / 2); i++)
        if (s[i] == s[i + (l / 2)]) {
          c++;
        }
    }
    if (c == (l / 2)) {
      cout << "YES" << t << "\n";
    } else {
      cout << "NO" << t << "\n";
    }
  }
  return 0;
}
