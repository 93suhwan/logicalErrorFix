#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
mt19937 rnd;
const long long maxn = 2e5 + 50;
const long long mod = 998244353;
const long long base = 1e18;
long long anc[maxn][20];
long long mx[maxn][20];
long long dep[maxn];
long long val[maxn];
long long valmx[maxn];
set<long long> st[maxn];
long long par[maxn];
long long pos[maxn];
vector<pair<long long, pair<long long, long long>>> adj[maxn];
long long cnt = 0;
long long f[maxn];
long long find_par(long long u) {
  if (u == par[u]) return u;
  return par[u] = find_par(par[u]);
}
void dfs(long long u, long long par) {
  cnt++;
  f[u] = cnt;
  pos[cnt] = u;
  for (int i = 1; i < 20; i++) {
    anc[u][i] = anc[anc[u][i - 1]][i - 1];
    mx[u][i] = max(mx[u][i - 1], mx[anc[u][i - 1]][i - 1]);
  }
  for (auto p : adj[u]) {
    long long to = p.first;
    if (to == par) continue;
    long long w = p.second.second;
    dep[to] = dep[u] + 1;
    anc[to][0] = u;
    mx[to][0] = w;
    dfs(to, u);
  }
}
long long get(long long x, long long y) {
  x = pos[x];
  y = pos[y];
  if (dep[x] < dep[y]) swap(x, y);
  long long kc = dep[x] - dep[y];
  long long ans = 0;
  for (int i = 19; i >= 0; i--) {
    if (kc & (1ll << i)) {
      ans = max(ans, mx[x][i]);
      x = anc[x][i];
    }
  }
  if (x == y) return ans;
  for (int i = 19; i >= 0; i--) {
    if (anc[x][i] != anc[y][i]) {
      ans = max(ans, mx[x][i]);
      x = anc[x][i];
      ans = max(ans, mx[y][i]);
      y = anc[y][i];
    }
  }
  ans = max(ans, mx[x][0]);
  ans = max(ans, mx[y][0]);
  return ans;
}
void dsu(long long x, long long y) {
  x = find_par(x);
  y = find_par(y);
  if (st[x].size() < st[y].size()) swap(x, y);
  if (val[x] < val[y]) {
    swap(val[x], val[y]);
    swap(st[x], st[y]);
    swap(valmx[x], valmx[y]);
    par[y] = x;
    st[y].clear();
    return;
  }
  if (val[x] > val[y]) {
    par[y] = x;
    st[y].clear();
    return;
  }
  for (auto p : st[y]) {
    auto it = st[x].lower_bound(p);
    if (it == st[x].end()) {
      it = st[x].begin();
    }
    long long h = *it;
    valmx[x] = max(valmx[x], get(p, h));
    if (it == st[x].begin()) {
      it = st[x].end();
    }
    it--;
    h = *it;
    valmx[x] = max(valmx[x], get(p, h));
    st[x].insert(p);
  }
  par[y] = x;
  st[y].clear();
  return;
}
pair<long long, long long> ans[maxn];
long long get1(long long p, long long x) {
  long long ans = 0;
  auto it = st[x].lower_bound(p);
  if (it == st[x].end()) {
    it = st[x].begin();
  }
  long long h = *it;
  ans = max(ans, get(p, h));
  if (it == st[x].begin()) {
    it = st[x].end();
  }
  it--;
  h = *it;
  ans = max(ans, get(p, h));
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("slom.inp", "r")) {
    freopen("slom.inp", "r", stdin);
    freopen("slom.out", "w", stdout);
  }
  long long n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
    par[i] = i;
  }
  vector<pair<long long, pair<long long, long long>>> vt;
  for (int i = 1; i <= n - 1; i++) {
    long long x, y, c, w;
    cin >> x >> y >> c >> w;
    adj[x].push_back(make_pair(y, make_pair(c, w)));
    adj[y].push_back(make_pair(x, make_pair(c, w)));
    vt.push_back(make_pair(c, make_pair(x, y)));
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    st[i].insert(f[i]);
  }
  for (int i = 1; i <= q; i++) {
    long long v, x;
    cin >> v >> x;
    vt.push_back(make_pair(v, make_pair(-i, x)));
  }
  sort(vt.rbegin(), vt.rend());
  for (auto p : vt) {
    if (p.second.first < 0) {
      long long id = -p.second.first;
      long long x = p.second.second;
      long long t = find_par(x);
      ans[id] = make_pair(val[t], max(valmx[t], get1(f[x], t)));
    } else {
      long long x = p.second.first;
      long long y = p.second.second;
      dsu(x, y);
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
}
