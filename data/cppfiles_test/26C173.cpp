#include <bits/stdc++.h>
using namespace std;
int mini(string s) {
  int a = 0, b = 0, ca = 5, cb = 5;
  int m = 0;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      a += s[i] == '1' ? 1 : 0;
      ca--;
    } else {
      b += s[i] == '1' ? 1 : 0;
      cb--;
    }
    m += 1;
    if ((a > b && (a - b) > cb) || (b > a && (b - a) > ca)) {
      break;
    }
  }
  return m;
}
void solve() {
  string c, c1 = "", c2 = "";
  cin >> c;
  for (int i = 0; i < 10; i++) {
    if (c[i] == '?') {
      c1 += i % 2 == 0 ? '1' : '0';
      c2 += i % 2 == 0 ? '0' : '1';
    } else {
      c1 += c[i];
      c2 += c[i];
    }
  }
  int a = mini(c1), b = mini(c2);
  cout << min(a, b) << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
