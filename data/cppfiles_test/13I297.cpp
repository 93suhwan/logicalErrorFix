#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    if (n & 1) {
      cout << "NO\n";
    } else {
      int a[3] = {0};
      for (int i = 0; i < n; i++) {
        a[s[i] - 'A']++;
      }
      if (a[0] % 2 == 0 && a[1] % 2 == 0 && a[2] % 2 == 0) {
        cout << "YES\n";
      } else {
        if (a[1] & 1) {
          if (a[0] + a[2] == a[1]) {
            cout << "YES\n";
          } else
            cout << "NO\n";
        } else
          cout << "NO\n";
      }
    }
  }
  return 0;
}
