#include <bits/stdc++.h>
using namespace std;
string s, p;
int t, a, b, rjes;
int funk() {
  for (int i = 0; i < 10; i++) {
    if (p[i] == '1') {
      if (i % 2 == 0) {
        a++;
        if ((10 - i) / 2 + b < a) return i;
      } else {
        b++;
        if ((10 - i) / 2 + a < b) return i;
      }
    } else {
      if (i % 2 == 0) {
        if ((9 - i) / 2 + a < b) return i;
      } else {
        if ((9 - i) / 2 + b < a) return i;
      }
    }
  }
  return 9;
}
int main() {
  cin >> t;
  while (t) {
    cin >> s;
    a = b = 0;
    for (int i = 0; i < 10; i++) {
      p[i] = s[i];
      if (s[i] == '?') {
        if (i % 2 == 0)
          p[i] = '1';
        else
          p[i] = '0';
      }
    }
    rjes = funk();
    a = b = 0;
    for (int i = 0; i < 10; i++) {
      p[i] = s[i];
      if (s[i] == '?') {
        if (i % 2 == 0)
          p[i] = '0';
        else
          p[i] = '1';
      }
    }
    rjes = min(rjes, funk());
    cout << rjes + 1 << endl;
    t--;
  }
}
