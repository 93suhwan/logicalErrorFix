#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1e5 + 100;
const int LOG = 18;
int cnt;
bool used[N];
ll a[N];
int sz[N], comp[N], comp_sz[N], comp_pos[N], comp_prev[N], h[N];
int p[LOG][N];
vector<int> g[N];
vector<ll> val[N], fen[N];
void init() {}
void dfs(int v) {
  used[v] = true;
  sz[v] = 1;
  for (int u : g[v]) {
    if (!used[u]) {
      p[0][u] = v;
      h[u] = h[v] + 1;
      dfs(u);
      sz[v] += sz[u];
    }
  }
}
void dfs2(int v, int c) {
  comp[v] = c;
  comp_pos[v] = comp_sz[c]++;
  pair<int, int> best(-1, -1);
  for (int u : g[v]) {
    if (p[0][u] == v) {
      best = max(best, make_pair(sz[u], u));
    }
  }
  if (best.second != -1) {
    dfs2(best.second, c);
  }
  for (int u : g[v]) {
    if (p[0][u] == v && u != best.second) {
      comp_prev[cnt++] = u;
      dfs2(u, cnt - 1);
    }
  }
}
void add(vector<ll>& f, int pos, ll val) {
  while (pos < ((int)(f).size())) {
    f[pos] += val;
    pos = (pos | (pos + 1));
  }
}
void set_val(int v, ll new_val) {
  add(fen[comp[v]], comp_pos[v], new_val - val[comp[v]][comp_pos[v]]);
  val[comp[v]][comp_pos[v]] = new_val;
}
int get_lca(int a, int b) {
  if (h[a] < h[b]) {
    swap(a, b);
  }
  for (int i = LOG - 1; i >= 0; --i) {
    if (p[i][a] != -1 && h[p[i][a]] >= h[b]) {
      a = p[i][a];
    }
  }
  if (a == b) {
    return a;
  }
  for (int i = LOG - 1; i >= 0; --i) {
    if (p[i][a] != p[i][b]) {
      a = p[i][a];
      b = p[i][b];
      assert(a != -1);
      assert(b != -1);
    }
  }
  return p[0][a];
}
ll get(const vector<ll>& f, int pos) {
  ll res = 0;
  while (pos >= 0) {
    res += f[pos];
    pos = (pos & (pos + 1)) - 1;
  }
  return res;
}
ll get(const vector<ll>& f, int l, int r) {
  assert(l <= r);
  return get(f, r) - get(f, l - 1);
}
ll get_sum(int a, int b) {
  assert(h[a] >= h[b]);
  ll res = 0;
  while (comp[a] != comp[b]) {
    res += get(fen[comp[a]], comp_pos[a]);
    a = p[0][comp_prev[comp[a]]];
  }
  assert(comp[a] == comp[b]);
  assert(comp_pos[b] <= comp_pos[a]);
  res += get(fen[comp[a]], comp_pos[b], comp_pos[a]);
  return res;
}
void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a + i);
    a[i] = abs(a[i]);
  }
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  p[0][0] = -1;
  h[0] = 0;
  dfs(0);
  for (int i = 1; i < LOG; ++i) {
    for (int j = 0; j < n; ++j) {
      if (p[i - 1][j] == -1) {
        p[i][j] = -1;
      } else {
        p[i][j] = p[i - 1][p[i - 1][j]];
      }
    }
  }
  cnt = 1;
  comp_prev[0] = 0;
  dfs2(0, 0);
  for (int i = 0; i < cnt; ++i) {
    val[i].resize(comp_sz[i]);
    fen[i].resize(comp_sz[i]);
  }
  for (int i = 0; i < n; ++i) {
    set_val(i, a[i]);
  }
  for (int i = 0; i < m; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int v;
      ll val;
      scanf("%d %lld", &v, &val);
      --v;
      a[v] = abs(val);
      set_val(v, a[v]);
    } else {
      assert(t == 2);
      int x, y;
      scanf("%d %d", &x, &y);
      --x;
      --y;
      int z = get_lca(x, y);
      ll res = 2 * (get_sum(x, z) + get_sum(y, z) - a[z]) - a[x] - a[y];
      printf("%lld\n", res);
    }
  }
}
int main() {
  init();
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
