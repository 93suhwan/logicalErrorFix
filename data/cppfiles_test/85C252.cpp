#include <bits/stdc++.h>
using namespace std;
int main() {
  long t;
  cin >> t;
  for (long it = 0; it < t; it++) {
    string s;
    cin >> s;
    int i = 0;
    for (; i < s.length() - 1; i++) {
      if (s[i] != s[i + 1]) break;
    }
    if (i == s.length() - 1) {
      if (s[0] == '0')
        cout << 1 << endl;
      else
        cout << 0 << endl;
    } else {
      int val = -1;
      for (i = 0; i < s.length(); i++) {
        if (val == -1 && s[i] == '0') {
          val = i;
        } else if (val > -1 && s[i] == '0') {
          if (val == i - 1)
            val = i;
          else {
            cout << 2 << endl;
            break;
          }
        }
      }
      if (i == s.length()) cout << 1 << endl;
    }
  }
}
