#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    int r = (s.length()) % 2;
    if (r == 1) {
      cout << "NO"
           << "\n";
    } else {
      int p = s.length() / 2;
      if (s.substr(0, p) == s.substr(p, p)) {
        cout << "YES"
             << "\n";
      } else {
        cout << "NO"
             << "\n";
      }
    }
  }
  return 0;
}
