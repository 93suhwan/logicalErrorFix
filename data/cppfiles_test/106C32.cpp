#include <bits/stdc++.h>
namespace {
template <typename T, int kN, int kE = 600000>
struct CostFlow {
  const T inf = std::numeric_limits<T>::max();
  int s, t, head[kN], etot, prevv[kN], preve[kN];
  T dis[kN];
  struct Edge {
    int v, next;
    T cap, cost;
  } g[kE];
  void init() {
    memset(head, -1, sizeof(head));
    etot = 0;
  }
  void add_edge(int u, int v, T cap, T cost) {
    g[etot].v = v;
    g[etot].cap = cap;
    g[etot].cost = cost;
    g[etot].next = head[u];
    head[u] = etot++;
    g[etot].v = u;
    g[etot].cap = 0;
    g[etot].cost = -cost;
    g[etot].next = head[v];
    head[v] = etot++;
  }
  void spfa(int source) {
    static int inq[kN], que[kN], qf, qe;
    for (int i = 0; i < kN; i++) dis[i] = inf;
    dis[source] = 0;
    qf = qe = 0;
    que[qe++] = source;
    while (qf != qe) {
      int u = que[qf++];
      inq[u] = 0;
      if (qf == kN) qf = 0;
      for (int i = head[u]; i != -1; i = g[i].next) {
        Edge& e = g[i];
        if (e.cap && dis[e.v] > dis[u] + e.cost) {
          dis[e.v] = dis[u] + e.cost;
          prevv[e.v] = u;
          preve[e.v] = i;
          if (!inq[e.v]) {
            que[qe++] = e.v;
            if (qe == kN) qe = 0;
            inq[e.v] = 1;
          }
        }
      }
    }
  }
  void mcmf(int _s, int _t, T& cost, T& flow) {
    s = _s;
    t = _t;
    cost = flow = 0;
    while (true) {
      spfa(s);
      if (dis[t] == inf) break;
      T f = inf;
      for (int u = t; u != s; u = prevv[u]) f = std::min(f, g[preve[u]].cap);
      cost += f * dis[t];
      flow += f;
      for (int u = t; u != s; u = prevv[u])
        g[preve[u]].cap -= f, g[preve[u] ^ 1].cap += f;
    }
  }
  void mcmf(int _s, int _t, int k, T& cost, T& flow) {
    s = _s;
    t = _t;
    cost = flow = 0;
    for (int iteration = 0; iteration < k; ++iteration) {
      spfa(s);
      if (dis[t] == inf) break;
      T f = inf;
      for (int u = t; u != s; u = prevv[u]) f = std::min(f, g[preve[u]].cap);
      cost += f * dis[t];
      flow += f;
      for (int u = t; u != s; u = prevv[u])
        g[preve[u]].cap -= f, g[preve[u] ^ 1].cap += f;
    }
  }
};
using LL = long long;
const int kN = 16002;
CostFlow<LL, kN> network;
struct Solver {
  int n, k;
  std::vector<int> a;
  void solve(int ca, std::istream& reader) {
    reader >> n >> k;
    a.resize(1 << n);
    for (int i = 0; i < 1 << n; ++i) {
      reader >> a[i];
    }
    using Edge = std::tuple<int, int, int>;
    std::vector<Edge> edges;
    for (int b = 0; b < n; ++b) {
      for (int i = 0; i < 1 << n; ++i)
        if (~i >> b & 1) {
          edges.emplace_back(-(a[i] + a[i ^ 1 << b]), i, i ^ 1 << b);
        }
      int m = std::min<int>(edges.size(), 2 * n * k);
      (m > 0);
      std::nth_element(edges.begin(), edges.begin() + m - 1, edges.end());
      edges.resize(m);
    }
    network.init();
    int _s = kN - 2;
    int _t = _s + 1;
    std::vector<int> ss;
    for (const auto& [w, x, y] : edges) {
      ss.emplace_back(x);
      ss.emplace_back(y);
    }
    std::sort(ss.begin(), ss.end());
    ss.erase(std::unique(ss.begin(), ss.end()), ss.end());
    for (int i = 0; i < ss.size(); ++i) {
      int x = ss[i];
      if (__builtin_parity(x)) {
        network.add_edge(i, _t, 1, 0);
      } else {
        network.add_edge(_s, i, 1, 0);
      }
    }
    for (auto [w, x, y] : edges) {
      if (__builtin_parity(x)) {
        std::swap(x, y);
      }
      int p = std::lower_bound(ss.begin(), ss.end(), x) - ss.begin();
      int q = std::lower_bound(ss.begin(), ss.end(), y) - ss.begin();
      network.add_edge(p, q, 1, w);
    }
    LL cost = 0, flow = 0;
    network.mcmf(_s, _t, k, cost, flow);
    printf("%lld\n", -cost);
  }
};
}  // namespace
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;
  int cas = 1;
  for (int ca = 1; ca <= cas; ++ca) {
    Solver().solve(ca, reader);
  }
}
