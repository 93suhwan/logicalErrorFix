#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const int maxn = 3e5 + 80;
const int mod = 998244353;
const int base = 1e18;
int st[4 * maxn];
struct Seqment_tree {
  int get(int id, int left, int right, int x, int y) {
    if (left > y || right < x) return 0;
    if (x <= left && right <= y) {
      return st[id];
    }
    int mid = (left + right) / 2;
    return (get(id * 2, left, mid, x, y) +
            get(id * 2 + 1, mid + 1, right, x, y));
  }
  void update(int id, int left, int right, int pos, int diff) {
    if (pos < left || pos > right) return;
    if (left == right) {
      st[id] = diff;
      return;
    }
    int mid = (left + right) / 2;
    update(id * 2, left, mid, pos, diff);
    update(id * 2 + 1, mid + 1, right, pos, diff);
    st[id] = (st[id * 2] + st[id * 2 + 1]);
  }
} man;
vector<pair<int, int> > adj[maxn];
int par[maxn];
int siz[maxn];
int find_par(int u) {
  if (u == par[u]) return u;
  return par[u] = find_par(par[u]);
}
bool dsu(int x, int y) {
  x = find_par(x);
  y = find_par(y);
  if (x == y) return true;
  par[x] = y;
  return false;
}
int anc[maxn][20];
bool dd[maxn * 2];
int x[maxn * 2];
int y[maxn * 2];
int w[maxn * 2];
int dep[maxn];
int dep1[maxn];
bool kt[maxn];
void dfs(int u, int par) {
  anc[u][0] = par;
  for (int i = 1; i < 20; i++) {
    anc[u][i] = anc[anc[u][i - 1]][i - 1];
  }
  siz[u] = 1;
  kt[u] = 1;
  for (auto p : adj[u]) {
    int to = p.first;
    int w = p.second;
    if (to == par) continue;
    dep[to] = dep[u] + 1;
    dep1[to] = dep1[u] ^ w;
    dfs(to, u);
    siz[u] += siz[to];
  }
}
int lca(int x, int y) {
  if (dep[y] > dep[x]) swap(x, y);
  int kc = dep[x] - dep[y];
  for (int i = 19; i >= 0; i--) {
    if (kc & (1ll << i)) {
      x = anc[x][i];
    }
  }
  if (x == y) return x;
  for (int i = 19; i >= 0; i--) {
    if (anc[x][i] != anc[y][i]) {
      x = anc[x][i];
      y = anc[y][i];
    }
  }
  return anc[x][0];
}
int getd(int x, int y) { return dep1[x] ^ dep1[y]; }
void dsu1(int x, int y) {
  x = find_par(x);
  y = find_par(y);
  if (x == y) return;
  if (dep[x] > dep[y]) swap(x, y);
  par[x] = y;
}
int cntnw = 0;
int nchain = 0;
int chainhead[maxn];
int chainid[maxn];
int id[maxn];
void hld(int u) {
  if (!chainhead[nchain]) chainhead[nchain] = u;
  cntnw++;
  chainid[u] = nchain;
  id[u] = cntnw;
  int nxt = -1;
  for (auto p : adj[u]) {
    int to = p.first;
    if (to == anc[u][0]) continue;
    if (nxt == -1 || siz[nxt] < siz[to]) {
      nxt = to;
    }
  }
  if (nxt != -1) {
    hld(nxt);
  }
  for (auto p : adj[u]) {
    int to = p.first;
    if (to == anc[u][0] || to == nxt) continue;
    nchain++;
    hld(to);
  }
}
int getn(int x, int y) {
  int kc = dep[x] - dep[y] - 1;
  for (int i = 19; i >= 0; i--) {
    if (kc & (1ll << i)) {
      x = anc[x][i];
    }
  }
  return x;
}
int get(int u, int a) {
  int p = chainid[u];
  int chk = chainid[a];
  int ans = 0;
  while (1) {
    if (p == chk) {
      ans += man.get(1, 1, cntnw, id[a], id[u]);
      break;
    }
    ans += man.get(1, 1, cntnw, id[chainhead[p]], id[u]);
    u = anc[chainhead[p]][0];
    p = chainid[u];
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    par[i] = i;
  }
  for (int i = 1; i <= q; i++) {
    cin >> x[i] >> y[i] >> w[i];
    if (!dsu(x[i], y[i])) {
      adj[x[i]].push_back(make_pair(y[i], w[i]));
      adj[y[i]].push_back(make_pair(x[i], w[i]));
      dd[i] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (kt[i]) continue;
    nchain++;
    dfs(i, 0);
    hld(i);
  }
  for (int i = 1; i <= q; i++) {
    if (dd[i]) {
      cout << "YES"
           << "\n";
    } else {
      if (dep[x[i]] < dep[y[i]]) swap(x[i], y[i]);
      int h = lca(x[i], y[i]);
      bool chk = true;
      if (h == y[i]) {
        if (get(x[i], getn(x[i], h))) {
          chk = false;
        }
      } else {
        if (get(x[i], getn(x[i], h))) chk = false;
        if (get(y[i], getn(y[i], h))) chk = false;
      }
      if ((getd(x[i], y[i]) ^ w[i]) == 1 && chk) {
        int nw = x[i];
        while (dep[nw] > dep[h]) {
          man.update(1, 1, cntnw, id[nw], 1);
          nw = anc[nw][0];
        }
        nw = y[i];
        while (dep[nw] > dep[h]) {
          man.update(1, 1, cntnw, id[nw], 1);
          nw = anc[nw][0];
        }
        cout << "YES"
             << "\n";
      } else {
        cout << "NO"
             << "\n";
      }
    }
  }
}
