#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const double PI = 3.14159265358979;
int ab_num(string s) {
  int ab = 0;
  for (int j = 0; j < s.size() - 1; j++) {
    if (s[j] == 'a' && s[j + 1] == 'b') {
      ab++;
    }
  }
  return ab;
}
int ba_num(string s) {
  int ba = 0;
  for (int j = 0; j < s.size() - 1; j++) {
    if (s[j] == 'b' && s[j + 1] == 'a') {
      ba++;
    }
  }
  return ba;
}
int main() {
  int t, i, j, ab, ba, AB, BA, k;
  char h;
  string s;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> s;
    if (s.size() == 1 || s.size() == 2) {
      cout << s << endl;
    } else {
      ab = ab_num(s);
      ba = ba_num(s);
      if (ab == ba) {
        cout << s << endl;
      } else {
        for (k = 0; k < s.size(); k++) {
          h = s[k];
          s[k] = 'a';
          AB = ab_num(s);
          BA = ba_num(s);
          if (AB == BA) {
            cout << s << endl;
            break;
          } else {
            s[k] = 'b';
            AB = ab_num(s);
            BA = ba_num(s);
            if (AB == BA) {
              cout << s << endl;
              break;
            } else {
              s[k] = h;
            }
          }
        }
      }
    }
  }
}
