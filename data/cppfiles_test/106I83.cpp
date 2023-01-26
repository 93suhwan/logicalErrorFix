#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
template <class t, class u>
bool chmax(t& first, u second) {
  if (first < second) {
    first = second;
    return true;
  } else
    return false;
}
template <class t, class u>
bool chmin(t& first, u second) {
  if (second < first) {
    first = second;
    return true;
  } else
    return false;
}
template <class t>
using vc = vector<t>;
template <class t>
using vvc = vc<vc<t>>;
using pi = pair<int, int>;
using vi = vc<int>;
template <class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << "," << p.second << "}";
}
template <class t>
ostream& operator<<(ostream& os, const vc<t>& v) {
  os << "{";
  for (auto e : v) os << e << ",";
  return os << "}";
}
using uint = unsigned;
using ull = unsigned long long;
template <class t, size_t n>
ostream& operator<<(ostream& os, const array<t, n>& first) {
  return os << vc<t>(first.begin(), first.end());
}
template <int i, class T>
void print_tuple(ostream&, const T&) {}
template <int i, class T, class H, class... Args>
void print_tuple(ostream& os, const T& t) {
  if (i) os << ",";
  os << get<i>(t);
  print_tuple<i + 1, T, Args...>(os, t);
}
template <class... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
  os << "{";
  print_tuple<0, tuple<Args...>, Args...>(os, t);
  return os << "}";
}
template <class t>
void print(t x, int suc = 1) {
  cout << x;
  if (suc == 1) cout << "\n";
  if (suc == 2) cout << " ";
}
ll read() {
  ll i;
  cin >> i;
  return i;
}
vi readvi(int n, int off = 0) {
  vi v(n);
  for (int i = int(0); i < int(n); i++) v[i] = read() + off;
  return v;
}
pi readpi(int off = 0) {
  int first, second;
  cin >> first >> second;
  return pi(first + off, second + off);
}
template <class t, class u>
void print(const pair<t, u>& p, int suc = 1) {
  print(p.first, 2);
  print(p.second, suc);
}
template <class T>
void print(const vector<T>& v, int suc = 1) {
  for (int i = int(0); i < int(v.size()); i++)
    print(v[i], i == int(v.size()) - 1 ? suc : 2);
}
template <class T>
void print_offset(const vector<T>& v, ll off, int suc = 1) {
  for (int i = int(0); i < int(v.size()); i++)
    print(v[i] + off, i == int(v.size()) - 1 ? suc : 2);
}
template <class T, size_t N>
void print(const array<T, N>& v, int suc = 1) {
  for (int i = int(0); i < int(N); i++) print(v[i], i == int(N) - 1 ? suc : 2);
}
string readString() {
  string s;
  cin >> s;
  return s;
}
template <class T>
T sq(const T& t) {
  return t * t;
}
void yes(bool ex = true) {
  cout << "Yes"
       << "\n";
  if (ex) exit(0);
}
void no(bool ex = true) {
  cout << "No"
       << "\n";
  if (ex) exit(0);
}
void possible(bool ex = true) {
  cout << "Possible"
       << "\n";
  if (ex) exit(0);
}
void impossible(bool ex = true) {
  cout << "Impossible"
       << "\n";
  if (ex) exit(0);
}
constexpr ll ten(int n) { return n == 0 ? 1 : ten(n - 1) * 10; }
const ll infLL = LLONG_MAX / 3;
const int inf = INT_MAX / 2 - 100;
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(signed first) { return first == 0 ? 32 : __builtin_ctz(first); }
int botbit(ll first) { return first == 0 ? 64 : __builtin_ctzll(first); }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }
ll mask(int i) { return (ll(1) << i) - 1; }
bool inc(int first, int second, int c) {
  return first <= second && second <= c;
}
template <class t>
void mkuni(vc<t>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
ll rand_int(ll l, ll r) {
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<ll>(l, r)(gen);
}
template <class t>
void myshuffle(vc<t>& first) {
  for (int i = int(0); i < int(int(first.size())); i++)
    swap(first[i], first[rand_int(0, i)]);
}
template <class t>
int lwb(const vc<t>& v, const t& first) {
  return lower_bound(v.begin(), v.end(), first) - v.begin();
}
vvc<int> readGraph(int n, int m) {
  vvc<int> g(n);
  for (int i = int(0); i < int(m); i++) {
    int first, second;
    cin >> first >> second;
    first--;
    second--;
    g[first].push_back(second);
    g[second].push_back(first);
  }
  return g;
}
vvc<int> readTree(int n) { return readGraph(n, n - 1); }
template <class D>
struct mincf {
  using P = pair<D, int>;
  struct E {
    int to, rev, cap;
    D cost;
  };
  int n;
  vvc<E> g;
  vc<D> h, d;
  vi pv, pe;
  mincf(int nn) : n(nn), g(n), h(n), d(n), pv(n), pe(n) {}
  pi ae(int first, int second, int cap, D cost) {
    pi res(first, g[first].size());
    g[first].push_back({second, (int)g[second].size(), cap, cost});
    g[second].push_back({first, (int)g[first].size() - 1, 0, -cost});
    return res;
  }
  P go(int s, int t, int f) {
    static vc<P> q;
    q.clear();
    fill(d.begin(), d.end(), inf);
    d[s] = 0;
    auto push = [&](D w, int v) {
      q.emplace_back(w, v);
      push_heap(q.begin(), q.end(), greater<P>());
    };
    auto pop = [&]() {
      pop_heap(q.begin(), q.end(), greater<P>());
      auto res = q.back();
      q.pop_back();
      return res;
    };
    push(0, s);
    while (q.size()) {
      D first;
      int v;
      tie(first, v) = pop();
      if (d[v] < first) continue;
      if (v == t) break;
      for (int i = int(0); i < int((int)g[v].size()); i++) {
        E e = g[v][i];
        if (e.cap > 0) {
          D w = d[v] + e.cost + h[v] - h[e.to];
          if (w < d[e.to]) {
            d[e.to] = w;
            push(w, e.to);
            pv[e.to] = v;
            pe[e.to] = i;
          }
        }
      }
    }
    if (d[t] == inf) return P(0, 0);
    for (int i = int(0); i < int(n); i++)
      h[i] = min<D>(h[i] + min(d[i], d[t]), inf);
    int first = f;
    for (int v = t; v != s; v = pv[v]) chmin(first, g[pv[v]][pe[v]].cap);
    for (int v = t; v != s; v = pv[v]) {
      E& e = g[pv[v]][pe[v]];
      e.cap -= first;
      g[e.to][e.rev].cap += first;
    }
    return P(h[t], first);
  }
  pair<int, D> calc(int s, int t, int f) {
    int first = 0;
    D res = 0;
    while (f > 0) {
      P w = go(s, t, f);
      if (w.second == 0) break;
      first += w.second;
      f -= w.second;
      res += w.first * w.second;
    }
    return make_pair(first, res);
  }
  tuple<vi, vc<D>, vc<D>> get_slopes(int s, int t, int f) {
    vi fs{0};
    vc<D> vs{0}, sls;
    int first = 0;
    D res = 0;
    while (f > 0) {
      P w = go(s, t, f);
      if (w.second == 0) break;
      sls.push_back(w.first);
      if (w.second >= inf / 2) break;
      first += w.second;
      f -= w.second;
      res += w.first * w.second;
      fs.push_back(first);
      vs.push_back(res);
    }
    return make_tuple(fs, vs, sls);
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  int n, k;
  cin >> n >> k;
  chmin(k, 1 << (n - 1));
  int s = 1 << n;
  vi first = readvi(1 << n);
  vi lf, rt;
  vc<bool> used(s);
  using T = tuple<int, int, int>;
  priority_queue<T> pq;
  auto add = [&](int bit) {
    int val = -1, z = -1;
    for (int i = int(0); i < int(n); i++)
      if (!used[bit ^ 1 << i] && chmax(val, first[bit] + first[bit ^ 1 << i])) {
        z = bit ^ 1 << i;
      }
    if (z != -1) pq.emplace(val, bit, z);
  };
  for (int bit = int(0); bit < int(s); bit++)
    if (popcount(bit) % 2 == 0) add(bit);
  while (int(lf.size()) < 2 * k && int(pq.size())) {
    auto [val, bit, z] = pq.top();
    pq.pop();
    if (!used[z]) {
      lf.push_back(bit);
      rt.push_back(z);
      used[z] = true;
    }
    add(bit);
  }
  vi x = lf, y = rt;
  for (auto v : lf)
    for (int i = int(0); i < int(n); i++) y.push_back(v ^ 1 << i);
  for (auto v : rt)
    for (int i = int(0); i < int(n); i++) x.push_back(v ^ 1 << i);
  mkuni(x);
  mkuni(y);
  mincf<int> mcf(1 + int(x.size()) + int(y.size()) + 1);
  for (int i = int(0); i < int(int(x.size())); i++) mcf.ae(0, 1 + i, 1, 0);
  for (int i = int(0); i < int(int(y.size())); i++)
    mcf.ae(1 + int(x.size()) + i, 1 + int(x.size()) + int(y.size()), 1, 0);
  const int V = 2 * ten(6);
  for (auto v : lf) {
    for (int i = int(0); i < int(n); i++) {
      int z = v ^ 1 << i;
      mcf.ae(1 + lwb(x, v), 1 + int(x.size()) + lwb(y, z), 1,
             V - (first[v] + first[z]));
    }
  }
  for (auto v : rt) {
    for (int i = int(0); i < int(n); i++) {
      int z = v ^ 1 << i;
      mcf.ae(1 + lwb(x, z), 1 + int(x.size()) + lwb(y, v), 1,
             V - (first[v] + first[z]));
    }
  }
  int cost = mcf.calc(0, 1 + int(x.size()) + int(y.size()), k).second;
  print(V * k - cost);
}
