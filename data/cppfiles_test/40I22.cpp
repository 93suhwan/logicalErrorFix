#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[1000000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  char c = getchar();
  long long su = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) su = su * 10 + c - '0';
  return su * f;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writesp(long long x) { write(x), putchar(' '); }
inline void writeln(long long x) {
  write(x);
  putchar('\n');
}
long long dep[600005], st[600005][2];
long long dis[600005];
long long ans;
long long fa[600005];
long long q;
long long n, m;
vector<long long> G[600005], E1[600005];
long long cnt;
pair<long long, long long> E[600005];
void ad(long long x, long long y) { G[x].push_back(y); }
long long gf(long long x) {
  if (x == fa[x]) return x;
  return fa[x] = gf(fa[x]);
}
void work(long long x, long long y) {
  vector<long long> g, g1;
  while (dep[x] != dep[y]) {
    if (dep[x] > dep[y])
      g.push_back(x), x = st[x][0];
    else
      g1.push_back(y), y = st[y][0];
  }
  while (x != y) {
    g1.push_back(y);
    g.push_back(x);
    x = st[x][0], y = st[y][0];
  }
  g.push_back(x);
  reverse(g1.begin(), g1.end());
  writeln(g.size() + g1.size());
  for (auto u : g) writesp(u);
  for (auto u : g1) writesp(u);
}
void dfs(long long k, long long fa) {
  dep[k] = dep[fa] + 1;
  st[k][0] = fa;
  for (auto u : G[k]) {
    if (u == fa) continue;
    if (dep[u]) continue;
    dfs(u, k);
    E1[k].push_back(u);
  }
}
void dfs1(long long k, long long fa) {
  long long x = 0;
  for (auto u : E1[k]) {
    dfs1(u, k);
    dis[k] ^= dis[u];
    if (dis[u]) x++;
    if (x >= 2) {
      ans++;
      x -= 2;
    }
  }
  if (x) ans++;
}
signed main() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; i++) fa[i] = i;
  for (long long i = 1; i <= m; i++) {
    long long x = read(), y = read();
    if (gf(x) != gf(y)) {
      ad(x, y);
      ad(y, x);
      fa[gf(x)] = gf(y);
    }
  }
  dfs(1, 0);
  q = read();
  while (q--) {
    long long x = read(), y = read();
    dis[x] ^= 1, dis[y] ^= 1;
    E[++cnt] = {x, y};
  }
  dfs1(1, 0);
  if (!ans) {
    puts("YES");
    for (long long i = 1; i <= cnt; i++)
      work(E[i].first, E[i].second), puts("");
  } else {
    puts("NO");
    writeln(ans);
  }
}
