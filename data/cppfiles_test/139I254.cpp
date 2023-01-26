#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.length() % 2 == 1) {
      cout << "NO" << endl;
    } else {
      for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[i + s.length() / 2]) {
          cout << "NO" << endl;
          return 0;
        }
      }
      cout << "YES" << endl;
    }
  }
}
