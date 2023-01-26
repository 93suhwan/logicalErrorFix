#include <bits/stdc++.h>
using namespace std;
const int NR = 2e5 + 10;
void Min(int& x, int y) { x = min(x, y); }
void Max(int& x, int y) { x = max(x, y); }
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n, m;
int to[NR << 1], nxt[NR << 1], val[NR << 1], head[NR], tot = 1;
void add(int x, int y, int z) {
  to[tot] = y, val[tot] = z, nxt[tot] = head[x], head[x] = tot++;
}
int cnt, FFF;
int vs[NR], rec[NR], rl[NR];
void init() {
  cnt = FFF = 0;
  for (int i = 1; i <= n; i++) head[i] = vs[i] = 0, rl[i] = 0, rec[i] = -1;
  tot = 1;
}
vector<int> v[NR];
struct Col {
  bool vis[NR], f[NR];
  int to[NR << 1], nxt[NR << 1], col[NR << 1], head[NR], id[NR], tott;
  void clear() {
    for (int i = 1; i <= n; i++)
      v[i].clear(), head[i] = f[i] = vis[i] = id[i] = 0;
    tott = 1;
  }
  void add(int x, int y, int v) {
    to[tott] = y, nxt[tott] = head[x], col[tott] = v, head[x] = tott++;
  }
  void dfs(int x, int c) {
    if (vis[x]) return;
    vis[x] = 1;
    f[x] = c;
    v[cnt].push_back(x);
    id[x] = cnt;
    for (int i = head[x]; i; i = nxt[i]) {
      int y = to[i];
      dfs(y, c ^ col[i]);
    }
  }
  void build() {
    for (int i = 1; i <= n; i++)
      if (!vis[i]) cnt++, dfs(i, 0);
  }
} T;
int lowbit(int x) { return (x & -x); }
int calc(int x) {
  int cnt = 0;
  while (x) x ^= lowbit(x), cnt++;
  return cnt & 1;
}
void dfs(int x, int fa_) {
  for (int i = head[x]; i; i = nxt[i]) {
    int y = to[i];
    if (y == fa_) continue;
    if (val[i] != -1) T.add(x, y, calc(val[i])), T.add(y, x, calc(val[i]));
    dfs(y, x);
  }
}
struct Orz {
  int to[NR << 1], nxt[NR << 1], val[NR << 1], head[NR], tottt;
  void clear() {
    for (int i = 1; i <= n; i++) head[i] = 0;
    tottt = 1;
  }
  void add(int x, int y, int z) {
    to[tottt] = y, val[tottt] = z, nxt[tottt] = head[x], head[x] = tottt++;
  }
  void dfs(int x, int col) {
    if (vs[x] && col == rec[x]) return;
    if (vs[x] && col != rec[x]) {
      FFF = 1;
      return;
    }
    vs[x] = 1;
    rec[x] = col;
    for (int i = head[x]; i; i = nxt[i]) {
      int y = to[i];
      dfs(y, col ^ val[i]);
    }
  }
  void build() {
    for (int i = 1; i <= cnt; i++)
      if (!vs[i]) dfs(i, 0);
  }
} S;
int X[NR], Y[NR], Z[NR];
void work() {
  n = read(), m = read();
  init();
  for (int i = 1; i < n; i++) {
    X[i] = read(), Y[i] = read(), Z[i] = read();
    add(X[i], Y[i], Z[i]), add(Y[i], X[i], Z[i]);
  }
  T.clear();
  dfs(1, 0);
  T.build();
  S.clear();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read(), p = read();
    S.add(T.id[x], T.id[y], p != (T.f[x] != T.f[y]));
    S.add(T.id[y], T.id[x], p != (T.f[x] != T.f[y]));
  }
  S.build();
  if (FFF) {
    puts("NO");
    return;
  }
  for (int i = 1; i <= cnt; i++) {
    int siz = v[i].size();
    for (int j = 0; j < siz; j++) {
      rl[v[i][j]] = (rec[i] ^ T.f[v[i][j]]);
    }
  }
  puts("YES");
  for (int i = 1; i < n; i++) {
    printf("%d %d %d\n", X[i], Y[i],
           (Z[i] == -1) ? (rl[X[i]] ^ rl[Y[i]]) : Z[i]);
  }
}
int main() {
  int T = read();
  while (T--) work();
  return 0;
}
