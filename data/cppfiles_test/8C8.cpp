#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long MX = 1e5 + 3;
const long long INF = 1e9;
int n;
int T[100003], L[100003], P[100003][22], s_id[MX], e_id[MX], c;
vector<int> g[100003];
void dfs(int from, int u, int dep) {
  s_id[u] = c++;
  T[u] = from;
  L[u] = dep;
  for (auto v : g[u]) {
    if (v == from) continue;
    dfs(u, v, dep + 1);
  }
  e_id[u] = c++;
}
void lca_init() {
  c = 1;
  dfs(-1, 1, 0);
  memset(P, -1, sizeof(P));
  for (int i = 1; i <= n; i++) P[i][0] = T[i];
  for (int j = 1; 1 << j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      if (P[i][j - 1] != -1) {
        P[i][j] = P[P[i][j - 1]][j - 1];
      }
    }
  }
}
int lca_query(int p, int q) {
  if (L[p] < L[q]) swap(p, q);
  int log = 1;
  while (true) {
    int next = log + 1;
    if (1 << next > L[p]) break;
    log++;
  }
  for (int i = log; i >= 0; i--) {
    if (L[p] - (1 << i) >= L[q]) {
      p = P[p][i];
    }
  }
  if (p == q) return p;
  for (int i = log; i >= 0; i--) {
    if (P[p][i] != -1 && P[p][i] != P[q][i]) {
      p = P[p][i], q = P[q][i];
    }
  }
  return T[p];
}
long long bit[MX + MX];
void update(int i, long long val) {
  for (; i < c; i += (i & (-i))) {
    bit[i] += val;
  }
}
long long query(int i) {
  long long ret = 0;
  for (; i > 0; i -= (i & (-i))) {
    ret += bit[i];
  }
  return ret;
}
long long sum(int l, int r) { return query(r) - query(l - 1); }
void solve() {
  int q;
  cin >> n >> q;
  int a[n + 1];
  for (int i = 1; i < n + 1; ++i) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  int u, v;
  for (int i = 1; i < n; ++i) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  lca_init();
  for (int i = 1; i < n + 1; ++i) {
    update(s_id[i], a[i]);
    update(e_id[i], -a[i]);
  }
  int tp, _a;
  while (q--) {
    cin >> tp;
    if (tp == 1) {
      cin >> u >> _a;
      update(s_id[u], -a[u]);
      update(e_id[u], a[u]);
      a[u] = abs(_a);
      update(s_id[u], a[u]);
      update(e_id[u], -a[u]);
    } else {
      cin >> u >> v;
      int lca = lca_query(u, v);
      long long ans;
      if (u == v)
        ans = 0;
      else if (u == lca || v == lca) {
        if (u == lca) swap(u, v);
        ans = 2 * (sum(s_id[1], s_id[u]) - sum(s_id[1], s_id[lca]));
        ans += a[lca];
        ans -= a[u];
      } else {
        ans = sum(s_id[1], s_id[u]) + sum(s_id[1], s_id[v]) -
              (2 * sum(s_id[1], s_id[lca])) + a[lca];
        ans = 2 * ans;
        ans -= a[u];
        ans -= a[v];
      }
      cout << ans << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int t1 = 1; t1 < t + 1; ++t1) {
    solve();
  }
  return 0;
}
