#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
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
int n, m, fst[200100], nxt[200100 << 1], to[200100 << 1], cnt, ind[200100];
int rt[200100], ls[200100], rs[200100], dis[200100];
long long ans, v[200100];
void add(int u, int v) {
  nxt[++cnt] = fst[u], fst[u] = cnt, to[cnt] = v, ind[v]++;
}
int merge(int x, int y) {
  if (!(x * y)) return x | y;
  if (v[x] < v[y]) swap(x, y);
  rs[x] = merge(rs[x], y);
  if (dis[ls[x]] < dis[rs[x]]) swap(ls[x], rs[x]);
  dis[x] = dis[rs[x]] + 1;
  return x;
}
int o;
void dfs(int x, int pa) {
  int flg = 1;
  if (ind[x] == 1) rt[x] = x;
  for (register int i = fst[x]; i; i = nxt[i])
    if (to[i] ^ pa) {
      dfs(to[i], x);
      flg = 0;
      rt[x] = merge(rt[x], rt[to[i]]);
    }
  v[rt[x]]++;
  o += flg;
}
int main() {
  n = read(), m = read();
  int a, b;
  for (register int i = (2), i__end = (n); i <= i__end; ++i)
    a = read(), b = read(), add(a, b), add(b, a);
  dfs(1, 0);
  for (register int i = (1), i__end = (m); i <= i__end; ++i) {
    ans += v[rt[1]];
    rt[1] = merge(ls[rt[1]], rs[rt[1]]);
  }
  int tp = n - ans;
  long long res = 1ll * (m - tp) * (n - m - tp);
  if (o < m) {
    for (register int i = (o), i__end = (m); i <= i__end; ++i)
      res = max(res, 1ll * i * (n - i));
  }
  cout << res;
}
