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
int a[1000005], lst[1000005][2], dp[1000005][2];
void solve() {
  int n;
  io >> n;
  for (int i = 1; i <= n; i++) io >> a[i];
  a[0] = 1e9;
  dp[0][0] = dp[0][1] = -1e9;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i][1] = 1e9;
    for (int j = 0; j < 2; j++) {
      int k = j ? (-a[i]) : a[i];
      if (k > a[i - 1]) {
        dp[i][j] = dp[i - 1][0];
        lst[i][j] = 0;
      }
      if (k > dp[i - 1][1] && dp[i][j] > -a[i - 1]) {
        dp[i][j] = -a[i - 1];
        lst[i][j] = 1;
      }
      if (k > dp[i - 1][0] && dp[i][j] > a[i - 1]) {
        dp[i][j] = a[i - 1];
        lst[i][j] = 0;
      }
      if (k > -a[i - 1] && dp[i - 1][1] < dp[i][j]) {
        dp[i][j] = dp[i - 1][1];
        lst[i][j] = 1;
      }
    }
  }
  if (dp[n][0] > n && dp[n][1] > n) {
    io << "NO\n";
    return;
  }
  int now = 0;
  if (dp[n][now] > n) now = 1;
  for (int i = n; i >= 1; i--) {
    if (now) a[i] = -a[i];
    now = lst[i][now];
  }
  io << "YES\n";
  for (int i = 1; i <= n; i++) io << a[i] << ' ';
  io << '\n';
}
signed main() {
  io.init();
  int T;
  io >> T;
  while (T--) solve();
  io.out();
  return 0;
}
