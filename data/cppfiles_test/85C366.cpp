#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const double eps = 1e-6;
struct inout {
  static const int ibufl = 1 << 25;
  char in_buf[ibufl + 5], out_buf[ibufl + 5], *inf, *ouf;
  void init() {
    fread(in_buf, 1, ibufl, stdin);
    inf = in_buf;
    ouf = out_buf;
  }
  inout& operator>>(int& a) {
    int fh = 1;
    while (!(isdigit(*inf) || *inf == '-')) ++inf;
    if (*inf == '-') fh = -1, ++inf;
    a = 0;
    while (isdigit(*inf)) {
      a = a * 10 + *inf - '0';
      ++inf;
    }
    a *= fh;
    return *this;
  }
  inout& operator>>(char& a) {
    while (*inf == ' ' || *inf == '\n') ++inf;
    a = *inf;
    ++inf;
    return *this;
  }
  inout& operator>>(char* a) {
    while (*inf == ' ' || *inf == '\n') ++inf;
    while (!(*inf == ' ' || *inf == '\n')) {
      *a = *inf;
      ++inf;
      ++a;
    }
    *a = '\0';
    return *this;
  }
  inout& operator>>(double& a) {
    int fh = 1;
    double s;
    while (!(isdigit(*inf) || *inf == '-')) ++inf;
    if (*inf == '-') fh = -1, ++inf;
    a = 0;
    while (isdigit(*inf)) {
      a = a * 10 + *inf - '0';
      ++inf;
    }
    if (*inf == '.') {
      s = 0.1;
      ++inf;
      while (isdigit(*inf)) {
        a += s * (*inf - '0');
        ++inf;
        s *= 0.1;
      }
    }
    a *= fh;
    return *this;
  }
  void writeint(int x) {
    if (x / 10) writeint(x / 10);
    *ouf = x % 10 + '0';
    ++ouf;
  }
  inout& operator<<(int a) {
    if (a < 0) {
      *ouf = '-';
      ++ouf;
      a = -a;
    }
    writeint(a);
    return *this;
  }
  static const int sz = 2;
  inout& operator<<(char a) {
    *ouf = a;
    ++ouf;
    return *this;
  }
  inout& operator<<(char* a) {
    while (*a) {
      *ouf = *a;
      ++ouf;
      ++a;
    }
    return *this;
  }
  inout& operator<<(double a) {
    if (a < -eps) {
      *ouf = '-';
      ++ouf;
      a = -a;
    }
    writeint((int)a);
    a -= (int)a;
    *ouf = '.';
    ++ouf;
    for (int i = 1; i <= sz; i++) {
      a = a * 10;
      *ouf = (int)a + '0';
      ++ouf;
      a -= (int)a;
    }
    return *this;
  }
  void out() { fwrite(out_buf, 1, ouf - out_buf, stdout); }
};
inout io;
string s;
void solve() {
  cin >> s;
  int cnt = 0;
  int lst = 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0' && lst) cnt++;
    lst = s[i] - '0';
  }
  cout << min(cnt, 2) << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
