#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    bool zero = false, one = false, bothSeparate = false;
    bool flipped = false;
    bool two = false;
    long long prev = s[0];
    for (long long i = 1; i < s.size(); i++) {
      if (flipped && s[i] != prev) {
        two = true;
        break;
      }
      if (s[i] != prev) {
        flipped = true;
      }
      prev = s[i];
    }
    if (two) {
      cout << "2\n";
    } else if (flipped) {
      cout << "1\n";
    } else if (s[0] == '0') {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }
  return 0;
}
