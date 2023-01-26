#include <bits/stdc++.h>
using namespace std;
long double PI = acos(-1);
long double DEL = 1e-12;
long long M = 1e9 + 7;
const long long N = 3e5 + 10;
long long cnt, sum, mx, mn, ans, a[N], b[N];
long long n, m, d, i, j, k, l, p, q, r, t, w, x, y, z, tc;
string s;
struct HEAVY_LIGHT {
  vector<long long> dfsarray, depth, heavy, par, sub, head, pos, seg;
  void buildseg(long long i, long long l, long long r) {
    if (l == r) {
      seg[i] = a[dfsarray[l]];
      return;
    }
    buildseg(2 * i, l, ((l + r) >> 1));
    buildseg(2 * i + 1, ((l + r) >> 1) + 1, r);
    seg[i] = seg[2 * i] + seg[2 * i + 1];
  }
  void upd(long long x, long long v, long long i = 1, long long l = 0,
           long long r = n - 1) {
    if (x < l or x > r) {
      return;
    }
    if (l == r) {
      seg[i] = v;
      return;
    }
    upd(x, v, 2 * i, l, ((l + r) >> 1));
    upd(x, v, 2 * i + 1, ((l + r) >> 1) + 1, r);
    seg[i] = seg[2 * i] + seg[2 * i + 1];
  }
  long long query(long long a, long long b, long long i = 1, long long l = 0,
                  long long r = n - 1) {
    if (l > b or r < a) {
      return 0;
    }
    if (a <= l and r <= b) {
      return seg[i];
    }
    return query(a, b, 2 * i, l, ((l + r) >> 1)) +
           query(a, b, 2 * i + 1, ((l + r) >> 1) + 1, r);
  }
  void build(vector<vector<long long>> &g, long long root) {
    long long sz = n;
    depth.resize(sz + 1);
    heavy.resize(sz + 1);
    par.resize(sz + 1);
    pos.resize(sz + 1);
    head.resize(sz + 1);
    sub.resize(sz + 1);
    seg.resize(4 * sz + 1);
    dfs(root, root, g);
    decompose(root, root, g);
    buildseg(1, 0, n - 1);
  }
  void dfs(long long i, long long p, vector<vector<long long>> &g) {
    depth[i] = depth[p] + 1;
    par[i] = p;
    sub[i] = 1;
    long long ms = 0, hc = -1;
    for (auto j : g[i]) {
      if (j == p) continue;
      dfs(j, i, g);
      sub[i] += sub[j];
      if (sub[j] > ms) {
        ms = sub[j];
        hc = j;
      }
    }
    heavy[i] = hc;
  }
  void decompose(long long i, long long h, vector<vector<long long>> &g) {
    pos[i] = dfsarray.size();
    dfsarray.push_back(i);
    head[i] = h;
    if (heavy[i] != -1) {
      decompose(heavy[i], h, g);
    }
    for (auto j : g[i]) {
      if (j == par[i] or j == heavy[i]) continue;
      decompose(j, j, g);
    }
  }
  long long lca(long long u, long long v) {
    for (; head[u] != head[v]; u = par[head[u]]) {
      if (depth[head[u]] < depth[head[v]]) {
        swap(u, v);
      }
    }
    return depth[u] > depth[v] ? v : u;
  }
  long long get(long long u, long long v) {
    long long ans = 0;
    long long sub = a[u] + a[v];
    for (; head[u] != head[v]; u = par[head[u]]) {
      if (depth[head[u]] < depth[head[v]]) {
        swap(u, v);
      }
      ans += query(pos[head[u]], pos[u]);
    }
    if (depth[u] > depth[v]) {
      swap(u, v);
    }
    ans += query(pos[u], pos[v]);
    ans *= 2;
    return ans - sub;
  }
};
vector<vector<long long>> g;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  g.resize(n + 1);
  for (long long i = 1; i < n; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  HEAVY_LIGHT h;
  h.build(g, 1);
  while (q--) {
    cin >> t >> x >> y;
    if (t == 1) {
      h.upd(h.pos[x], abs(y));
      a[x] = abs(y);
    } else {
      cout << h.get(x, y);
      cout << "\n";
    }
  }
}
