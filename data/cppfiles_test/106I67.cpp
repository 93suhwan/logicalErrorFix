#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios {
  fast_ios() {
    cin.tie(nullptr), ios::sync_with_stdio(false),
        cout << fixed << setprecision(20);
  };
} fast_ios_;
template <typename T, typename V>
void ndarray(vector<T> &vec, const V &val, int len) {
  vec.assign(len, val);
}
template <typename T, typename V, typename... Args>
void ndarray(vector<T> &vec, const V &val, int len, Args... args) {
  vec.resize(len),
      for_each(begin(vec), end(vec), [&](T &v) { ndarray(v, val, args...); });
}
template <typename T>
bool chmax(T &m, const T q) {
  return m < q ? (m = q, true) : false;
}
template <typename T>
bool chmin(T &m, const T q) {
  return m > q ? (m = q, true) : false;
}
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) {
  return make_pair(l.first + r.first, l.second + r.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) {
  return make_pair(l.first - r.first, l.second - r.second);
}
template <typename T>
vector<T> sort_unique(vector<T> vec) {
  sort(vec.begin(), vec.end()),
      vec.erase(unique(vec.begin(), vec.end()), vec.end());
  return vec;
}
template <typename T>
int arglb(const std::vector<T> &v, const T &x) {
  return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x));
}
template <typename T>
int argub(const std::vector<T> &v, const T &x) {
  return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x));
}
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << '[';
  for (auto v : vec) os << v << ',';
  os << ']';
  return os;
}
template <typename T, size_t sz>
ostream &operator<<(ostream &os, const array<T, sz> &arr) {
  os << '[';
  for (auto v : arr) os << v << ',';
  os << ']';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec) {
  os << "deq[";
  for (auto v : vec) os << v << ',';
  os << ']';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T, typename TH>
ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa) {
  os << '(' << pa.first << ',' << pa.second << ')';
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp) {
  os << '{';
  for (auto v : mp) os << v.first << "=>" << v.second << ',';
  os << '}';
  return os;
}
template <typename TK, typename TV, typename TH>
ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) {
  os << '{';
  for (auto v : mp) os << v.first << "=>" << v.second << ',';
  os << '}';
  return os;
}
template <class Cap, class Cost,
          Cost INF_COST = std::numeric_limits<Cost>::max() / 2>
