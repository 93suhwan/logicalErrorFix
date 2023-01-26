#include <bits/stdc++.h>
using namespace std;
const long long N = 300005;
long long n, m, k, up[N], dn[N];
long long r[N], c[N], ordr[N], ordc[N];
long long x[N], y[N], cntr[N], cntc[N];
map<long long, long long> Mapr, Mapc;
vector<long long> vecr[N], vecc[N];
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
signed main() {
  long long T = read();
  while (T--) {
    n = read(), m = read(), k = read();
    Mapr.clear(), Mapc.clear();
    for (long long i = 1; i <= n; ++i) ordr[i] = 0, cntr[i] = 0;
    for (long long i = 1; i <= m; ++i) ordc[i] = 0, cntc[i] = 0;
    for (long long i = 1; i <= n; ++i) r[i] = read(), ordr[r[i]] = i;
    for (long long i = 1; i <= m; ++i) c[i] = read(), ordc[c[i]] = i;
    for (long long i = 1; i <= n; ++i) Mapr[r[i]] = i;
    for (long long i = 1; i <= m; ++i) Mapc[c[i]] = i;
    for (long long i = 0; i < n; ++i) vecc[i].clear();
    for (long long i = 0; i < m; ++i) vecr[i].clear();
    for (long long i = 1; i <= k; ++i) {
      x[i] = read(), y[i] = read();
      if ((ordr[x[i]]) && (ordc[y[i]])) continue;
      if (ordr[x[i]]) {
        up[i] = (*(Mapc.lower_bound(y[i]))).second, dn[i] = up[i] - 1;
        ++cntc[dn[i]];
        vecc[dn[i]].push_back(x[i]);
      } else {
        up[i] = (*(Mapr.lower_bound(x[i]))).second, dn[i] = up[i] - 1;
        ++cntr[dn[i]];
        vecr[dn[i]].push_back(y[i]);
      }
    }
    long long ans = 0;
    for (long long i = 0; i < n; ++i)
      if (cntc[i] > 0) ans += cntc[i] * (cntc[i] - 1) / 2;
    for (long long i = 0; i < m; ++i)
      if (cntr[i] > 0) ans += cntr[i] * (cntr[i] - 1) / 2;
    for (long long i = 0; i < n; ++i) {
      sort(vecr[i].begin(), vecr[i].end());
      long long cnt = 1;
      for (long long j = 1; j < vecr[i].size(); ++j) {
        if (vecr[i][j] == vecr[i][j - 1])
          ++cnt;
        else {
          if (cnt > 1) ans -= cnt * (cnt - 1) / 2;
          cnt = 1;
        }
      }
      if (cnt > 1) ans -= cnt * (cnt - 1) / 2;
    }
    for (long long i = 0; i < m; ++i) {
      sort(vecc[i].begin(), vecc[i].end());
      long long cnt = 1;
      for (long long j = 1; j < vecc[i].size(); ++j) {
        if (vecc[i][j] == vecc[i][j - 1])
          ++cnt;
        else {
          if (cnt > 1) ans -= cnt * (cnt - 1) / 2;
          cnt = 1;
        }
      }
      if (cnt > 1) ans -= cnt * (cnt - 1) / 2;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
