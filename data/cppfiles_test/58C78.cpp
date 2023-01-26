#include <bits/stdc++.h>
using namespace std;
const int M = 400005;
const int MOD = 998244353;
long long read() {
  long long x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
long long T, n, m, fac[M], inv[M];
void init(long long n) {
  fac[0] = inv[0] = inv[1] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
  for (long long i = 2; i <= n; i++)
    inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
  for (long long i = 2; i <= n; i++) inv[i] = inv[i - 1] * inv[i] % MOD;
}
long long C(long long n, long long m) {
  if (n < m || m < 0) return 0;
  return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
namespace treap {
long long rt, cnt, ch[M][2], val[M], hp[M], tg[M];
void clear() {
  for (long long i = 1; i <= cnt; i++) ch[i][0] = ch[i][1] = val[i] = tg[i] = 0;
  rt = cnt = 0;
}
struct node {
  long long p[2];
  node() { p[0] = p[1] = 0; }
} emp;
void add(long long x, long long v) {
  if (!x) return;
  val[x] += v;
  tg[x] += v;
}
void down(long long x) {
  if (!tg[x]) return;
  add(ch[x][0], tg[x]);
  add(ch[x][1], tg[x]);
  tg[x] = 0;
}
node split(long long x, long long v) {
  if (!x) return emp;
  long long d = val[x] <= v;
  down(x);
  node y = split(ch[x][d], v);
  ch[x][d] = y.p[d ^ 1];
  y.p[d ^ 1] = x;
  return y;
}
long long merge(long long x, long long y) {
  if (!x || !y) return x + y;
  if (hp[x] < hp[y]) {
    down(x);
    ch[x][1] = merge(ch[x][1], y);
    return x;
  }
  down(y);
  ch[y][0] = merge(x, ch[y][0]);
  return y;
}
long long get(long long x) {
  cnt++;
  val[cnt] = x;
  hp[cnt] = rand();
  return cnt;
}
long long find(long long x) {
  node t = split(rt, x - 1), w = split(t.p[1], x);
  if (w.p[0] > 0) {
    add(w.p[0], 1);
    add(w.p[1], 1);
    rt = merge(t.p[0], merge(w.p[0], w.p[1]));
    return 0;
  }
  w.p[0] = merge(get(x), w.p[1]);
  add(w.p[0], 1);
  rt = merge(t.p[0], w.p[0]);
  return 1;
}
}  // namespace treap
signed main() {
  T = read();
  init(4e5);
  while (T--) {
    n = read();
    m = read();
    treap::clear();
    long long ans = 0;
    for (long long i = 1; i <= m; i++) {
      long long a = read(), b = read();
      if (treap::find(b)) ans++;
    }
    printf("%lld\n", C(2 * n - ans - 1, n));
  }
}
