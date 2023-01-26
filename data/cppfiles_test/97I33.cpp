#include <bits/stdc++.h>
using namespace std;
int n, m, q, c[200015], ans[200015], dep[200015], par[200015];
vector<int> e[200015];
vector<pair<int, int> > que[200015];
int fa[200015], siz[200015], rt[200015], tc[200015], tk[200015];
void init() {
  for (int i = (1); i <= (n); i++) fa[i] = rt[i] = i, siz[i] = 1, tc[i] = c[i];
}
int find(int x) { return x == fa[x] ? x : find(fa[x]); }
void uni(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return;
  if (siz[u] < siz[v]) swap(u, v);
  fa[v] = u;
  tc[v] -= tc[u];
  tk[v] -= tk[u];
  siz[u] += siz[v];
  rt[u] = dep[rt[v]] < dep[rt[u]] ? rt[v] : rt[u];
}
int qc(int x) {
  int res = 0;
  while (x != fa[x]) {
    res += tc[x];
    x = fa[x];
  }
  res += tc[x];
  return res;
}
int qk(int x) {
  int res = 0;
  while (x != fa[x]) {
    res += tk[x];
    x = fa[x];
  }
  res += tk[x];
  return res;
}
void addc(int x, int v) { tc[x] += v; }
void addk(int x, int v) { tk[x] += v; }
void dfs(int u, int pa) {
  dep[u] = dep[pa] + 1;
  par[u] = pa;
  for (auto v : e[u])
    if (v != pa) {
      c[u]++;
      dfs(v, u);
    }
}
set<pair<int, int> > S;
int main() {
  scanf("%d", &n);
  for (int i = (2); i <= (n); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  scanf("%d", &q);
  for (int i = (1); i <= (q); i++) {
    int v, k;
    scanf("%d%d", &v, &k);
    m = max(m, k);
    que[k].push_back(make_pair(v, i));
  }
  dfs(1, 0);
  init();
  for (int i = (1); i <= (n); i++) S.insert(make_pair(-c[i], i));
  for (int i = (m); i >= (0); i--) {
    while (((int)S.size()) > 0) {
      if (-S.begin()->first <= i) break;
      int u = S.begin()->second;
      S.erase(S.begin());
      if (!par[u]) continue;
      int v = find(par[u]);
      assert(u == rt[find(u)]);
      S.erase(make_pair(-qc(rt[v]), rt[v]));
      addc(v, qc(u) - 1);
      addk(v, 1);
      uni(u, v);
      if (par[rt[v]]) S.insert(make_pair(-qc(rt[v]), rt[v]));
    }
    for (auto x : que[i]) {
      ans[x.second] = qc(x.first) - qk(x.first) * i;
    }
  }
  for (int i = (1); i <= (q); i++) printf("%d\n", ans[i]);
  return 0;
}
