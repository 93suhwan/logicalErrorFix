#include <bits/stdc++.h>
using namespace std;
long long t = 1, n, m, k, q, l, r, a[400009], b[200009], pre[400009],
          sz[400009], id[400009], pos[200009], ans[200009], tim[400009],
          wtf[400009], u, v, x, y, z, mod = 1e9 + 7;
string s;
vector<long long> to[200009];
struct st {
  long long x, y;
} p[200009];
bool cmp(const st &a, const st &b) { return a.x < b.x; }
long long find(long long x) { return x == id[x] ? x : id[x] = find(id[x]); }
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0')
    s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return s * w;
}
long long qp(long long x, long long y) {
  long long a = 1, b = x;
  while (y) {
    if (y & 1) a = a * b % mod;
    b = b * b % mod, y >>= 1;
  }
  return a;
}
int main() {
  while (t--) {
    n = read(), m = read(), q = read();
    for (long long i = 1; i <= n; i += 1) a[i] = b[i] = read();
    for (long long i = 1; i <= m; i += 1) a[i + n] = read();
    sort(a + 1, a + n + m + 1), sort(b + 1, b + n + 1);
    for (long long i = 1; i <= n + m; i += 1)
      pre[i] = pre[i - 1] + a[i], id[i] = i;
    long long cur = 1;
    for (long long i = 1; i <= n + m; i += 1)
      if (a[i] == b[cur]) sz[i] = 1, cur += 1;
    for (long long i = 1; i <= q; i += 1)
      p[i] = (st){read(), i}, wtf[i] = p[i].x;
    sort(p + 1, p + q + 1, cmp), sort(wtf + 1, wtf + q + 1);
    for (long long i = 1; i <= n + m - 1; i += 1)
      to[lower_bound(wtf + 1, wtf + q + 1, a[i + 1] - a[i]) - wtf].emplace_back(
          i);
    long long asd = 0;
    for (long long i = 1; i <= n; i += 1) asd += b[i];
    for (long long i = 1; i <= q; i += 1) {
      for (long long j = 0; j < to[i].size(); j += 1) {
        long long now = to[i][j];
        long long qwq = find(now), awa = find(now + 1);
        if (qwq == awa) continue;
        asd -= pre[qwq] - pre[qwq - sz[qwq]],
            asd -= pre[awa] - pre[awa - sz[awa]];
        id[qwq] = awa, sz[awa] += sz[qwq], sz[qwq] = 0;
        asd += pre[awa] - pre[awa - sz[awa]];
      }
      ans[p[i].y] = asd;
    }
    for (long long i = 1; i <= q; i += 1) printf("%lld\n", ans[i]);
  }
  return 0;
}
