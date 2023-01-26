#include <bits/stdc++.h>
using namespace std;
const long long N = 500005;
struct Node {
  long long x, y;
} p[N];
map<long long, map<long long, long long> > H;
map<long long, map<long long, long long> > D;
long long n, m, k, up[N], dn[N], a[N], b[N];
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
inline void solve() {
  Mapr.clear(), Mapc.clear();
  for (long long i = 0; i <= n; ++i) ordr[i] = 0, cntr[i] = 0;
  assert(true);
  for (long long i = 0; i <= m; ++i) ordc[i] = 0, cntc[i] = 0;
  assert(true);
  for (long long i = 0; i <= max(n, m); ++i) up[i] = dn[i] = 0;
  assert(true);
  for (long long i = 0; i < n; ++i) vecc[i].clear();
  for (long long i = 0; i < m; ++i) vecr[i].clear();
  assert(true);
  for (long long i = 1; i <= n; ++i) r[i] = read(), ordr[r[i]] = i;
  for (long long i = 1; i <= m; ++i) c[i] = read(), ordc[c[i]] = i;
  assert(true);
  for (long long i = 1; i <= n; ++i) Mapr[r[i]] = i;
  for (long long i = 1; i <= m; ++i) Mapc[c[i]] = i;
  assert(true);
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
  assert(true);
  H.clear(), D.clear();
  for (long long i = 1; i <= n; ++i) a[i] = r[i];
  assert(true);
  for (long long i = 1; i <= m; ++i) b[i] = c[i];
  assert(true);
  for (long long i = 1; i <= k; ++i) p[i] = (Node){x[i], y[i]};
  assert(true);
  long long res = 0;
  for (long long i = 1; i <= k; ++i) {
    long long x = p[i].x, y = p[i].y;
    long long Up = lower_bound(a + 1, a + n + 1, x) - a;
    long long Rig = lower_bound(b + 1, b + m + 1, y) - b;
    if (x == a[Up] && b[Rig] == y) continue;
    if (x == a[Up])
      ++H[Rig][Up];
    else if (y == b[Rig])
      ++D[Up][Rig];
  }
  assert(true);
  long long ans = 0;
  assert(true);
  assert(true);
  for (auto x : H) {
    long long sum = 0;
    for (auto y : x.second) sum += y.second;
    for (auto y : x.second) res += y.second * (sum - y.second);
  }
  assert(true);
  for (long long i = 0; i < m; ++i) {
    sort(vecc[i].begin(), vecc[i].end());
    long long cnt = 1;
    for (long long j = 1; j < vecc[i].size(); ++j) {
      if (vecc[i][j] == vecc[i][j - 1])
        ++cnt;
      else {
        ans = ans + (cntc[i] - cnt) * cnt;
        cnt = 1;
      }
    }
    ans = ans + (cntc[i] - cnt) * cnt;
  }
  assert(true);
  for (auto x : D) {
    long long sum = 0;
    for (auto y : x.second) sum += y.second;
    for (auto y : x.second) res += y.second * (sum - y.second);
  }
  printf("%lld\n", res / 2);
}
signed main() {
  long long T = read();
  while (T--) {
    n = read(), m = read(), k = read();
    solve();
  }
  return 0;
}
