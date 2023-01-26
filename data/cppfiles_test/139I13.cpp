#include <bits/stdc++.h>
using namespace std;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    bool signal = true;
    if (n % 2 != 0) {
      cout << "NO" << endl;
    } else {
      int r = n / 2;
      for (int i = 0, j = r; i < r, j < n; i++, j++) {
        if (s[i] == s[j]) {
          signal = true;
        } else {
          signal = false;
        }
      }
      if (signal == true) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
