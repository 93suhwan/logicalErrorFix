#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    bool flipped = false;
    bool flippedAgain = false;
    bool fail = false;
    bool two = false;
    long long prev = s[0];
    long long n = s.size();
    for (long long i = 1; i < n; i++) {
      if (flippedAgain && s[i] != prev) {
        fail = true;
        two = true;
        break;
      }
      if (flipped && s[i] != prev) {
        flippedAgain = true;
      }
      if (s[i] != prev) {
        flipped = true;
      }
      prev = s[i];
    }
    if (two) {
      cout << "2\n";
    } else if (fail == false &&
               (flippedAgain && (s[0] == '1' && s[n - 1] == '1'))) {
      cout << "1\n";
    } else if (flippedAgain) {
      cout << "2\n";
    } else if (s[0] == '0') {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }
  return 0;
}
