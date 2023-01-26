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
long long dp[200005][3], n, m;
pair<long long, long long> p[200005];
long long a[200005];
vector<pair<long long, long long> > v[200005];
pair<long long, long long> lst[200005];
void solve() {
  io >> n >> m;
  for (long long i = 1; i <= n; i++) io >> a[i];
  sort(a + 1, a + n + 1);
  for (long long i = 0; i <= n; i++) v[i].clear();
  for (long long i = 1; i <= m; i++) {
    io >> p[i].first >> p[i].second;
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
    if (i)
      while (pos <= m && p[pos].first <= a[i - 1]) pos++;
    while (pos <= m && p[pos].second < a[i]) {
      v[i - 1].emplace_back(p[pos]);
      pos++;
    }
  }
  for (long long i = 0; i <= n; i++) {
    if (!v[i].empty()) {
      lst[i + 1] = v[i].back();
    } else
      lst[i + 1].first = lst[i + 1].second = a[i + 1];
  }
  if (v[0].empty()) {
    dp[1][0] = dp[1][1] = dp[1][2] = 0;
  } else {
    dp[1][0] = (a[1] - v[0][0].second) * 2;
    dp[1][2] = dp[1][0] - (a[1] - lst[1].second);
    if (v[0].size() != 1)
      dp[1][1] = max(0ll, dp[1][0] - (a[1] - lst[1].first));
    else
      dp[1][1] = dp[1][2];
  }
  for (long long i = 2; i <= n; i++) {
    if (v[i - 1].empty()) {
      dp[i][0] = dp[i][1] = dp[i][2] =
          min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
    } else {
      dp[i][0] =
          min({dp[i - 1][0] + (v[i - 1].back().first - a[i - 1]),
               dp[i - 1][1] + (v[i - 1].back().first - lst[i - 1].first),
               dp[i - 1][2] + (v[i - 1].back().first - lst[i - 1].second)});
      dp[i][2] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) +
                 (a[i] - v[i - 1][0].second) * 2 -
                 (a[i] - v[i - 1].back().second);
      dp[i][1] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) +
                 (a[i] - v[i - 1][0].second) * 2 -
                 (a[i] - max(v[i - 1].back().first, v[i - 1][0].second));
      for (long long j = 0; j < v[i - 1].size(); j++) {
        if (j == v[i - 1].size() - 1) {
        } else {
          dp[i][1] = min(
              dp[i][1],
              min({dp[i - 1][0] + (v[i - 1][j].first - a[i - 1]),
                   dp[i - 1][1] + (v[i - 1][j].first - lst[i - 1].first),
                   dp[i - 1][2] + (v[i - 1][j].first - lst[i - 1].second)}) +
                  max((a[i] - v[i - 1][j + 1].second) * 2 -
                          (a[i] - lst[i].first),
                      0ll));
          dp[i][2] = min(
              dp[i][2],
              min({dp[i - 1][0] + (v[i - 1][j].first - a[i - 1]),
                   dp[i - 1][1] + (v[i - 1][j].first - lst[i - 1].first),
                   dp[i - 1][2] + (v[i - 1][j].first - lst[i - 1].second)}) +
                  max((a[i] - v[i - 1][j + 1].second) * 2 -
                          (a[i] - lst[i].second),
                      0ll));
        }
      }
    }
  }
  if (v[n].empty()) {
    io << min({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
  } else {
    io << min({dp[n][0] + (v[n].back().first - a[n]),
               dp[n][1] + (v[n].back().first - lst[n].first),
               dp[n][2] + (v[n].back().first - lst[n].second)})
       << '\n';
  }
}
signed main() {
  io.init();
  long long t;
  io >> t;
  while (t--) solve();
  io.out();
  return 0;
}
