#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
const long long SZ = 2e5 + 100, INF = 1e9, LG = 20;
long long n, q, tin[SZ], tout[SZ], t = 0, up[SZ][LG], mx[SZ][LG];
long long dsu[SZ], mdd[SZ];
pair<long long, long long> mxd[SZ];
vector<long long> vec;
struct edge {
  long long u, v, c, d;
};
vector<vector<pair<long long, long long>>> gr;
vector<edge> edges;
void dfs(int v, int par = -1) {
  t++;
  tin[v] = t;
  for (int i = 1; i < LG; i++) {
    up[v][i] = up[up[v][i - 1]][i - 1];
    mx[v][i] = max(mx[v][i - 1], mx[up[v][i - 1]][i - 1]);
  }
  for (auto to : gr[v]) {
    if (to.first != par) {
      up[to.first][0] = v;
      mx[to.first][0] = to.second;
      dfs(to.first, v);
    }
  }
  t++;
  tout[v] = t;
}
bool is_par(int v, int u) { return tin[v] <= tin[u] && tout[u] <= tout[v]; }
long long get_mx(int v, int u) {
  long long ans = 0;
  for (int i = LG - 1; i >= 0; i--) {
    if (!is_par(up[v][i], u)) {
      ans = max(mx[v][i], ans);
      v = up[v][i];
    }
    if (!is_par(up[u][i], v)) {
      ans = max(mx[u][i], ans);
      u = up[u][i];
    }
  }
  if (!is_par(v, u)) ans = max(ans, mx[v][0]);
  if (!is_par(u, v)) ans = max(ans, mx[u][0]);
  return ans;
}
struct qs {
  long long v, x, ind;
};
vector<qs> queries;
vector<pair<long long, long long>> ans;
bool cmp(qs a, qs b) { return a.x < b.x; }
bool cmp2(edge a, edge b) { return a.c < b.c; }
long long find(int v) {
  if (dsu[v] == v)
    return v;
  else
    return dsu[v] = find(dsu[v]);
}
void uni(int v, int u) {
  v = find(v);
  u = find(u);
  if (u != v) {
    dsu[u] = v;
    if (mxd[v].first < mxd[u].first) {
      mxd[v] = mxd[u];
      mdd[v] = mdd[u];
    } else if (mxd[v].first == mxd[u].first) {
      mdd[v] = max(max(mdd[u], mdd[v]), get_mx(mxd[v].second, mxd[u].second));
    }
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  cin >> n >> q;
  gr.resize(n);
  vec.resize(n);
  for (auto& c : vec) cin >> c;
  for (int i = 0; i < n - 1; i++) {
    long long u, v, c, d;
    cin >> u >> v >> c >> d;
    u--;
    v--;
    edges.push_back({u, v, c, d});
    gr[u].push_back({v, d});
    gr[v].push_back({u, d});
  }
  for (int i = 0; i < n; i++) {
    dsu[i] = i;
    mdd[i] = 0;
    mxd[i] = {vec[i], i};
  }
  dfs(0);
  for (int i = 0; i < q; i++) {
    long long v, x;
    cin >> x >> v;
    v--;
    queries.push_back({v, x, i});
  }
  ans.resize(q);
  sort(queries.rbegin(), queries.rend(), cmp);
  sort(edges.rbegin(), edges.rend(), cmp2);
  long long i2 = 0;
  for (auto cur : queries) {
    while (i2 < edges.size() && edges[i2].c >= cur.x) {
      uni(edges[i2].u, edges[i2].v);
      i2++;
    }
    long long cmp = find(cur.v);
    ans[cur.ind].first = mxd[cmp].first;
    ans[cur.ind].second = max(mdd[cmp], get_mx(cur.v, mxd[cmp].second));
  }
  for (auto c : ans) cout << c.first << " " << c.second << "\n";
  return 0;
}
