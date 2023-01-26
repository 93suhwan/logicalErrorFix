#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
const long long N = 1e6 + 5;
const long long M = 6e5 + 5;
const long long SZ = 550;
const double eps = 1e-9;
const long long mod = 998244353;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void wt(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) wt(x / 10), putchar(10);
  putchar(x % 10 + '0');
}
long long ksm(long long x, long long y = mod - 2, long long z = mod) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % z;
    x = (x * x) % z;
    y >>= 1;
  }
  return ret;
}
long long vis[N], p[N], cnt;
void Init(long long n) {
  for (long long i = 2; i <= n; i++) {
    if (!vis[i]) p[++cnt] = i, vis[i] = i;
    for (long long j = 1; j <= cnt && p[j] * i <= n; j++) {
      vis[p[j] * i] = p[j];
      if (i % p[j] == 0) break;
    }
  }
}
long long n, q, m;
map<long long, bool> Map[N];
long long a[N], fa[N];
long long getfa(long long x) {
  if (x == fa[x]) return x;
  return fa[x] = getfa(fa[x]);
}
vector<long long> v[N];
long long tmp[N], CNT;
signed main() {
  m = 1e6 + 1;
  Init(m);
  n = read();
  q = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= m; i++) fa[i] = i;
  for (long long i = 1; i <= n; i++) {
    long long x = a[i];
    while (x != 1) v[vis[x]].push_back(a[i]), x /= vis[x];
  }
  for (long long i = 1; i <= m; i++)
    if (v[i].size() > 1)
      for (long long j = 1; j < v[i].size(); j++) {
        long long x = v[i][j - 1], y = v[i][j];
        x = getfa(x), y = getfa(y);
        if (x != y) fa[x] = y;
      }
  for (long long i = 1; i <= n; i++) {
    long long x = a[i] + 1;
    CNT = 0;
    while (x != 1) {
      long long y = vis[x];
      if (y != tmp[CNT]) tmp[++CNT] = y;
      if (v[y].size())
        Map[getfa(v[y][0])][getfa(a[i])] = Map[getfa(a[i])][getfa(v[y][0])] = 1;
      x /= vis[x];
    }
    for (long long i = 1; i < CNT; i++)
      if (v[tmp[i]].size())
        for (long long j = i + 1; j <= CNT; j++)
          if (v[tmp[j]].size())
            Map[getfa(v[tmp[i]][0])][getfa(v[tmp[j]][0])] =
                Map[getfa(v[tmp[j]][0])][getfa(v[tmp[i]][0])] = 1;
  }
  while (q--) {
    long long s, t;
    s = read();
    t = read();
    s = a[s], t = a[t];
    s = getfa(s), t = getfa(t);
    if (s == t)
      puts("0");
    else if (Map[s][t])
      puts("1");
    else
      puts("2");
  }
}
