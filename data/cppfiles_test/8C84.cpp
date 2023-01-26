#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-12;
const int INF = 1e9 + 10;
template <typename T>
using MinPQ = priority_queue<T, vector<T>, greater<T>>;
template <class T>
struct FenwickTree {
  int n;
  vector<T> a;
  vector<T> f;
  FenwickTree(int n = 0) { Reset(n); }
  void Reset(int n) {
    this->n = n;
    a.assign(n + 1, 0);
    f.assign(n + 1, 0);
  }
  T Query(int i) {
    assert(i >= 0 && i <= n);
    T r = 0;
    for (; i > 0; i -= LowBit(i)) {
      r += f[i];
    }
    return r;
  }
  T Query(int l, int r) {
    T res = Query(r);
    if (l > 1) res -= Query(l - 1);
    return res;
  }
  T QueryAll() { return Query(n); }
  void Add(int i, T x) {
    assert(i >= 1 && i <= n);
    a[i] += x;
    for (; i <= n; i += LowBit(i)) {
      f[i] += x;
    }
  }
  void Set(int i, T x) { Add(i, x - a[i]); }

 private:
  static inline int LowBit(int i) { return i & -i; }
};
template <class T>
struct Rmq {
  int n;
  vector<T> a;
  vector<vector<int>> f;
  vector<int> f_idx;
  Rmq(const vector<T>& a = {}) { Reset(a); }
  void Reset(const vector<T>& a) {
    this->a = a;
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
    if (a[u1] < a[u2]) return u1;
    return u2;
  }
};
int n;
vector<int> a;
vector<pair<int, int>> edges;
vector<vector<int>> child;
vector<int> par;
vector<int> depth;
vector<int> e_seq;
vector<pair<int, int>> e_pos;
vector<int> u_seq;
vector<int> u_pos;
struct EdgeStatus {
  set<int> updated;
};
vector<EdgeStatus> child_edge_status;
int Cost(int ei) {
  assert(ei >= 0 && ei < n - 1);
  int u = edges[ei].first, v = edges[ei].second;
  return max(abs(a[u] + a[v]), abs(a[u] - a[v]));
}
void Dfs(int u, int pu) {
  u_pos[u] = int((u_seq).size());
  u_seq.push_back(u);
  for (int i = 0; i < int((child[u]).size()); ++i) {
    int ei = child[u][i];
    auto& e = edges[ei];
    if (e.first == pu) {
      par[u] = ei;
      child[u][i] = child[u].back();
      child[u].pop_back();
      i--;
      continue;
    }
    if (e.second == u) swap(e.first, e.second);
    depth[e.second] = depth[u] + 1;
    e_pos[ei].first = int((e_seq).size());
    e_seq.push_back(ei);
    Dfs(e.second, u);
    e_pos[ei].second = int((e_seq).size());
    e_seq.push_back(ei);
    u_seq.push_back(u);
  }
}
void Solve() {
  int q;
  scanf("%d%d", &n, &q);
  a.resize(n);
  for (auto& x : (a)) scanf("%d", &x);
  edges.resize(n - 1);
  child.assign(n, {});
  for (int i = 0; i < n - 1; ++i) {
    auto& e = edges[i];
    scanf("%d%d", &e.first, &e.second);
    e.first--;
    e.second--;
    child[e.first].push_back(i);
    child[e.second].push_back(i);
  }
  e_seq.clear();
  e_seq.reserve(n * 2);
  e_pos.resize(n - 1);
  u_seq.clear();
  u_seq.reserve(n * 2);
  u_pos.resize(n);
  par.resize(n);
  depth.resize(n);
  depth[0] = 0;
  par[0] = -1;
  Dfs(0, -1);
  vector<int> depth_seq(int((u_seq).size()));
  for (int i = 0; i < int((u_seq).size()); ++i) {
    depth_seq[i] = depth[u_seq[i]];
  }
  Rmq<int> rmq(depth_seq);
  vector<int> cost_seq(int((e_seq).size()));
  for (int i = 0; i < n - 1; ++i) {
    int w = Cost(i);
    cost_seq[e_pos[i].first] = w;
    cost_seq[e_pos[i].second] = -w;
  }
  FenwickTree<long long> cost_ft;
  cost_ft.Reset(int((cost_seq).size()));
  for (int i = 0; i < int((cost_seq).size()); ++i) {
    cost_ft.Set(i + 1, cost_seq[i]);
  }
  child_edge_status.resize(n);
  for (int i = 0; i < n; ++i) {
    child_edge_status[i].updated =
        set<int>((child[i]).begin(), (child[i]).end());
  }
  set<int> e_seq_idx_to_update;
  auto UpdateEdge = [&](int ei) {
    int w = Cost(ei);
    cost_ft.Set(e_pos[ei].first + 1, w);
    cost_ft.Set(e_pos[ei].second + 1, -w);
    int u = edges[ei].first;
    child_edge_status[u].updated.insert(ei);
  };
  auto Query = [&](int u, int v) -> long long {
    int up = u_pos[u], vp = u_pos[v];
    assert(up <= vp);
    if (up == vp) return 0;
    vp--;
    auto it = e_seq_idx_to_update.lower_bound(up);
    while (it != e_seq_idx_to_update.end() && *it <= vp) {
      UpdateEdge(e_seq[*it]);
      it = e_seq_idx_to_update.erase(it);
    }
    return cost_ft.Query(up + 1, vp + 1);
  };
  while (q--) {
    int op, u, v;
    scanf("%d%d%d", &op, &u, &v);
    --u;
    if (op == 1) {
      a[u] = v;
      for (auto& ei : (child_edge_status[u].updated)) {
        e_seq_idx_to_update.insert(e_pos[ei].first);
        e_seq_idx_to_update.insert(e_pos[ei].second);
      }
      child_edge_status[u].updated.clear();
      if (par[u] >= 0) {
        int ei = par[u];
        int pu = edges[ei].first;
        child_edge_status[pu].updated.erase(ei);
        e_seq_idx_to_update.insert(e_pos[ei].first);
        e_seq_idx_to_update.insert(e_pos[ei].second);
      }
    } else {
      --v;
      int lca = u_seq[rmq.QueryIndex(u_pos[u], u_pos[v])];
      42;
      long long w = Query(lca, u) + Query(lca, v);
      printf("%lld\n", w);
    }
  }
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; ++i) {
    Solve();
  }
  return 0;
}
