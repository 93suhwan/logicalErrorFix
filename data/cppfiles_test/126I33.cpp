#line 2 "/home/maspy/library/my_template.hpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ll8 = __int128;
using ld = long double;
using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using vvvvvc = vector<vvvvc<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size)                                                                                                                                  \
    vector<type> name(size);                                                                                                                                   \
    IN(name)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                                                                                                                                   \
    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)                                                                                                                         \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))
#define FOR3(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))
#define FOR_R(i, n) for (ll i = (ll)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1; (i) >= (ll)(m); --(i))
#define FORIN(x, A) for (auto&& x : A)
#define FOR_nCk(s, n, k) \
  for (ll s = (1 << k) - 1, tmp_var = 0; s < (1 << n); \
  tmp_var = s | (s - 1), s = (tmp_var + 1) | (((~tmp_var & -~tmp_var) - 1) >> (__builtin_ctz(s) + 1))) 
#define FOR_SUB(t, s) for(ll t = s; t >= 0; t = (t==0 ? -1 : (t - 1) & s))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())

#define elif else if

using ull = unsigned long long;
using uint = unsigned int;
int popcnt(uint x) {
  return __builtin_popcount(x);
}
int popcnt(int x) {
  return __builtin_popcount(x);
}
int popcnt(ull x) {
  return __builtin_popcountll(x);
}
int popcnt(ll x) {
  return __builtin_popcountll(x);
}
int bsr(uint x) {
  return 31 - __builtin_clz(x);
}
int bsr(ull x) {
  return 63 - __builtin_clzll(x);
}
int ctz(int x) {
  return __builtin_ctz(x);
}
int ctz(ll x) {
  return __builtin_ctzll(x);
}
int ctz(ull x) {
  return __builtin_ctzll(x);
}

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))

#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())

ll ceil(ll x, ll y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}

ll floor(ll x, ll y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x - y + 1) / y);
}

ll mod(ll x, ll y) {
  return x - y * floor(x, y);
}

#define INT(...) \
  int __VA_ARGS__; \
  IN(__VA_ARGS__)
#define LL(...) \
  ll __VA_ARGS__; \
  IN(__VA_ARGS__)
#define STR(...) \
  string __VA_ARGS__; \
  IN(__VA_ARGS__)
#define CHR(...) \
  char __VA_ARGS__; \
  IN(__VA_ARGS__)
#define DBL(...) \
  long double __VA_ARGS__; \
  IN(__VA_ARGS__)
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &a) {for(auto &i : a) scan(i);}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
  scan(head);
  IN(tail...);
}

ll isqrt(ll n) {
  ll x = n, y = (n + 1) / 2;
  while (y < x) { tie(x, y) = mp(y, (y + n / y) / 2); }
  return x;
}

vi s_to_vi(string S, char first_char='a'){
  vi A(S.size());
  FOR(i, S.size()){
    A[i] = S[i] - first_char;
  }
  return A;
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& A) {
  os << A.fi << " " << A.se;
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    if(i) os << " ";
    os << A[i];
  }
  return os;
}

void print() {
  cout << "\n";
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}

const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }

template <typename T>
vector<T> cumsum(vector<T> A) {
  ll N = A.size();
  vector<T> B(N + 1);
  B[0] = T(0);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  return B;
}

vi bin_count(vi& A, ll size) {
  vi C(size);
  for (auto&& x : A) {
    ++C[x];
  }
  return C;
}

template <typename T>
vi argsort(vector<T>& A){
  vi ids(A.size());
  iota(all(ids), 0);
  sort(all(ids), [&](ll i, ll j){
    return A[i] < A[j] || (A[i] == A[j] && i < j);
  });
  return ids;
}

ll binary_search(function<bool(ll)> check, ll ok, ll ng) {
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    if (check(x))
      ok = x;
    else
      ng = x;
  }
  return ok;
}

template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }

template <typename T>
vc<T> merge_sort(vc<T>& A, vc<T>& B) {
  vc<T> C;
  C.reserve(A.size() + B.size());
  merge(all(A), all(B), back_inserter(C));
  return C;
}
#line 2 "main.cpp"

enum Objective {
  MINIMIZE = 1,
  MAXIMIZE = -1,
};
enum class Status {
  OPTIMAL,
  INFEASIBLE,
};

template <class Flow, class Cost, Objective objective = Objective::MINIMIZE,
          Flow SCALING_FACTOR = 2>
