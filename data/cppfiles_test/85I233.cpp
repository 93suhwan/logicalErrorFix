#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int p = 1; p <= t; p++) {
    string s;
    cin >> s;
    int n = s.length();
    int count = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '1') {
        count = 1;
      }
    }
    if (count == 1) {
      for (int i = 0; i < n; ++i) {
        if (s[i] == '0') count = 2;
      }
    }
    if (s[0] == '1' && s[n - 1] == '1') {
      if (count == 2) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    } else if (s[0] == '0' && s[n - 1] == '0') {
      if (count == 2) {
        cout << 2 << endl;
      } else {
        cout << 1 << endl;
      }
    } else {
      if (count == 2) {
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }
  return 0;
}
