#include <bits/stdc++.h>
using namespace std;
char b[3];
int ans = 0, c[3];
void underscore(int x, int place) {
  if (place == 3) {
    if (c[0] && (c[1] * 10 + c[2]) % 25 == 0) ans++;
  } else {
    if (b[place] == 'X') {
      c[place] = x;
      underscore(x, place + 1);
    } else if (b[place] == '_') {
      for (int _ = 0; _ < 10; _++) {
        c[place] = _;
        underscore(x, place + 1);
      }
    } else {
      c[place] = b[place] - '0';
      underscore(x, place + 1);
    }
  }
}
int main() {
  string s;
  cin >> s;
  if (s.length() == 1) {
    if (s[0] == '0')
      cout << 1 << "\n";
    else
      cout << 0 << "\n";
  } else {
    int numof_ = 0;
    for (int i = 1; i < s.length() - 2; i++) {
      if (s[i] == '_') numof_++;
    }
    b[0] = s[0];
    b[1] = s[s.length() - 2];
    b[2] = s[s.length() - 1];
    if (b[0] != 'X' && b[1] != 'X' && b[2] != 'X')
      underscore(0, 0);
    else
      for (int x = 0; x < 10; x++) underscore(x, 0);
    cout << ans * pow(10, numof_) << "\n";
  }
}
