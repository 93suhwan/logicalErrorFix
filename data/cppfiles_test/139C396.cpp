#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, t, n;
  string s, s1, s2;
  cin >> t;
  while (t--) {
    cin >> s;
    n = s.size();
    if (n % 2 != 0) {
      cout << "NO\n";
    } else {
      int i = 0;
      for (i; i < n / 2; i++) {
        s1 += s[i];
      }
      for (i; i < n; i++) {
        s2 += s[i];
      }
      if (s1 == s2) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
    s1.clear();
    s2.clear();
  }
  return 0;
}
