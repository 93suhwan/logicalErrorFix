#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
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
int n, a[200005], ans[200005];
char tap[200005];
int s[200005], top;
char c[200005];
signed main() {
  io.init();
  io >> n;
  for (int i = 1; i <= n; i++) io >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) io >> c[i];
  for (int i = 1; i <= n; i++) {
    if (c[i] != c[i - 1]) {
      tap[i] = c[i];
      ans[i] = i;
    } else {
      ans[i] = 1;
      s[i - 1] = 1;
      if (i & 1)
        tap[i] = c[i];
      else
        tap[i] = c[i] ^ 'L' ^ 'R';
    }
  }
  for (int i = n; i >= 1; i--) s[i] += s[i + 1];
  for (int i = 1; i <= n; i++) io << a[ans[i] + s[i]] << ' ' << tap[i] << '\n';
  io.out();
  return 0;
}
