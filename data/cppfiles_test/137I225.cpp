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
void FuN(string s, string res) {
  if (s == res) {
    fg = 1;
    return;
  }
  string temp = s;
  reverse(temp.begin(), temp.end());
  if (temp == res) {
    fg = 1;
    return;
  }
  if (s.size() > res.size() + 1) return;
  FuN(s + "1", res);
  FuN("1" + s, res);
}
void Solve(int t) {
  long long x, y;
  cin >> x >> y;
  string s, s2;
  s = To_string(x);
  s2 = To_string(y);
  FuN(s, s2);
  while (s.back() == '0' && !fg) {
    s.resize(s.size() - 1);
    FuN(s, s2);
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
