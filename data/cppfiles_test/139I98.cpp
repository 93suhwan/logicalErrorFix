#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long a = s.size();
    if (a % 2 != 0) {
      cout << "NO\n";
      continue;
    }
    for (long long i = 0; i < a / 2; i++) {
      if (s[i] != s[a / 2 + i]) {
        cout << "NO\n";
        continue;
      }
    }
    cout << "YES\n";
  }
}
