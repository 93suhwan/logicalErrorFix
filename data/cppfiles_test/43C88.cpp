#include <bits/stdc++.h>
using namespace std;
struct nodS {
  bool viz;
  int val, l, r, d;
  int par[22];
  vector<pair<int, int>> v;
};
struct edgeS {
  int x, y, w, id;
  edgeS(int x, int y, int w, int id) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->id = id;
  }
};
int n, q, timp;
nodS nod[300005];
int dsu[300005];
int euler[600005];
int ans[500005];
vector<edgeS> edges;
int dsu_anc(int x) {
  if (dsu[x] != x) dsu[x] = dsu_anc(dsu[x]);
  return dsu[x];
}
bool dsu_merge(int x, int y) {
  x = dsu_anc(x);
  y = dsu_anc(y);
  if (x == y) return false;
  dsu[x] = y;
  return true;
}
int anc(int x, int d) {
  for (int b = 0; b <= 20; b++)
    if ((d >> b) & 1) x = nod[x].par[b];
  return x;
}
int lca(int x, int y) {
  if (nod[x].d > nod[y].d) swap(x, y);
  y = anc(y, nod[y].d - nod[x].d);
  if (x == y) return x;
  for (int b = 20; b >= 0; b--) {
    if (nod[x].par[b] != nod[y].par[b]) {
      x = nod[x].par[b];
      y = nod[y].par[b];
    }
  }
  return nod[x].par[0];
}
void addBit(int i, int val) {
  for (; i <= 2 * n; i += ((i) & -(i))) euler[i] += val;
}
int queryBit(int i) {
  int ans = 0;
  for (; i >= 1; i -= ((i) & -(i))) ans += euler[i];
  return ans;
}
void addNod(int x) {
  addBit(nod[x].l, 1);
  addBit(nod[x].r, -1);
}
void addPath(int x, int y) {
  while (nod[x].d > nod[y].d) {
    addNod(x);
    x = nod[x].par[0];
  }
}
int queryPath(int x, int y) { return queryBit(nod[x].l) - queryBit(nod[y].l); }
void dfs(int p, int parV, int valX) {
  timp++;
  nod[p].l = timp;
  nod[p].viz = true;
  nod[p].d = nod[parV].d + 1;
  nod[p].val = valX;
  nod[p].par[0] = parV;
  for (int b = 1; b <= 20; b++)
    nod[p].par[b] = nod[nod[p].par[b - 1]].par[b - 1];
  for (auto it : nod[p].v)
    if (it.first != parV) dfs(it.first, p, valX ^ it.second);
  timp++;
  nod[p].r = timp;
}
void buildTree() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) dsu[i] = i;
  for (int i = 1; i <= q; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    if (dsu_merge(x, y)) {
      nod[x].v.push_back({y, w});
      nod[y].v.push_back({x, w});
      ans[i] = true;
    } else
      edges.push_back(edgeS(x, y, w, i));
  }
  for (int i = 1; i <= n; i++)
    if (!nod[i].viz) dfs(i, 0, 0);
}
int main() {
  buildTree();
  for (auto it : edges) {
    int x = it.x;
    int y = it.y;
    int w = it.w;
    int id = it.id;
    int valX = nod[x].val ^ nod[y].val;
    if (valX == w) continue;
    int l = lca(x, y);
    if (queryPath(x, l) || queryPath(y, l)) continue;
    ans[id] = true;
    addPath(x, l);
    addPath(y, l);
  }
  for (int i = 1; i <= q; i++) {
    if (ans[i])
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}
