#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-12;
const int INF = 1e9 + 10;
template <typename T>
using MinPQ = priority_queue<T, vector<T>, greater<T>>;
struct ModInt {
  static constexpr int MOD = 1e9 + 7;
  int v = 0;
  ModInt() {}
  ModInt(long long x) {
    v = x % MOD;
    if (v < 0) v += MOD;
  }
  friend inline bool operator==(const ModInt& l, const ModInt& r) {
    return l.v == r.v;
  }
  friend inline bool operator!=(const ModInt& l, const ModInt& r) {
    return !(l == r);
  }
  ModInt& operator+=(const ModInt& r) {
    v += r.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  ModInt& operator-=(const ModInt& r) {
    v -= r.v;
    if (v < 0) v += MOD;
    return *this;
  }
  ModInt& operator*=(const ModInt& r) {
    v = ((long long)v * r.v) % MOD;
    return *this;
  }
  friend ModInt operator+(ModInt l, const ModInt& r) {
    l += r;
    return l;
  }
  friend ModInt operator-(ModInt l, const ModInt& r) {
    l -= r;
    return l;
  }
  friend ModInt operator*(ModInt l, const ModInt& r) {
    l *= r;
    return l;
  }
  ModInt Pow(long long n) {
    if (!n) return 1;
    ModInt r = Pow(n >> 1);
    r *= r;
    if (n & 1) r *= v;
    return r;
  }
};
template <typename T, typename U>
pair<T, U> operator+(const pair<T, U>& l, const pair<T, U>& r) {
  return {l.first + r.first, l.second + r.second};
}
template <typename T, typename U>
pair<T, U> operator-(const pair<T, U>& l, const pair<T, U>& r) {
  return {l.first - r.first, l.second - r.second};
}
struct FenwickTree {
  using T = pair<int, ModInt>;
  int n;
  vector<T> a;
  vector<T> f;
  FenwickTree(int n = 0) { Reset(n); }
  void Reset(int n) {
    this->n = n;
    a.assign(n + 1, {0, 0});
    f.assign(n + 1, {0, 0});
  }
  T Query(int i) {
    i = min(i, n);
    assert(i >= 0 && i <= n);
    T r = {0, 0};
    for (; i > 0; i -= LowBit(i)) {
      r = r + f[i];
    }
    return r;
  }
  T Query(int l, int r) {
    T res = Query(r);
    if (l > 1) res = res - Query(l - 1);
    return res;
  }
  T QueryAll() { return Query(n); }
  void Add(int i, T x) {
    assert(i >= 1 && i <= n);
    a[i] = a[i] + x;
    for (; i <= n; i += LowBit(i)) {
      f[i] = f[i] + x;
    }
  }
  void Set(int i, T x) { Add(i, x - a[i]); }

 private:
  static inline int LowBit(int i) { return i & -i; }
};
vector<int> a;
int max_switch;
ModInt ans;
struct CentroidDecomp {
  using E = int;
  int n;
  vector<vector<pair<int, E>>> adj;
  struct Node {
    int par;
    int dep;
    vector<E> up_dis;
    vector<int> child;
    int dfn;
    int last_des_dfn;
  };
  vector<Node> nodes;
  vector<int> child_idx;
  vector<int> dfsq;
  CentroidDecomp(int n = 0) { Reset(n); }
  void Reset(int n) {
    this->n = n;
    adj.assign(n, {});
  }
  void AddEdge(int u, int v, E e) {
    adj[u].emplace_back(v, e);
    adj[v].emplace_back(u, e);
  }
  void Build() {
    size.assign(n, 0);
    nodes.assign(n, Node());
    {
      int c = 0;
      int u = n + 1;
      while (u > 0) {
        ++c;
        u >>= 1;
      }
      for (int i = 0; i < n; ++i) nodes[i].up_dis.reserve(c);
    }
    fu.resize(n);
    DfsSize(0, -1);
    child_idx.assign(n, -1);
    dfsq.clear();
    dfsq.reserve(n);
    BuildSubtree(0, -1);
    if (0) {
      for (int i = 0; i < n; ++i) {
        Node& node = nodes[i];
        42;
      }
    }
  }

