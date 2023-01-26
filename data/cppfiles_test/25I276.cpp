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
    } else {
      for (long long i = 0; i < l1; i++) {
        if (s[i] == t[0]) {
          if (i == (l1 - 1)) {
            break;
          }
          long long k = i + 1, j = 1;
          while (j <= (l2 - 1) && (k < l1 && found == false)) {
            if (t[j] == s[k]) {
              if (j == (l2 - 1)) {
                found = true;
                break;
              }
              k++;
              j++;
            } else {
              break;
            }
          }
          long long p = k - 2;
          while (j <= (l2 - 1) && (k >= 0 && found == false)) {
            if (t[j] == s[p]) {
              if (j == (l2 - 1)) {
                found = true;
                break;
              }
              p--;
              j++;
            } else {
              break;
            }
          }
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
