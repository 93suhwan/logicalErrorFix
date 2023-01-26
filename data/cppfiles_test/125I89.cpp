#include <bits/stdc++.h>
using namespace std;
namespace match {
int k, i, j, g[605][605], fa[605], x, y, typ[605], pre[605], lk[605], ans,
    vis[605], ti, t, tot;
queue<int> qx;
int fnd_flower_root(int x) {
  if (fa[x] == x) return x;
  return fa[x] = fnd_flower_root(fa[x]);
}
int lca(int x, int y) {
  ti++;
  for (;;) {
    if (x) {
      x = fnd_flower_root(x);
      if (vis[x] == ti) return x;
      vis[x] = ti;
      x = pre[lk[x]];
    }
    swap(x, y);
  }
}
void merge_flower(int x, int y, int t) {
  while (fnd_flower_root(x) != t) {
    pre[x] = y;
    y = lk[x];
    typ[y] = 1;
    qx.push(y);
    if (fnd_flower_root(x) == x) fa[x] = t;
    if (fnd_flower_root(y) == y) fa[y] = t;
    x = pre[y];
  }
}
bool flower_try(int x) {
  while (!qx.empty()) qx.pop();
  int i;
  for ((i) = 1; (i) <= (tot); (i)++) {
    fa[i] = i;
    pre[i] = typ[i] = 0;
  }
  typ[x] = 1;
  qx.push(x);
  while (!qx.empty()) {
    int x = qx.front();
    qx.pop();
    for ((i) = 1; (i) <= (tot); (i)++)
      if (g[x][i]) {
        if (fnd_flower_root(x) == fnd_flower_root(i) || typ[i] == 2) continue;
        if (typ[i] == 0) {
          pre[i] = x;
          if (!lk[i]) {
            int j = i;
            while (j) {
              int t = lk[pre[j]];
              lk[j] = pre[j];
              lk[pre[j]] = j;
              j = t;
            }
            return 1;
          }
          typ[i] = 2;
          typ[lk[i]] = 1;
          qx.push(lk[i]);
        } else {
          int t = lca(x, i);
          merge_flower(x, i, t);
          merge_flower(i, x, t);
        }
      }
  }
  return 0;
}
void doit() {
  int i;
  for ((i) = 1; (i) <= (tot); (i)++) {
    if (!lk[i]) ans += flower_try(i);
  }
}
}  // namespace match
const int N = 300005, M = 605;
int n, a[N];
int vis[M], fa[M], cyc[M];
int X[N], Y[N];
vector<int> G[M];
int pl[N], pr[N], cnt;
int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}
void merge(int x, int y, int id) {
  int mx = x, my = y;
  x = find(x);
  y = find(y);
  if (x != y) {
    if (cyc[x] + cyc[y] != 2)
      cyc[y] |= cyc[x], fa[x] = y, X[id] = mx, Y[id] = my, G[my].push_back(id),
                        G[mx].push_back(id);
  } else if (!cyc[x]) {
    cyc[x] = 1, fa[x] = y, X[id] = mx, Y[id] = my, G[my].push_back(id),
    G[mx].push_back(id);
  }
}
void push1(int id, int col) {
  assert(!vis[col]);
  vis[col] = 1;
  if (a[pl[id] - 1] == col)
    a[pl[id]] = col;
  else if (a[pr[id] + 1] == col)
    a[pr[id]] = col;
  else
    assert(false);
}
void dfs1(int x, int fa, int rt) {
  for (int y : G[x])
    if (y != fa) {
      int z = X[y] ^ Y[y] ^ x;
      if (vis[z]) continue;
      push1(y, z);
      if (z != rt) {
        dfs1(z, y, rt);
      }
    }
}
void solve() {
  int i;
  scanf("%d", &n);
  for ((i) = 1; (i) <= (n); (i)++) scanf("%d", &a[i]);
  for ((i) = 1; (i) <= (n - 1); (i)++)
    if (a[i] && a[i] == a[i + 1]) vis[a[i]] = 1;
  int fir = -1, lst = -1;
  for ((i) = 1; (i) <= (n); (i)++) {
    if (a[i] == 0) {
      if (lst == i - 1)
        lst = i;
      else {
        if (fir != -1) cnt++, pl[cnt] = fir, pr[cnt] = lst;
        fir = lst = i;
      }
    }
  }
  if (fir != -1) cnt++, pl[cnt] = fir, pr[cnt] = lst;
  for ((i) = 1; (i) <= (600); (i)++) fa[i] = i, cyc[i] = 0;
  for ((i) = 1; (i) <= (cnt); (i)++) {
    int typ = ((pr[i] - pl[i] + 1) & 1);
    if (typ == 1) {
      int x = 0, y = 0;
      if (pl[i] != 1 && !vis[a[pl[i] - 1]]) x = a[pl[i] - 1];
      if (pr[i] != n && !vis[a[pr[i] + 1]]) y = a[pr[i] + 1];
      if (!x && !y) continue;
      if (!x || !y) x = y = (x | y);
      merge(x, y, i);
    }
  }
  for ((i) = 1; (i) <= (600); (i)++)
    if (fa[i] == i && cyc[i]) {
      dfs1(i, 0, i);
    }
  match::tot = 600;
  for ((i) = 1; (i) <= (cnt); (i)++) {
    int typ = ((pr[i] - pl[i] + 1) & 1);
    if (typ == 0) {
      int x = 0, y = 0;
      if (pl[i] != 1 && !vis[a[pl[i] - 1]]) x = a[pl[i] - 1];
      if (pr[i] != n && !vis[a[pr[i] + 1]]) y = a[pr[i] + 1];
      if (!x || !y) continue;
      if (x == y) continue;
      match::g[find(x)][find(y)] = match::g[find(y)][find(x)] = i;
    }
  }
  match::doit();
  for ((i) = 1; (i) <= (600); (i)++)
    if (match::lk[i] > i) {
      push1(match::g[i][match::lk[i]], i);
      push1(match::g[i][match::lk[i]], match::lk[i]);
    }
  for ((i) = 1; (i) <= (600); (i)++)
    if (!cyc[find(i)] && vis[find(i)]) dfs1(i, 0, i);
  for ((i) = 1; (i) <= (600); (i)++)
    if (!cyc[find(i)] && !vis[find(i)]) dfs1(i, 0, i);
  int t = 1;
  for ((i) = 1; (i) <= (n); (i)++) {
    if (a[i] == 0) {
      while (vis[t]) t++;
      vis[t] = 1;
      a[i] = t;
      if (i != n && a[i + 1] == 0) {
        a[i + 1] = t;
      }
    }
  }
  for ((i) = 1; (i) <= (n); (i)++) printf("%d ", a[i]);
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