struct MinCostFlow {
private:
  using V_id = uint32_t;
  using E_id = uint32_t;

  struct Edge {
    friend struct MinCostFlow;

  private:
    V_id src, dst;
    Flow flow, cap;
    Cost cost;
    E_id rev;

  public:
    Edge() = default;

    Edge(const V_id src, const V_id dst, const Flow cap, const Cost cost,
         const E_id rev)
        : src(src), dst(dst), flow(0), cap(cap), cost(cost), rev(rev) {}

    [[nodiscard]] Flow residual_cap() const { return cap - flow; }
  };

public:
  struct EdgePtr {
    friend struct MinCostFlow;

  private:
    const MinCostFlow *instance;
    const V_id v;
    const E_id e;

    EdgePtr(const MinCostFlow *instance, const V_id v, const E_id e)
        : instance(instance), v(v), e(e) {}

    [[nodiscard]] const Edge &edge() const { return instance->g[v][e]; }

    [[nodiscard]] const Edge &rev() const {
      const Edge &e = edge();
      return instance->g[e.dst][e.rev];
    }

  public:
    [[nodiscard]] V_id src() const { return rev().dst; }

    [[nodiscard]] V_id dst() const { return edge().dst; }

    [[nodiscard]] Flow flow() const { return edge().flow; }

    [[nodiscard]] Flow lower() const { return -rev().cap; }

    [[nodiscard]] Flow upper() const { return edge().cap; }

    [[nodiscard]] Cost cost() const { return edge().cost; }

    [[nodiscard]] Cost gain() const { return -edge().cost; }
  };

private:
  V_id n;
  std::vector<std::vector<Edge>> g;
  std::vector<Flow> b;

public:
  MinCostFlow() : n(0) {}

  V_id add_vertex() {
    ++n;
    g.resize(n);
    b.resize(n);
    return n - 1;
  }

  std::vector<V_id> add_vertices(const size_t size) {
    std::vector<V_id> ret;
    for (V_id i = 0; i < size; ++i) ret.emplace_back(n + i);
    n += size;
    g.resize(n);
    b.resize(n);
    return ret;
  }

  EdgePtr add_edge(const V_id src, const V_id dst, const Flow lower,
                   const Flow upper, const Cost cost) {
    const E_id e = g[src].size(), re = src == dst ? e + 1 : g[dst].size();
    assert(lower <= upper);
    g[src].emplace_back(Edge{src, dst, upper, cost * objective, re});
    g[dst].emplace_back(Edge{dst, src, -lower, -cost * objective, e});
    return EdgePtr{this, src, e};
  }

  void add_supply(const V_id v, const Flow amount) { b[v] += amount; }

  void add_demand(const V_id v, const Flow amount) { b[v] -= amount; }

private:
  static Cost constexpr unreachable = std::numeric_limits<Cost>::max();
  Cost farthest;
  std::vector<Cost> potential;
  std::vector<Cost> dist;
  std::vector<Edge *> parent;
  std::priority_queue<std::pair<Cost, int>, std::vector<std::pair<Cost, int>>,
                      std::greater<>>
    pq;
  std::vector<V_id> excess_vs, deficit_vs;

  Edge &rev(const Edge &e) { return g[e.dst][e.rev]; }

  void push(Edge &e, const Flow amount) {
    e.flow += amount;
    g[e.dst][e.rev].flow -= amount;
  }

  Cost residual_cost(const V_id src, const V_id dst, const Edge &e) {
    return e.cost + potential[src] - potential[dst];
  }

  bool dual(const Flow delta) {
    dist.assign(n, unreachable);
    parent.assign(n, nullptr);
    excess_vs.erase(std::remove_if(std::begin(excess_vs), std::end(excess_vs),
                                   [&](const V_id v) { return b[v] < delta; }),
                    std::end(excess_vs));
    deficit_vs.erase(
      std::remove_if(std::begin(deficit_vs), std::end(deficit_vs),
                     [&](const V_id v) { return b[v] > -delta; }),
      std::end(deficit_vs));
    for (const auto v : excess_vs) pq.emplace(dist[v] = 0, v);
    farthest = 0;
    std::size_t deficit_count = 0;
    while (!pq.empty()) {
      const auto [d, u] = pq.top();
      pq.pop();
      if (dist[u] < d) continue;
      farthest = d;
      if (b[u] <= -delta) ++deficit_count;
      if (deficit_count >= deficit_vs.size()) break;
      for (auto &e : g[u]) {
        if (e.residual_cap() < delta) continue;
        const auto v = e.dst;
        const auto new_dist = d + residual_cost(u, v, e);
        if (new_dist >= dist[v]) continue;
        pq.emplace(dist[v] = new_dist, v);
        parent[v] = &e;
      }
    }
    pq = decltype(pq)();
    for (V_id v = 0; v < n; ++v) {
      potential[v] += std::min(dist[v], farthest);
    }
    return deficit_count > 0;
  }

