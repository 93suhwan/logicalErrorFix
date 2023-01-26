#include <bits/stdc++.h>
const int N = 2e5 + 5;
int fa[N << 1], n, m;
int Head[N], Nxt[N << 1], Ver[N << 1], Val[N << 1], cnt_edge;
int fr[N];
int uu[N], vv[N], ans[N];
int dep[N];
int pree[N];
inline int Read() {
  char ch;
  int f = 1;
  while ((ch = getchar()) < '0' || ch > '9')
    if (ch == '-') f = -1;
  int x = ch ^ 48;
  while ((ch = getchar()) >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48);
  return x * f;
}
inline void Print(const int x, const char ch = '\n', const bool flg = 1) {
  if (x < 0) {
    putchar('-');
    return Print(-x, ch, flg);
  }
  if (x >= 10) Print(x / 10, ch, 0);
  putchar(x % 10 + 48);
  if (flg) putchar(ch);
  return;
}
inline void Add(const int u, const int v, const int value) {
  ++cnt_edge;
  Ver[cnt_edge] = v;
  Val[cnt_edge] = value;
  Nxt[cnt_edge] = Head[u];
  Head[u] = cnt_edge;
  return;
}
inline void Add_Edge(const int u, const int v, const int value) {
  Add(u, v, value);
  Add(v, u, value);
  return;
}
inline int Get(int x) {
  if (x == -1) return -1;
  int ss = 0;
  while (x) {
    ss ^= (x & 1);
    x >>= 1;
  }
  return ss;
}
inline void Init() {
  cnt_edge = -1;
  n = Read();
  m = Read();
  for (register int i = 1; i <= n; i++) Head[i] = -1;
  for (register int i = 1; i < n; i++) {
    uu[i] = Read();
    vv[i] = Read();
    ans[i] = Read();
    Add_Edge(uu[i], vv[i], Get(ans[i]));
  }
  return;
}
inline int Find(const int u) { return fa[u] == u ? u : fa[u] = Find(fa[u]); }
inline void Merge(const int u, const int v) {
  int fu = Find(u), fv = Find(v);
  fa[fu] = fv;
  return;
}
inline void Dfs(const int u, const int fa) {
  dep[u] = dep[fa] + 1;
  for (register int i = Head[u]; i != -1; i = Nxt[i]) {
    int v = Ver[i], value = Val[i];
    if (v == fa) continue;
    if (value != -1) {
      if (value) {
        Merge(u, v + n);
        Merge(v, u + n);
      } else {
        Merge(u, v);
        Merge(u + n, v + n);
      }
    }
    fr[v] = i;
    Dfs(v, u);
  }
  return;
}
inline void Solve() {
  for (register int i = 1; i <= n; i++) {
    fa[i] = i;
    fa[i + n] = i + n;
  }
  Dfs(1, 0);
  for (register int i = 1; i <= m; i++) {
    int u = Read(), v = Read();
    int value = Read();
    if (value == 0) {
      Merge(u, v);
      Merge(u + n, v + n);
    } else {
      Merge(u + n, v);
      Merge(u, v + n);
    }
  }
  for (register int i = 1; i <= n; i++)
    if (Find(i) == Find(i + n)) {
      puts("NO");
      return;
    }
  puts("YES");
  for (register int i = 1; i <= n; i++) pree[i] = -1;
  for (register int i = 1; i <= n; i++) {
    if (pree[i] != -1) continue;
    int fi = Find(i), fj = Find(i + n);
    int ii = fi, jj = fj;
    if (ii > n) ii -= n;
    if (jj > n) jj -= n;
    if (pree[ii] == 0) {
      if (fi > n) {
        pree[i] = 1;
        continue;
      }
      pree[i] = 0;
      continue;
    }
    if (pree[ii] == 1) {
      if (fi > n) {
        pree[i] = 0;
        continue;
      }
      pree[i] = 1;
      continue;
    }
    if (pree[jj] == 0) {
      if (fj > n) {
        pree[i] = 0;
        continue;
      }
      pree[i] = 1;
      continue;
    }
    if (pree[jj] == 1) {
      if (fj > n) {
        pree[i] = 1;
        continue;
      }
      pree[i] = 0;
      continue;
    }
    pree[ii] = (fi > n);
    pree[i] = 0;
  }
  for (register int i = 1; i < n; i++) {
    if (ans[i] != -1)
      printf("%d %d %d\n", uu[i], vv[i], ans[i]);
    else
      printf("%d %d %d\n", uu[i], vv[i], (pree[uu[i]] != pree[vv[i]]));
  }
  return;
}
int T;
int main() {
  for (T = Read(); T; T--) {
    Init();
    Solve();
  }
  return 0;
}