struct MinCostFlow {
  template <class E>
  struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>> &edges)
        : start(n + 1), elist(edges.size()) {
      for (auto e : edges) {
        start[e.first + 1]++;
      }
      for (int i = 1; i <= n; i++) {
        start[i] += start[i - 1];
      }
      auto counter = start;
      for (auto e : edges) {
        elist[counter[e.first]++] = e.second;
      }
    }
  };

 public:
  MinCostFlow() {}
  explicit MinCostFlow(int n) : is_dual_infeasible(false), _n(n) {
    static_assert(std::numeric_limits<Cap>::max() > 0,
                  "max() must be greater than 0");
  }
  int add_edge(int from, int to, Cap cap, Cost cost) {
    assert(0 <= from && from < _n);
    assert(0 <= to && to < _n);
    assert(0 <= cap);
    if (cost < 0) is_dual_infeasible = true;
    int m = int(_edges.size());
    _edges.push_back({from, to, cap, 0, cost});
    return m;
  }
  struct edge {
    int from, to;
    Cap cap, flow;
    Cost cost;
  };
  edge get_edge(int i) {
    int m = int(_edges.size());
    assert(0 <= i && i < m);
    return _edges[i];
  }
  std::vector<edge> edges() { return _edges; }
  std::pair<Cap, Cost> flow(int s, int t) {
    return flow(s, t, std::numeric_limits<Cap>::max());
  }
  std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
    return slope(s, t, flow_limit).back();
  }
  std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
    return slope(s, t, std::numeric_limits<Cap>::max());
  }
  std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
    assert(0 <= s && s < _n);
    assert(0 <= t && t < _n);
    assert(s != t);
    int m = int(_edges.size());
    std::vector<int> edge_idx(m);
    auto g = [&]() {
      std::vector<int> degree(_n), redge_idx(m);
      std::vector<std::pair<int, _edge>> elist;
      elist.reserve(2 * m);
      for (int i = 0; i < m; i++) {
        auto e = _edges[i];
        edge_idx[i] = degree[e.from]++;
        redge_idx[i] = degree[e.to]++;
        elist.push_back({e.from, {e.to, -1, e.cap - e.flow, e.cost}});
        elist.push_back({e.to, {e.from, -1, e.flow, -e.cost}});
      }
      auto _g = csr<_edge>(_n, elist);
      for (int i = 0; i < m; i++) {
        auto e = _edges[i];
        edge_idx[i] += _g.start[e.from];
        redge_idx[i] += _g.start[e.to];
        _g.elist[edge_idx[i]].rev = redge_idx[i];
        _g.elist[redge_idx[i]].rev = edge_idx[i];
      }
      return _g;
    }();
    auto result = slope(g, s, t, flow_limit);
    for (int i = 0; i < m; i++) {
      auto e = g.elist[edge_idx[i]];
      _edges[i].flow = _edges[i].cap - e.cap;
    }
    return result;
  }

 private:
  bool is_dual_infeasible;
  int _n;
  std::vector<edge> _edges;
  struct _edge {
    int to, rev;
    Cap cap;
    Cost cost;
  };
  std::vector<std::pair<Cap, Cost>> slope(csr<_edge> &g, int s, int t,
                                          Cap flow_limit) {
    std::vector<std::pair<Cost, Cost>> dual_dist(_n);
    if (is_dual_infeasible) {
      auto check_dag = [&]() {
        std::vector<int> deg_in(_n);
        for (int v = 0; v < _n; v++) {
          for (int i = g.start[v]; i < g.start[v + 1]; i++) {
            deg_in[g.elist[i].to] += g.elist[i].cap > 0;
          }
        }
        std::vector<int> st;
        st.reserve(_n);
        for (int i = 0; i < _n; i++) {
          if (!deg_in[i]) st.push_back(i);
        }
        for (int n = 0; n < _n; n++) {
          if (int(st.size()) == n) return false;
          int now = st[n];
          for (int i = g.start[now]; i < g.start[now + 1]; i++) {
            const auto &e = g.elist[i];
            if (!e.cap) continue;
            deg_in[e.to]--;
            if (deg_in[e.to] == 0) st.push_back(e.to);
            if (dual_dist[e.to].first >= dual_dist[now].first + e.cost)
              dual_dist[e.to].first = dual_dist[now].first + e.cost;
          }
        }
        return true;
      }();
      if (!check_dag) throw;
      auto dt = dual_dist[t].first;
      for (int v = 0; v < _n; v++) dual_dist[v].first -= dt;
      is_dual_infeasible = false;
    }
    std::vector<int> prev_e(_n);
    std::vector<bool> vis(_n);
    struct Q {
      Cost key;
      int to;
      bool operator<(Q r) const { return key > r.key; }
    };
    std::vector<int> que_min;
    std::vector<Q> que;
    auto dual_ref = [&]() {
      for (int i = 0; i < _n; i++) {
        dual_dist[i].second = std::numeric_limits<Cost>::max();
      }
      std::fill(vis.begin(), vis.end(), false);
      que_min.clear();
      que.clear();
      unsigned heap_r = 0;
      dual_dist[s].second = 0;
      que_min.push_back(s);
      while (!que_min.empty() || !que.empty()) {
        int v;
        if (!que_min.empty()) {
          v = que_min.back();
          que_min.pop_back();
        } else {
          while (heap_r < que.size()) {
            heap_r++;
            std::push_heap(que.begin(), que.begin() + heap_r);
          }
          v = que.front().to;
          std::pop_heap(que.begin(), que.end());
          que.pop_back();
          heap_r--;
        }
        if (vis[v]) continue;
        vis[v] = true;
        if (v == t) break;
        Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;
        for (int i = g.start[v]; i < g.start[v + 1]; i++) {
          auto e = g.elist[i];
          if (!e.cap) continue;
          Cost cost = e.cost - dual_dist[e.to].first + dual_v;
          if (dual_dist[e.to].second - dist_v > cost) {
            Cost dist_to = dist_v + cost;
            dual_dist[e.to].second = dist_to;
            prev_e[e.to] = e.rev;
            if (dist_to == dist_v) {
              que_min.push_back(e.to);
            } else {
              que.push_back(Q{dist_to, e.to});
            }
          }
        }
      }
      if (!vis[t]) {
        return false;
      }
      for (int v = 0; v < _n; v++) {
        if (!vis[v]) continue;
        dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;
      }
      return true;
    };
    Cap flow = 0;
    Cost cost = 0, prev_cost_per_flow = -1;
    std::vector<std::pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};
    while (flow < flow_limit) {
      if (!dual_ref()) break;
      Cap c = flow_limit - flow;
      for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
        c = std::min(c, g.elist[g.elist[prev_e[v]].rev].cap);
      }
      for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
        auto &e = g.elist[prev_e[v]];
        e.cap += c;
        g.elist[e.rev].cap -= c;
      }
      Cost d = -dual_dist[s].first;
      flow += c;
      cost += c * d;
      if (prev_cost_per_flow == d) {
        result.pop_back();
      }
      result.push_back({flow, cost});
      prev_cost_per_flow = d;
    }
    return result;
  }
};
struct UnionFind {
  std::vector<int> par, cou;
  UnionFind(int N = 0) : par(N), cou(N, 1) { iota(par.begin(), par.end(), 0); }
  int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (cou[x] < cou[y]) std::swap(x, y);
    par[y] = x, cou[x] += cou[y];
    return true;
  }
  int count(int x) { return cou[find(x)]; }
  bool same(int x, int y) { return find(x) == find(y); }
};
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(1 << N);
  cin >> A;
  vector<vector<pint>> v2i(2);
  for (int s = (0), s_end_ = (1 << N); s < s_end_; s++) {
    int odd = __builtin_popcount(s) % 2;
    v2i[odd].emplace_back(A[s], s);
  }
  priority_queue<pair<int, pint>> pq;
  for (int s = (0), s_end_ = (1 << N); s < s_end_; s++) {
    int no = __builtin_parity(s);
    if (no) continue;
    for (int i = (0), i_end_ = (N); i < i_end_; i++) {
      int t = s ^ (1 << i);
      pq.emplace(A[s] + A[t], pint(s, t));
    }
  }
  vector<int> inuse(1 << N);
  vector<int> is[2];
  for (int k = (0), k_end_ = (K); k < k_end_; k++) {
    while (pq.size() and
           (inuse[pq.top().second.first] or inuse[pq.top().second.second]))
      pq.pop();
    int amax = -1;
    int imax = -1, jmax = -1;
    if (pq.size()) {
      amax = pq.top().first;
      tie(imax, jmax) = pq.top().second;
    }
    UnionFind uf(is[0].size() + is[1].size());
    for (int i = (0), i_end_ = (is[0].size()); i < i_end_; i++) {
      for (int j = (0), j_end_ = (is[1].size()); j < j_end_; j++) {
        int b = is[0][i] ^ is[1][j];
        if (__builtin_popcount(b) == 1) {
          uf.unite(i, is[0].size() + j);
        }
      }
    }
    vector<pint> hi0(uf.par.size(), {-(1 << 28), -1});
    vector<pint> hi1(uf.par.size(), {-(1 << 28), -1});
    for (int n = (0), n_end_ = (is[0].size()); n < n_end_; n++) {
      int i = is[0][n];
      for (int d = (0), d_end_ = (N); d < d_end_; d++)
        if (!inuse[i ^ (1 << d)])
          chmax(hi1[uf.find(n)], pint(A[i ^ (1 << d)], i ^ (1 << d)));
    }
    for (int n = (0), n_end_ = (is[1].size()); n < n_end_; n++) {
      int i = is[1][n];
      for (int d = (0), d_end_ = (N); d < d_end_; d++)
        if (!inuse[i ^ (1 << d)])
          chmax(hi0[uf.find(is[0].size() + n)],
                pint(A[i ^ (1 << d)], i ^ (1 << d)));
    }
    for (int d = (0), d_end_ = (uf.par.size()); d < d_end_; d++) {
      int asum = hi0[d].first + hi1[d].first;
      if (chmax(amax, asum)) imax = hi0[d].second, jmax = hi1[d].second;
    }
    if (amax < 0) break;
    is[0].push_back(imax);
    is[1].push_back(jmax);
    inuse[imax] = inuse[jmax] = 1;
  }
  lint ret = 0;
  for (int d = (0), d_end_ = (2); d < d_end_; d++)
    for (auto i : is[d]) ret += A[i];
  cout << ret << '\n';
}