 private:
  vector<int> size;
  void FindCentroid(int r, int& cen, int& p_cen) {
    cen = r;
    p_cen = -1;
    bool found;
    do {
      found = 0;
      for (auto& e : (adj[cen])) {
        int v = e.first;
        if (v == p_cen || size[v] < 0) continue;
        if (size[v] * 2 >= size[r]) {
          p_cen = cen;
          cen = v;
          found = 1;
          break;
        }
      }
    } while (found);
  }
  vector<vector<pair<int, ModInt>>> fu;
  FenwickTree f[2];
  void Dfs(int u, int pu, int sw, ModInt sum, int prev_e,
           vector<pair<int, ModInt>>& tmp) {
    if (sw > max_switch) return;
    42;
    if (sw >= int((tmp).size())) {
      tmp.resize(sw + 1, {0, 0});
    }
    tmp[sw].first++;
    tmp[sw].second += sum;
    for (auto [v, e] : adj[u]) {
      if (size[v] < 0 || v == pu) continue;
      Dfs(v, u, sw + (prev_e != e), sum + a[v], e, tmp);
    }
  }
  void Com(int cen) {
    42;
    ans += a[cen];
    int max_sz = 0;
    for (auto [u, e] : adj[cen]) {
      if (size[u] < 0) continue;
      fu[u].clear();
      Dfs(u, cen, 0, ModInt(a[u]), e, fu[u]);
      max_sz = max(max_sz, int((fu[u]).size()));
    }
    f[0].Reset(max_sz + 1);
    f[1].Reset(max_sz + 1);
    for (auto [u, e] : adj[cen]) {
      if (size[u] < 0) continue;
      const auto& tmp = fu[u];
      for (int i = 0; i < int((tmp).size()); ++i) {
        int mf = max_switch - i;
        if (mf >= 0) {
          auto u = f[e].Query(mf + 1);
          ans += tmp[i].second * u.first + u.second * tmp[i].first +
                 ModInt(a[cen]) * tmp[i].first * u.first;
        }
        mf = max_switch - i - 1;
        if (mf >= 0) {
          auto u = f[1 - e].Query(mf + 1);
          ans += tmp[i].second * u.first + u.second * tmp[i].first +
                 ModInt(a[cen]) * tmp[i].first * u.first;
        }
      }
      for (int i = 0; i < int((tmp).size()); ++i) {
        f[e].Add(i + 1, tmp[i]);
      }
    }
    42;
    {
      auto u = f[0].QueryAll();
      ans += u.second + ModInt(a[cen]) * u.first;
      u = f[1].QueryAll();
      ans += u.second + ModInt(a[cen]) * u.first;
    }
    42;
  }
  void BuildSubtree(int r, int pr) {
    42;
    int cen;
    {
      int p_cen;
      FindCentroid(r, cen, p_cen);
      nodes[cen].par = pr;
      nodes[cen].dep = (pr < 0) ? 0 : nodes[pr].dep + 1;
      Com(cen);
      size[cen] = -1;
      if (p_cen >= 0 && size[p_cen] >= 0) DfsSize(p_cen, -1);
    }
    nodes[cen].dfn = int((dfsq).size());
    dfsq.push_back(cen);
    if (pr >= 0) {
      child_idx[cen] = int((nodes[pr].child).size());
      nodes[pr].child.push_back(cen);
    }
    42;
    for (auto& e : (adj[cen])) {
      int v = e.first;
      if (size[v] < 0) continue;
      BuildSubtree(v, cen);
    }
    nodes[cen].last_des_dfn = int((dfsq).size()) - 1;
  }
  void DfsSize(int u, int pu) {
    size[u] = 1;
    for (auto& e : (adj[u])) {
      int v = e.first;
      if (v == pu || size[v] < 0) continue;
      DfsSize(v, u);
      size[u] += size[v];
    }
  }
  void DfsDis(int u, int pu, E sum_e) {
    nodes[u].up_dis.push_back(sum_e);
    for (auto& e : (adj[u])) {
      int v = e.first;
      if (v == pu || size[v] < 0) continue;
      DfsDis(v, u, sum_e + e.second);
    }
  }
};
CentroidDecomp cd;
void Solve() {
  int n;
  scanf("%d%d", &n, &max_switch);
  a.resize(n);
  for (auto& x : (a)) scanf("%d", &x);
  cd.Reset(n);
  for (int i = 1; i < n; ++i) {
    int u, v, e;
    scanf("%d%d%d", &u, &v, &e);
    --u;
    --v;
    cd.AddEdge(u, v, e);
  }
  ans = 0;
  cd.Build();
  printf("%d\n", ans.v);
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; ++i) {
    Solve();
  }
  return 0;
}
