#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
const long long N = 2e5 + 5, mod = 1e9 + 7, INF = 1e9;
long long value[N], n, k, a[N], head[N], tot;
struct edge {
  long long link, next, val;
} e[N << 1];
inline void add_edge(long long u, long long v, long long w) {
  e[++tot] = (edge){v, head[u], w};
  head[u] = tot;
}
inline void insert(long long u, long long v, long long w) {
  add_edge(u, v, w);
  add_edge(v, u, w);
}
inline void init() {
  n = read();
  k = read();
  for (long long i = 1; i <= n; i++) value[i] = read();
  for (long long i = 1; i < n; i++) {
    long long u = read(), v = read(), w = read();
    insert(u, v, w);
  }
}
bool vis[N];
long long All, sz[N], fa[N], rt, mn;
void getroot(long long u, long long par) {
  fa[u] = par;
  sz[u] = 1;
  long long tmp = 0;
  for (long long i = head[u]; i; i = e[i].next) {
    long long v = e[i].link;
    if (!vis[v] && v != par) {
      getroot(v, u);
      sz[u] += sz[v];
      tmp = max(tmp, sz[v]);
    }
  }
  tmp = max(tmp, All - sz[u]);
  if (tmp < mn) mn = tmp, rt = u;
}
struct node {
  long long tic, v;
} q[N];
long long ans, b[N][2];
void dfs(long long u, long long par, long long pre, long long w, long long d) {
  q[++tot] = (node){w, d};
  for (long long i = head[u]; i; i = e[i].next) {
    long long v = e[i].link;
    if (v != par && !vis[v]) {
      dfs(v, u, e[i].val, w + (e[i].val ^ pre), d + value[v]);
    }
  }
}
struct BIT {
  long long bit[2][N];
  inline long long lowbit(long long x) { return x & (-x); }
  inline void update(long long opt, long long x, long long v) {
    x++;
    for (; x <= n; x += lowbit(x)) (bit[opt][x] += v + mod) %= mod;
  }
  inline long long query(long long opt, long long x) {
    if (x < 0) return 0;
    long long sum = 0;
    x++;
    for (; x; x -= lowbit(x)) (sum += bit[opt][x]) %= mod;
    return sum;
  }
  inline void clear(long long opt, long long x) {
    x++;
    for (; x <= n; x += lowbit(x)) bit[opt][x] = 0;
  }
} T1, T2;
inline void calc(long long u) {
  long long cnt = 0, Son = 0;
  for (long long i = head[u]; i; i = e[i].next) {
    long long v = e[i].link;
    if (!vis[v]) {
      tot = 0;
      dfs(v, u, e[i].val, 0, value[v]);
      for (long long j = 1; j <= tot; j++) {
        ans = (ans +
               q[j].v *
                   (T1.query(e[i].val, k - q[j].tic) +
                    T1.query(e[i].val ^ 1, k - q[j].tic - 1)) %
                   mod +
               T2.query(e[i].val, k - q[j].tic) +
               T2.query(e[i].val ^ 1, k - q[j].tic - 1)) %
              mod;
        if (q[j].tic <= k) (ans += q[j].v + value[u]) %= mod;
      }
      for (long long j = 1; j <= tot; j++) {
        T1.update(e[i].val, q[j].tic, 1);
        T2.update(e[i].val, q[j].tic, q[j].v + value[u]);
        b[++cnt][0] = e[i].val, b[cnt][1] = q[j].tic;
      }
    }
  }
  (ans += value[u]) %= mod;
  for (long long i = 1; i <= cnt; i++) {
    T1.clear(b[i][0], b[i][1]), T2.clear(b[i][0], b[i][1]);
  }
}
void divide(long long u) {
  vis[u] = 1;
  calc(u);
  long long tmp = All;
  for (long long i = head[u]; i; i = e[i].next) {
    long long v = e[i].link;
    if (!vis[v]) {
      All = (fa[u] == v) ? tmp - sz[u] : sz[v];
      mn = INF;
      getroot(v, u);
      divide(rt);
    }
  }
}
inline void solve() {
  All = n;
  mn = INF;
  getroot(1, 0);
  divide(rt);
  writeln(ans);
}
signed main() {
  init();
  solve();
  return 0;
}
