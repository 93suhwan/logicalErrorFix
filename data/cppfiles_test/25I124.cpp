#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    bool found = false;
    string s = "", t = "";
    cin >> s;
    cin >> t;
    long long l1 = s.length();
    long long l2 = t.length();
    if (l2 == 1) {
      for (long long i = 0; i < l1; i++) {
        if (t[0] == s[i]) {
          found = true;
          break;
        }
      }
    }
    long long cnt = 0, j = 0;
    if (found == false) {
      for (long long i = 0; i < l1; i++) {
        if (s[i] == t[j]) {
          cnt++;
          j++;
        }
        if (cnt == l2) {
          found = true;
          break;
        }
      }
    }
    if (found == false && (j < l2 - 1)) {
      for (long long i = l1 - 2; i >= 0; i--) {
        if (s[i] == t[j]) {
          cnt++;
          j++;
        }
        if (cnt == l2) {
          found = true;
          break;
        }
      }
    }
    if (found == true) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
