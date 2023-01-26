#include <bits/stdc++.h>
using namespace std;
long long fg = 0;
string To_string(long long x) {
  string s;
  while (x != 0) {
    s += (x % 2) + '0';
    x /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}
void Solve(int t) {
  long long x, y, i, j;
  cin >> x >> y;
  string s, s2;
  s = To_string(x);
  s2 = To_string(y);
  for (i = 0; i <= 100; i++) {
    for (j = 1; j <= 100; j++) {
      string temp = s;
      for (int k = 1; k <= i; k++) {
        temp = "1" + temp;
      }
      for (int k = 1; k <= j; k++) {
        temp = temp + "1";
      }
      if (temp == s2) fg = 1;
      reverse(temp.begin(), temp.end());
      if (temp == s2) fg = 1;
    }
  }
  while (s.back() == '0') {
    s.resize(s.size() - 1);
  }
  for (i = 0; i <= 100; i++) {
    for (j = 0; j <= 100; j++) {
      string temp = s;
      for (int k = 1; k <= i; k++) {
        temp = "1" + temp;
      }
      for (int k = 1; k <= j; k++) {
        temp = temp + "1";
      }
      if (temp == s2) fg = 1;
      reverse(temp.begin(), temp.end());
      if (temp == s2) fg = 1;
    }
  }
  if (fg)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  int t, T = 1;
  for (t = 1; t <= T; t++) {
    Solve(t);
  }
  return 0;
}
