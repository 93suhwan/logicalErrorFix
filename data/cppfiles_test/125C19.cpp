#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5, M = 12e5 + 5;
int n, a[N], id = 1, have[N], head[N], tot, ver[M], nxt[M];
int fa[N], vis[N], pre[N], match[N], dfn[N], timer;
bool del[M], vs[N];
queue<int> q;
vector<int> clr;
vector<pair<int, int> > vec;
inline void add(int u, int v) {
  ver[++tot] = v;
  nxt[tot] = head[u];
  head[u] = tot;
  ver[++tot] = u;
  nxt[tot] = head[v];
  head[v] = tot;
}
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline int lca(int u, int v) {
  timer++, u = find(u), v = find(v);
  while (dfn[u] != timer) {
    dfn[u] = timer;
    u = find(pre[match[u]]);
    if (v) u ^= v ^= u ^= v;
  }
  return u;
}
inline void blossom(int x, int y, int z) {
  while (find(x) != z) {
    pre[x] = y;
    y = match[x];
    if (vis[y] == 2) vis[y] = 1, q.push(y), clr.emplace_back(y);
    if (x == find(x)) fa[x] = z;
    if (y == find(y)) fa[y] = z;
    x = pre[y];
  }
}
inline bool bfs(int s) {
  for (auto x : clr) vis[x] = pre[x] = 0, fa[x] = x;
  clr.clear();
  while (!q.empty()) q.pop();
  q.push(s);
  vis[s] = 1;
  clr.emplace_back(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = nxt[i]) {
      int v = ver[i];
      if (vis[v] == 2 || find(u) == find(v)) continue;
      if (vis[v] == 0) {
        vis[v] = 2;
        pre[v] = u;
        clr.emplace_back(v);
        if (!match[v]) {
          for (int x = v, lst; x; x = lst) {
            lst = match[pre[x]];
            match[x] = pre[x];
            match[pre[x]] = x;
          }
          return 1;
        }
        vis[match[v]] = 1;
        q.push(match[v]);
        clr.emplace_back(match[v]);
      } else {
        int w = lca(u, v);
        blossom(u, v, w);
        blossom(v, u, w);
        clr.emplace_back(v), clr.emplace_back(w);
      }
    }
  }
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n + n; ++i) fa[i] = i;
  for (int i = 1; i <= n; ++i) scanf("%d", a + i), have[a[i]] = 1;
  for (int i = 1; i < n; ++i)
    if (a[i] == a[i - 1] && a[i]) vs[a[i]] = 1;
  for (int i = 1, j; i <= n; i = j + 1) {
    j = i;
    if (a[i]) continue;
    while (!a[j] && j <= n) ++j;
    vec.emplace_back(i, j);
    if ((j - i) & 1) {
      if (i > 1 && !vs[a[i - 1]]) add(a[i - 1], n + i);
      if (j <= n && !vs[a[j]]) add(a[j], n + i);
    } else {
      if (i > 1 && !vs[a[i - 1]]) add(a[i - 1], n + i);
      if (j <= n && !vs[a[j]]) add(a[j], n + j - 1);
      add(n + i, n + j - 1);
    }
  }
  for (int i = 1; i <= n + n; ++i)
    if (!match[i]) bfs(i);
  for (auto p : vec) {
    int l = p.first, r = p.second;
    if ((r - l) & 1) {
      if (l > 1 && match[n + l] == a[l - 1]) {
        a[l] = a[l - 1];
        for (int i = l + 1; i + 1 < r; i += 2) {
          while (have[id]) ++id;
          a[i] = a[i + 1] = id++;
        }
      } else {
        for (int i = l; i + 1 < r; i += 2) {
          while (have[id]) ++id;
          a[i] = a[i + 1] = id++;
        }
        a[r - 1] = a[r];
      }
    } else {
      if (match[n + l] == n + r - 1) {
        for (int i = l; i + 1 < r; i += 2) {
          while (have[id]) ++id;
          a[i] = a[i + 1] = id++;
        }
      } else {
        a[l] = a[l - 1], a[r - 1] = a[r];
        for (int i = l + 1; i + 1 < r; i += 2) {
          while (have[id]) ++id;
          a[i] = a[i + 1] = id++;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) printf("%d ", a[i] ? a[i] : 1);
  return 0;
}
