#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    if (n % 2 == 1) {
      cout << "NO\n";
    } else {
      bool ok = true;
      for (int i = 0, j = n / 2; i < n / 2, j < n; ++i, ++j) {
        if (s[i] != s[j]) {
          ok = false;
        }
      }
      if (!ok) {
        cout << "No\n";
      } else {
        cout << "YEs\n";
      }
    }
  }
}
