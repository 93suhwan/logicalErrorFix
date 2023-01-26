#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> adj;
struct LCA {
  vector<vector<long long>> st;
  vector<long long> parent, level;
  LCA() {
    long long n = (long long)adj.size();
    long long k = log2(n) + 2;
    st.assign(n, vector<long long>(k, -1));
    parent.assign(n, -1);
    level.assign(n, 0);
    dfs(adj, 1, -1);
    for (long long i = 1; i <= n - 1; i++) st[i][0] = parent[i];
    build(n - 1);
  }
  void dfs(vector<vector<long long>> &adj, long long s, long long p) {
    parent[s] = p;
    for (auto u : adj[s]) {
      if (u != p) {
        level[u] = level[s] + 1;
        dfs(adj, u, s);
      }
    }
  }
  void build(long long n) {
    for (long long j = 1; (1 << j) <= n; j++) {
      for (long long i = 1; i <= n; i++) {
        if (st[i][j - 1] != -1) {
          st[i][j] = st[st[i][j - 1]][j - 1];
        }
      }
    }
  }
  long long lca(long long a, long long b, long long n) {
    if (level[a] < level[b]) swap(a, b);
    long long dist = level[a] - level[b];
    while (dist) {
      long long raise_by = log2(dist);
      a = st[a][raise_by];
      dist -= (long long)(1 << raise_by);
    }
    if (a == b) return a;
    long long k = log2(n) + 1;
    for (long long j = k; j >= 0; j--) {
      if (st[a][j] != -1 and st[a][j] != st[b][j]) {
        a = st[a][j];
        b = st[b][j];
      }
    }
    return parent[a];
  }
  long long kth_ancestor(long long a, long long k) {
    while (k) {
      long long raise_by = log2(k);
      a = st[a][raise_by];
      k -= (long long)(1LL << raise_by);
      if (a == -1) return a;
    }
    return a;
  }
};
struct DSU {
  vector<long long> parent, sizz;
  DSU(long long n) {
    for (long long i = 0; i <= n; i++) parent.push_back(i);
    sizz.assign(n + 1, 1);
  }
  long long find_set(long long v) {
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent[v]);
  }
  void union_set(long long u, long long v) {
    u = find_set(u);
    v = find_set(v);
    if (v == u) return;
    if (sizz[u] > sizz[v]) swap(u, v);
    parent[u] = v;
    sizz[v] += sizz[u];
  }
};
void solve() {
  long long n, m;
  cin >> n >> m;
  DSU span_t(n);
  adj.resize(n + 1);
  vector<long long> freq(n + 1);
  vector<pair<long long, long long>> qr;
  while (m--) {
    long long x, y;
    cin >> x >> y;
    if (span_t.find_set(x) != span_t.find_set(y)) {
      span_t.union_set(x, y);
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
  }
  long long q;
  cin >> q;
  while (q--) {
    long long x, y;
    cin >> x >> y;
    freq[x]++;
    freq[y]++;
    qr.push_back({x, y});
  }
  long long odd = 0;
  for (long long i = 1; i <= n; i++) {
    if (freq[i] & 1) {
      odd++;
    }
  }
  if (odd > 0) {
    cout << "NO\n";
    cout << odd / 2 << "\n";
    return;
  }
  LCA lca_t;
  cout << "YES\n";
  for (auto &u : qr) {
    vector<long long> path;
    long long c_ances = lca_t.lca(u.first, u.second, n);
    while (u.first != c_ances) {
      path.push_back(u.first);
      u.first = lca_t.parent[u.first];
    }
    path.push_back(c_ances);
    vector<long long> tmp;
    while (u.second != c_ances) {
      tmp.push_back(u.second);
      u.second = lca_t.parent[u.second];
    }
    reverse((tmp).begin(), (tmp).end());
    cout << (long long)tmp.size() + (long long)path.size() << "\n";
    for (auto &u : path) cout << u << " ";
    for (auto &u : tmp) cout << u << " ";
    cout << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long testcases = 1;
  while (testcases--) solve();
  return 0;
}
