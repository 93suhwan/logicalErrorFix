#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const double eps = 1e-6;
struct inout {
  static const long long ibufl = 1 << 25;
  char in_buf[ibufl + 5], out_buf[ibufl + 5], *inf, *ouf;
  void init() {
    fread(in_buf, 1, ibufl, stdin);
    inf = in_buf;
    ouf = out_buf;
  }
  inout& operator>>(long long& a) {
    long long fh = 1;
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
    long long fh = 1;
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
  void writeint(long long x) {
    if (x / 10) writeint(x / 10);
    *ouf = x % 10 + '0';
    ++ouf;
  }
  inout& operator<<(long long a) {
    if (a < 0) {
      *ouf = '-';
      ++ouf;
      a = -a;
    }
    writeint(a);
    return *this;
  }
  static const long long sz = 2;
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
    writeint((long long)a);
    a -= (long long)a;
    *ouf = '.';
    ++ouf;
    for (long long i = 1; i <= sz; i++) {
      a = a * 10;
      *ouf = (long long)a + '0';
      ++ouf;
      a -= (long long)a;
    }
    return *this;
  }
  void out() { fwrite(out_buf, 1, ouf - out_buf, stdout); }
};
inout io;
long long dp[200005], n, m;
pair<long long, long long> p[200005];
long long a[200005];
long long l[200005], r[200005];
void solve() {
  io >> n >> m;
  for (long long i = 1; i <= n; i++) io >> a[i];
  sort(a + 1, a + n + 1);
  for (long long i = 1; i <= m; i++) {
    io >> p[i].first >> p[i].second;
    if ((*lower_bound(a + 1, a + n + 1, p[i].first)) <= p[i].second) i--, m--;
  }
  sort(p + 1, p + m + 1);
  reverse(p + 1, p + m + 1);
  long long nowm = 0, mini = 2e9;
  for (long long i = 1; i <= m; i++) {
    if (p[i].second >= mini) {
    } else {
      mini = p[i].second;
      p[++nowm] = p[i];
    }
  }
  m = nowm;
  sort(p + 1, p + m + 1);
  a[0] = -2e9;
  a[n + 1] = 2e9;
  long long pos = 1;
  for (long long i = 1; i <= n + 1; i++) {
    l[i - 1] = pos;
    while (pos <= m && p[pos].second < a[i]) {
      pos++;
    }
    r[i - 1] = pos - 1;
  }
  for (long long i = 1; i <= m; i++) dp[i] = 1e18;
  for (long long i = 1; i <= n; i++) {
    long long dp0 = 1e18, dp1 = 1e18;
    for (long long j = l[i - 1] - 1; j <= r[i - 1]; j++) {
      dp0 = min(dp0, dp[j] + (j == r[i - 1] ? 0 : (a[i] - p[j + 1].second)));
      dp1 =
          min(dp1, dp[j] + 2 * (j == r[i - 1] ? 0 : (a[i] - p[j + 1].second)));
    }
    for (long long j = l[i]; j <= r[i]; j++) {
      dp[j] = min(dp[j], dp0 + (p[j].first - a[i]) * 2);
      dp[j] = min(dp[j], dp1 + (p[j].first - a[i]));
    }
  }
  io << dp[m] << '\n';
}
signed main() {
  io.init();
  long long t;
  io >> t;
  while (t--) solve();
  io.out();
  return 0;
}
