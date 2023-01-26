#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long k = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    k = k * 10 + ch - '0';
    ch = getchar();
  }
  return k * f;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
const long long N = 2e5 + 10;
const long long MOD = 1e9 + 7;
long long nedge = 0, p[2 * N], nex[2 * N], head[2 * N], c[2 * N];
long long n, deep[N], Deep[N][2], dep[N], Dep[N][2];
long long s[N], f[N], vis[N], sum, rt, ans = 0, d[N], K;
long long maxx = 0, Maxx = 0, a[N];
inline void upd(long long &x, long long v) { x = (x + v) % MOD; }
inline void addedge(long long x, long long y, long long z) {
  p[++nedge] = y;
  c[nedge] = z;
  nex[nedge] = head[x];
  head[x] = nedge;
}
inline void dfs(long long x, long long fa) {
  s[x] = 1;
  f[x] = 0;
  for (long long k = head[x]; k; k = nex[k])
    if (p[k] != fa && !vis[p[k]]) {
      dfs(p[k], x);
      s[x] += s[p[k]];
      f[x] = max(f[x], s[p[k]]);
    }
  f[x] = max(f[x], sum - s[x]);
  if (f[x] < f[rt]) rt = x;
}
inline void dfss(long long x, long long fa, long long ps, long long v) {
  if (d[x] > K) return;
  maxx = max(maxx, d[x]);
  upd(v, a[x]);
  upd(deep[d[x]], v);
  upd(dep[d[x]], 1);
  for (long long k = head[x]; k; k = nex[k])
    if (p[k] != fa && !vis[p[k]]) {
      if (ps == c[k])
        d[p[k]] = d[x];
      else
        d[p[k]] = d[x] + 1;
      dfss(p[k], x, c[k], v);
    }
}
inline void cal(long long x) {
  upd(ans, a[x]);
  for (long long i = 0; i <= Maxx; i++) {
    Deep[i][0] = Deep[i][1] = 0;
    Dep[i][0] = Dep[i][1] = 0;
    deep[i] = dep[i] = 0;
  }
  d[x] = Maxx = 0;
  for (long long k = head[x]; k; k = nex[k])
    if (!vis[p[k]]) {
      for (long long i = 0; i <= Maxx; i++) deep[i] = dep[i] = 0;
      maxx = 0;
      d[p[k]] = 0;
      dfss(p[k], x, c[k], 0);
      for (long long i = 0; i <= maxx; i++) {
        upd(ans, ((deep[i] * Dep[min(Maxx, K - i)][c[k]]) % MOD +
                  (Deep[min(Maxx, K - i)][c[k]] * dep[i]) % MOD) %
                     MOD);
        upd(ans, dep[i] * Dep[min(Maxx, K - i)][c[k]] % MOD * a[x] % MOD);
        if (K - i - 1 >= 0) {
          upd(ans, ((deep[i] * Dep[min(Maxx, K - i - 1)][c[k] ^ 1]) % MOD +
                    (Deep[min(Maxx, K - i - 1)][c[k] ^ 1] * dep[i]) % MOD) %
                       MOD);
          upd(ans,
              dep[i] * Dep[min(Maxx, K - i - 1)][c[k] ^ 1] % MOD * a[x] % MOD);
        }
      }
      while (Maxx < maxx) {
        Maxx++;
        Deep[Maxx][0] = Deep[Maxx - 1][0];
        Deep[Maxx][1] = Deep[Maxx - 1][1];
        Dep[Maxx][0] = Dep[Maxx - 1][0];
        Dep[Maxx][1] = Dep[Maxx - 1][1];
      }
      for (long long i = 0; i <= Maxx; i++) {
        if (i) {
          upd(deep[i], deep[i - 1]);
          upd(dep[i], dep[i - 1]);
        }
        if (i == Maxx) upd(ans, (deep[i] + a[x] * dep[i] % MOD) % MOD);
        upd(Deep[i][c[k]], deep[i]);
        upd(Dep[i][c[k]], dep[i]);
      }
    }
}
inline void work(long long x) {
  vis[x] = 1;
  cal(x);
  for (long long k = head[x]; k; k = nex[k])
    if (!vis[p[k]]) {
      sum = s[p[k]];
      rt = 0;
      dfs(p[k], 0);
      work(rt);
    }
}
signed main() {
  n = read();
  K = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i < n; i++) {
    long long x = read(), y = read(), v = read();
    addedge(x, y, v);
    addedge(y, x, v);
  }
  f[0] = 1e9;
  sum = n;
  dfs(1, 0);
  work(rt);
  writeln(ans);
  return 0;
}
