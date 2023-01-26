#include <bits/stdc++.h>
using namespace std;
string to(long long x) {
  string s = "";
  while (x) {
    char c = x % 2 + '0';
    s += c;
    x /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}
bool check(string x, string y) {
  int m = x.length();
  int n = y.length();
  if (m > n) {
    return 0;
  }
  bool can = 0;
  for (int i = 0; i <= n - m; i++) {
    bool ok = 1;
    for (int j = 0; j < m; j++) {
      if (x[j] != y[i + j]) {
        ok = 0;
        break;
      }
    }
    for (int j = 0; j <= i - 1; j++) {
      if (y[j] != '1') {
        ok = 0;
        break;
      }
    }
    for (int j = i + m; j <= n - 1; j++) {
      if (y[j] != '1') {
        ok = 0;
        break;
      }
    }
    if (ok == 1) {
      can = 1;
      break;
    }
  }
  if (can == 1) {
    return 1;
  } else {
    return 0;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long x, y;
  cin >> x >> y;
  string s1, s2 = "", t;
  s1 = to(x);
  int l = s1.length();
  bool ok = 0;
  for (int i = l - 1; i >= 0; i--) {
    if (ok == 0 && s1[i] == '0') {
      continue;
    } else {
      ok = 1;
      s2 += s1[i];
    }
  }
  reverse(s2.begin(), s2.end());
  t = to(y);
  string rs1 = s1, rs2 = s2;
  reverse(rs1.begin(), rs1.end());
  reverse(rs2.begin(), rs2.end());
  if (check(s1, t) || check(rs1, t) || check(s2, t) || check(rs2, t)) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
  return 0;
}
