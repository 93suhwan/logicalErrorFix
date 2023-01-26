#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long flips = 0;
    char prev = s[0];
    long long n = s.size();
    for (long long i = 1; i < n; i++) {
      if (s[i] != prev) {
        flips++;
      }
      prev = s[i];
    }
    if (flips == 0 && s[0] == '1') {
      cout << "0\n";
    } else if (flips <= 1) {
      cout << "1\n";
    } else if (flips == 2 && s[0] == '1') {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }
  return 0;
}
