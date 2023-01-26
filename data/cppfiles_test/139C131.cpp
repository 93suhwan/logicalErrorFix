#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long c = 0;
    string s;
    cin >> s;
    long long a = s.size();
    if (a % 2 != 0) {
      cout << "NO\n";
      continue;
    } else {
      for (long long i = 0; i < a / 2; i++) {
        if (s[i] != s[a / 2 + i]) {
          cout << "NO\n";
          c = 1;
          break;
        }
      }
      if (c == 0) cout << "YES\n";
    }
  }
}
