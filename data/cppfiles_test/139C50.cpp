#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.length() == 1) {
      cout << "NO"
           << "\n";
    } else if (s.length() % 2 != 0) {
      cout << "NO"
           << "\n";
    } else if (s.length() % 2 == 0) {
      int k;
      int count = 0;
      for (int i = 0; i < s.length() / 2; i++) {
        k = (s.length() / 2) + i;
        if (s[i] == s[k]) {
          count = 1;
        } else {
          count = 0;
          break;
        }
      }
      if (count == 1) {
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
