#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, n, t, c, r, j;
  char a;
  string s;
  cin >> t;
  while (t != 0) {
    cin >> s;
    sort(s.begin(), s.end());
    a = s[0];
    r = 0;
    j = 0;
    c = 0;
    if (s[0] != s[1]) {
      c = 1;
    }
    for (i = 1; i < s.length() - 1; i++) {
      if (a == s[i] && j == 0) {
        r = r + 1;
        j = j + 1;
      } else if (a != s[i] && s[i] != s[i + 1]) {
        a = s[i];
        j = 0;
        c = c + 1;
      } else if (a != s[i] && s[i] == s[i + 1]) {
        a = s[i];
        j = 0;
      }
    }
    if (a != s[i]) {
      c = c + 1;
    }
    if (a == s[i] && j == 0) {
      r = r + 1;
    }
    if (s.length() == 1) {
      cout << 0 << endl;
    } else {
      cout << r + (c / 2) << endl;
    }
    t = t - 1;
  }
}
