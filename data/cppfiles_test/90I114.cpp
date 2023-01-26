#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
long long a[1000003];
pair<long long, long long> b[1000003], tmp[1000003];
bool cmp(pair<long long, long long> A, pair<long long, long long> B) {
  if (A.first != B.first) return A.first < B.first;
  return A.second > B.second;
}
long long l[1000003], r[1000003];
long long f[1000003][2][2];
signed main() {
  for (long long T = read(); T--;) {
    long long n = read() + 1, o = read();
    a[1] = -1e12;
    for (long long i = 2; i <= n; ++i) a[i] = read();
    a[++n] = 1e12;
    sort(a + 1, a + n + 1);
    for (long long i = 1; i <= o; ++i) {
      b[i].first = read(), b[i].second = read();
      long long L = lower_bound(a + 1, a + n + 1, b[i].first) - a,
                R = upper_bound(a + 1, a + n + 1, b[i].second) - a;
      if (L < R) --i, --o;
    }
    sort(b + 1, b + o + 1, cmp);
    long long m = 0;
    for (long long i = 1; i <= o; ++i) {
      while (m && tmp[m].second >= b[i].second) --m;
      ++m, tmp[m] = b[i];
    }
    for (long long i = 1; i <= m; ++i) b[i] = tmp[i];
    for (long long i = 1; i <= n; ++i) l[i] = r[i] = 0;
    for (long long i = 1, pos = 0; i <= m; ++i) {
      long long x = lower_bound(a + 1, a + n + 1, b[i].first) - a;
      if (!l[x])
        l[x] = r[x] = i;
      else
        r[x] = i;
    }
    for (long long i = 2; i <= n; ++i) {
      for (long long p = 0; p <= 1; ++p)
        for (long long q = 0; q <= 1; ++q) f[i][p][q] = 1e18;
      for (long long p = 0; p <= 1; ++p)
        for (long long q = 0; q <= 1; ++q)
          for (long long rr = 0; rr <= 1; ++rr)
            if (!l[i]) {
              f[i][q][rr] = f[i - 1][p][q ^ 1];
            } else {
              for (long long t = l[i] + 1; t <= r[i]; ++t) {
                f[i][q][rr] =
                    min(f[i][q][rr], f[i - 1][p][q ^ 1] +
                                         (q + 1) * (b[t - 1].first - a[i - 1]) +
                                         (rr + 1) * (a[i] - b[t].second));
              }
              f[i][q][rr] =
                  min(f[i][q][rr],
                      f[i - 1][p][q ^ 1] + (rr + 1) * (a[i] - b[l[i]].second));
              f[i][q][rr] =
                  min(f[i][q][rr], f[i - 1][p][q ^ 1] +
                                       (q + 1) * (b[r[i]].first - a[i - 1]));
            }
    }
    long long Ans = 1e18;
    for (long long p = 0; p <= 1; ++p)
      for (long long q = 0; q <= 1; ++q) Ans = min(Ans, f[n][p][q]);
    printf("%lld\n", Ans);
  }
  return 0;
}
