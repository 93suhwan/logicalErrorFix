#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
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
long long L[300005], R[300005];
long long cnt[300005], fa[300005], siz[300005];
bool down[300005], vis[300005];
long long n, m, k;
long long dp[300005];
long long get(long long x) { return (fa[x] == x) ? x : (fa[x] = get(fa[x])); }
bool merge(long long x, long long y) {
  x = get(x);
  y = get(y);
  if (x == y) return 0;
  fa[x] = y;
  siz[y] += siz[x];
  down[y] |= down[x];
  return 1;
}
signed main() {
  io.init();
  io >> n >> m >> k;
  for (long long i = 1; i <= k; i++) fa[i] = i, siz[i] = 1;
  for (long long i = 1; i <= n; i++) {
    long long len, x;
    io >> len >> x;
    for (long long j = 1; j < len; j++) {
      long long y;
      io >> y;
      if (!R[x]) {
        if (!merge(x, y)) {
          down[x] = down[y] = 1;
        }
      }
      merge(x, y);
      if (R[x] && R[x] != y) {
        down[x] = 1;
      }
      if (L[y] && L[y] != x) {
        down[y] = 1;
      }
      R[x] = y;
      L[y] = x;
      x = y;
    }
  }
  for (long long i = 1; i <= k; i++) down[get(i)] |= down[i];
  for (long long i = 1; i <= k; i++)
    if (!vis[fa[i]] && !down[fa[i]]) {
      cnt[siz[fa[i]]]++;
      vis[fa[i]] = 1;
    }
  vector<long long> v;
  for (long long i = 1; i <= m; i++)
    if (cnt[i]) {
      v.emplace_back(i);
    }
  dp[0] = 1;
  long long mod = 998244353;
  for (long long i = 1; i <= m; i++) {
    for (auto u : v)
      if (u <= i) {
        dp[i] = (1ll * dp[i - u] * cnt[u] + dp[i]) % mod;
      }
  }
  cout << dp[m];
  return 0;
}