  void primal(const Flow delta) {
    for (const auto t : deficit_vs) {
      if (dist[t] > farthest) continue;
      Flow f = -b[t];
      V_id v;
      for (v = t; parent[v] != nullptr && f >= delta; v = parent[v]->src) {
        f = std::min(f, parent[v]->residual_cap());
      }
      f = std::min(f, b[v]);
      if (f < delta) continue;
      for (v = t; parent[v] != nullptr;) {
        auto &e = *parent[v];
        push(e, f);
        const size_t u = parent[v]->src;
        parent[v] = nullptr;
        v = u;
      }
      b[t] += f;
      b[v] -= f;
    }
  }

  void saturate_negative(const Flow delta) {
    excess_vs.clear();
    deficit_vs.clear();
    for (auto &es : g)
      for (auto &e : es) {
        const Flow rcap = e.residual_cap();
        const Cost rcost = residual_cost(e.src, e.dst, e);
        if (rcost < 0 && rcap >= delta) {
          push(e, rcap);
          b[e.src] -= rcap;
          b[e.dst] += rcap;
        }
      }
    for (V_id v = 0; v < n; ++v)
      if (b[v] != 0) { (b[v] > 0 ? excess_vs : deficit_vs).emplace_back(v); }
  }

public:
  std::pair<Status, Cost> solve() {
    potential.resize(n);
    for (auto &es : g)
      for (auto &e : es) {
        const Flow rcap = e.residual_cap();
        if (rcap < 0) {
          push(e, rcap);
          b[e.src] -= rcap;
          b[e.dst] += rcap;
        }
      }

    Flow inf_flow = 1;
    for (const auto &es : g)
      for (const auto &e : es) inf_flow = std::max(inf_flow, e.residual_cap());
    Flow delta = 1;
    while (delta <= inf_flow) delta *= SCALING_FACTOR;

    for (delta /= SCALING_FACTOR; delta; delta /= SCALING_FACTOR) {
      saturate_negative(delta);
      while (dual(delta)) primal(delta);
    }

    Cost value = 0;
    for (const auto &es : g)
      for (const auto &e : es) { value += e.flow * e.cost; }
    value /= 2;

    if (excess_vs.empty() && deficit_vs.empty()) {
      return {Status::OPTIMAL, value / objective};
    } else {
      return {Status::INFEASIBLE, value / objective};
    }
  }

  template <class T>
  T get_result_value() {
    T value = 0;
    for (const auto &es : g)
      for (const auto &e : es) { value += (T)(e.flow) * (T)(e.cost); }
    value /= (T)2;
    return value / objective;
  }

  std::vector<Cost> get_potential() {
    std::fill(potential.begin(), potential.end(), 0);
    for (int i = 0; i < n; i++)
      for (const auto &es : g)
        for (const auto &e : es)
          if (e.residual_cap() > 0)
            potential[e.dst] =
              std::min(potential[e.dst], potential[e.src] + e.cost);
    return potential;
  }
};

void solve() {
  LL(N, M);
  VEC(ll, A, N);
  using T = long long;
  MinCostFlow<T, T> MCF;
  MCF.add_vertices(N + 1);
  FOR(v, N + 1) MCF.add_supply(v, 0);

  T INF = 1LL << 61;

  vector<MinCostFlow<T, T>::EdgePtr> edges;
  FOR(v, N) {
    edges.eb(MCF.add_edge(v, N, 0, 1, 0));
    edges.eb(MCF.add_edge(N, v, 0, 1, 0));
  }
  FOR(_, M) {
    LL(u, v);
    --u, --v;
    edges.eb(MCF.add_edge(v, u, 0, INF, A[v] - A[u]));
  }

  auto p = MCF.solve();
  T res_value = MCF.get_result_value<T>();
  vi ANS(N);
  auto P = MCF.get_potential();
  FOR(v, N) ANS[v] = A[v] + P[v] - P[N];
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  // LL(T);
  ll T = 1;
  FOR(_, T) solve();

  return 0;
}
