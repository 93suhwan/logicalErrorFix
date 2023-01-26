#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-12;
const int INF = 1e9 + 10;
template <typename T>
inline void UpdateMax(T& x, T v) {
  x = max(x, v);
}
template <typename T>
inline void UpdateMin(T& x, T v) {
  x = min(x, v);
}
template <typename T>
using MinPQ = priority_queue<T, vector<T>, greater<T>>;
template <class T>
struct Rmq {
  int n;
  const vector<T>* ptr_a;
  vector<vector<int>> f;
  vector<int> f_idx;
  Rmq(const vector<T>& a = {}) { Reset(a); }
  void Reset(const vector<T>& a) {
    ptr_a = &a;
    n = int((a).size());
    vector<int> cur(n);
    iota((cur).begin(), (cur).end(), 0);
    f.clear();
    f.push_back(move(cur));
    if (n == 0) return;
    for (int p = 1;; ++p) {
      int len = 1 << p;
      int len2 = len >> 1;
      cur.resize(n - len + 1);
      for (int i = 0; i < int((cur).size()); ++i) {
        int u1 = f[p - 1][i], u2 = f[p - 1][i + len - len2];
        if (a[u1] < a[u2])
          cur[i] = u1;
        else
          cur[i] = u2;
      }
      f.push_back(move(cur));
      if ((len << 1) >= n) break;
    }
    f_idx.resize(n + 1);
    f_idx[0] = 0;
    for (int i = 1; i <= n; ++i) {
      int p = f_idx[i >> 1];
      while (1 << (p + 1) < i) ++p;
      f_idx[i] = p;
    }
  }
  int QueryIndex(int l, int r) {
    if (l > r) swap(l, r);
    int len = r - l + 1;
    int p = f_idx[len];
    int u1 = f[p][l], u2 = f[p][r - (1 << p) + 1];
    if ((*ptr_a)[u1] < (*ptr_a)[u2]) return u1;
    return u2;
  }
  int QueryValue(int l, int r) { return (*ptr_a)[QueryIndex(l, r)]; }
};
struct Lca {
  int n;
  vector<int> depth;
  vector<int> seq;
  vector<int> pos;
  Rmq<int> rmq;
  vector<int> depth_seq;
  void Dfs(int u, int pu, int d, const vector<vector<int>>& adj) {
    depth[u] = d;
    if (pos[u] < 0) pos[u] = int((seq).size());
    seq.push_back(u);
    for (auto& v : (adj[u])) {
      if (v == pu) continue;
      Dfs(v, u, d + 1, adj);
      seq.push_back(u);
    }
  }
  void Reset(const vector<vector<int>>& adj, int root) {
    n = int((adj).size());
    depth.resize(n);
    seq.clear();
    pos.assign(n, -1);
    Dfs(root, -1, 0, adj);
    depth_seq.resize(int((seq).size()));
    for (int i = 0; i < int((seq).size()); ++i) depth_seq[i] = depth[seq[i]];
    rmq.Reset(depth_seq);
  }
  int Query(int u, int v) { return seq[rmq.QueryIndex(pos[u], pos[v])]; }
};
int n, m;
vector<vector<int>> adj;
vector<int> fa;
vector<int> dep;
vector<int> sc, ec;
vector<int> cnt;
vector<int> f, g;
Lca lca;
void Dfs(int u) {
  for (int i = 0; i < int((adj[u]).size());) {
    int v = adj[u][i];
    if (dep[v] < 0) {
      fa[v] = u;
      dep[v] = dep[u] + 1;
      Dfs(v);
      ++i;
    } else {
      adj[u][i] = adj[u].back();
      adj[u].pop_back();
    }
  }
}
void Mark(int u, int& w) {
  w += sc[u] - ec[u];
  for (auto& v : (adj[u])) {
    cnt[v] += w;
    Mark(v, w);
    cnt[v] += w;
    cnt[v] %= 2;
    42;
  }
}
void Com(int u) {
  f[u] = g[u] = 0;
  for (auto& v : (adj[u])) {
    Com(v);
    f[u] += f[v];
    if (cnt[v]) {
      if (g[v]) f[u]--;
      g[u]++;
    }
  }
  f[u] += g[u] / 2;
  g[u] %= 2;
  f[u] += g[u];
  42;
}
vector<int> GetLink(int u, int r) {
  vector<int> qu;
  qu.push_back(u);
  while (u != r) {
    u = fa[u];
    qu.push_back(u);
  }
  return qu;
}
void GetPath(pair<int, int> u, int r) {
  vector<int> qu = GetLink(u.first, r);
  vector<int> qv = GetLink(u.second, r);
  reverse((qv).begin(), (qv).end());
  qv.erase(qv.begin());
  printf("%d\n", int((qu).size()) + int((qv).size()));
  for (auto& x : (qu)) printf("%d ", x + 1);
  for (auto& x : (qv)) printf("%d ", x + 1);
  printf("\n");
}
void Solve() {
  scanf("%d%d", &n, &m);
  adj.assign(n, {});
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  fa.resize(n);
  dep.assign(n, -1);
  dep[0] = 0;
  Dfs(0);
  lca.Reset(adj, 0);
  sc.assign(n, 0);
  ec.assign(n, 0);
  int nq;
  vector<pair<pair<int, int>, int>> qs;
  scanf("%d", &nq);
  while (nq--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    int r = lca.Query(u, v);
    qs.push_back({{u, v}, r});
    sc[r]++, ec[u]++;
    sc[r]++, ec[v]++;
  }
  cnt.assign(n, 0);
  {
    int w = 0;
    Mark(0, w);
  }
  f.resize(n);
  g.resize(n);
  Com(0);
  int ans = f[0];
  if (ans == 0) {
    printf("YES\n");
    for (auto& q : (qs)) GetPath(q.first, q.second);
  } else
    printf("NO\n%d\n", ans);
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; ++i) {
    Solve();
  }
  return 0;
}
