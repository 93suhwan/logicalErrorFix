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
struct unionfind {
  vi p, s;
  int c;
  unionfind(int n) : p(n, -1), s(n, 1), c(n) {}
  int find(int first) {
    return p[first] == -1 ? first : (p[first] = find(p[first]));
  }
  bool unite(int first, int second) {
    first = find(first);
    second = find(second);
    if (first == second) return false;
    p[second] = first;
    s[first] += s[second];
    c--;
    return true;
  }
  bool same(int first, int second) { return find(first) == find(second); }
  int sz(int first) { return s[find(first)]; }
};
struct SA {
  int n;
  vi sa, as, lcp;
  SA() {}
  template <class t>
  SA(t s) : n(s.size()), sa(n), as(n), lcp(n - 1) {
    for (int i = int(0); i < int(n); i++) sa[i] = n - 1 - i;
    stable_sort(sa.begin(), sa.end(),
                [&](int first, int second) { return s[first] < s[second]; });
    vi c(n);
    for (int i = int(0); i < int(n); i++) c[i] = s[i];
    for (int w = 1; w < n; w *= 2) {
      vi d(c);
      for (int i = int(0); i < int(n); i++) {
        if (i && sa[i - 1] + w < n && d[sa[i - 1]] == d[sa[i]] &&
            d[sa[i - 1] + w / 2] == d[sa[i] + w / 2])
          c[sa[i]] = c[sa[i - 1]];
        else
          c[sa[i]] = i;
      }
      vi e(sa), f(n);
      iota(f.begin(), f.end(), 0);
      for (int i = int(0); i < int(n); i++) {
        int j = e[i] - w;
        if (j >= 0) sa[f[c[j]]++] = j;
      }
    }
    for (int i = int(0); i < int(n); i++) as[sa[i]] = i;
    int w = 0;
    for (auto i : as) {
      if (w) w--;
      if (i < n - 1) {
        while (max(sa[i], sa[i + 1]) + w < n &&
               s[sa[i] + w] == s[sa[i + 1] + w])
          w++;
        lcp[i] = w;
      }
    }
  }
};
struct ste {
  int to, l, r;
  operator int() const { return to; }
};
ostream& operator<<(ostream& os, const ste& first) {
  return os << "ste{" << first.to << ",[" << first.l << "," << first.r << "]}";
}
pair<vvc<ste>, int> stree(const SA& sa) {
  int n = sa.n, s = n * 2 - 1;
  vi len(s);
  for (int i = int(0); i < int(n); i++) len[i] = n - sa.sa[i];
  for (int i = int(0); i < int(n - 1); i++) len[i + n] = sa.lcp[i];
  vi idx(n - 1);
  iota(idx.begin(), idx.end(), n);
  stable_sort(idx.begin(), idx.end(),
              [&](int first, int second) { return len[first] > len[second]; });
  unionfind uf(s);
  vi par(s, -1), c(s, -1);
  for (int i = int(0); i < int(n); i++) c[i] = sa.sa[i];
  for (auto i : idx) {
    int first = uf.find(i - n), second = uf.find(i - n + 1);
    uf.unite(i, first);
    uf.unite(i, second);
    par[first] = i;
    par[second] = i;
    c[i] = c[first];
  }
  par[n == 1 ? 0 : idx.back()] = s++;
  len.push_back(0);
  uf = unionfind(s);
  for (int i = int(0); i < int(s - 1); i++)
    if (len[i] == len[par[i]]) uf.unite(i, par[i]);
  vi vs;
  for (int i = int(0); i < int(s); i++)
    if (uf.find(i) == i) vs.push_back(i);
  auto z = [&](int i) {
    return lower_bound(vs.begin(), vs.end(), uf.find(i)) - vs.begin();
  };
  vvc<ste> res(vs.size());
  for (int ii = int(0); ii < int(s - 1); ii++) {
    int i = ii / 2 + ii % 2 * n;
    int first = z(i), second = z(par[i]);
    if (first == second) continue;
    res[second].push_back(ste{first, c[i] + len[par[i]], c[i] + len[i]});
  }
  return make_pair(res, z(s - 1));
}
template <class t>
struct BIT {
  vc<t> buf;
  int s;
  BIT(int n = 0) { init(n); }
  void init(int n) {
    buf.clear();
    buf.resize(s = n, 0);
  }
  void init(const vc<t>& first) {
    s = int(first.size());
    buf.resize(s);
    for (int i = int(0); i < int(s); i++) buf[i] = first[i];
    for (int i = int(0); i < int(s); i++) {
      int j = i + ((i + 1) & (-i - 1));
      if (j < s) buf[j] += buf[i];
    }
  }
  void add(int i, t v) {
    for (; i < s; i += (i + 1) & (-i - 1)) buf[i] += v;
  }
  t get(int i) {
    t res = 0;
    for (; i >= 0; i -= (i + 1) & (-i - 1)) res += buf[i];
    return res;
  }
  t sum(int second, int e) { return get(e - 1) - get(second - 1); }
  void add_range(int second, int e, t v) {
    add(second, v);
    add(e, -v);
  }
  int kth(int k) {
    int res = 0;
    for (int i = topbit(s); i >= 0; i--) {
      int w = res + (1 << i);
      if (w <= s && buf[w - 1] <= k) {
        k -= buf[w - 1];
        res = w;
      }
    }
    return res;
  }
  int kth_helper(int k, int i) { return kth(k + get(i - 1)); }
};
template <class t>
struct Point1D {
  BIT<t> bit;
  vi pos;
  void addp(int p) { pos.push_back(p); }
  void init() {
    mkuni(pos);
    bit.init(pos.size());
  }
  int idx(int p) { return lwb(pos, p); }
  void addv(int p, t v) { bit.add(idx(p), v); }
  t sum(int second, int e) { return bit.sum(idx(second), idx(e)); }
  t getpref(int p) { return bit.get(idx(p) - 1); }
};
template <class t>
struct Point2D {
  vc<Point1D<t>> buf;
  vi pos, xs, ys;
  void addp(int x, int y) {
    xs.push_back(x);
    ys.push_back(y);
  }
  int idx(int p) { return lwb(pos, p); }
  void init() {
    pos = xs;
    mkuni(pos);
    buf.resize(pos.size());
    for (int i = int(0); i < int(xs.size()); i++)
      for (int j = idx(xs[i]); j < int(buf.size()); j += (j + 1) & (-j - 1))
        buf[j].addp(ys[i]);
    for (auto& second : buf) second.init();
  }
  void addv(int x, int y, t v) {
    for (int j = idx(x); j < int(buf.size()); j += (j + 1) & (-j - 1))
      buf[j].addv(y, v);
  }
  t rect(int x1, int x2, int y1, int y2) {
    t res = 0;
    for (int j = idx(x1) - 1; j >= 0; j -= (j + 1) & (-j - 1))
      res -= buf[j].sum(y1, y2);
    for (int j = idx(x2) - 1; j >= 0; j -= (j + 1) & (-j - 1))
      res += buf[j].sum(y1, y2);
    return res;
  }
  t getpref(int x, int y) {
    t res = 0;
    for (int j = idx(x) - 1; j >= 0; j -= (j + 1) & (-j - 1))
      res += buf[j].getpref(y);
    return res;
  }
};
template <class E, class N>
struct cdecomp {
  const vvc<E>& g;
  int n;
  vi rem;
  int ts(int v, int p) {
    int res = 1;
    for (auto e : g[v])
      if (e != p && !rem[e]) res += ts(e, v);
    return res;
  }
  int fc(int v, int p, int s) {
    int ret = 1, mx = 0;
    for (auto e : g[v])
      if (e != p && !rem[e]) {
        int f = fc(e, v, s);
        if (f <= 0)
          return f;
        else {
          ret += f;
          mx = max(mx, f);
        }
      }
    mx = max(mx, s - ret);
    if (mx * 2 <= s)
      return -v;
    else
      return ret;
  }
  cdecomp(const vvc<E>& gg) : g(gg), n(g.size()), rem(n) {}
  vc<N> buf0;
  vc<N> buf1;
  vi tp;
  vvc<tuple<int, int, int>> bucket;
  void dfs1(int v, int p, int i, N cur0, N cur1) {
    buf0[v] = cur0;
    buf1[v] = cur1;
    tp[v] = i;
    for (auto e : g[v])
      if (e != p && !rem[e]) {
        dfs1(e, v, i == -1 ? e : i, cur0.extend(e), cur1.extend(e));
      }
  }
  template <class F>
  void con(int r, const vc<tuple<int, int, int>>& qs, F f) {
    r = -fc(r, -1, ts(r, -1));
    N ini0, ini1;
    ini0.init(0);
    ini1.init(1);
    dfs1(r, -1, -1, ini0, ini1);
    for (const auto& w : qs) {
      int first, second, i;
      tie(first, second, i) = w;
      if (tp[first] != tp[second]) {
        f(i, buf0[first], buf1[second], r);
      } else {
        bucket[tp[first]].push_back(w);
      }
    }
    rem[r] = 1;
    for (auto e : g[r])
      if (!rem[e]) {
        vc<tuple<int, int, int>> tmp;
        tmp.swap(bucket[e]);
        con(e, tmp, f);
      }
  }
  template <class F>
  void slv(const vc<pi>& qs, F f) {
    fill(rem.begin(), rem.end(), 0);
    buf0.resize(n);
    buf1.resize(n);
    tp.resize(n);
    bucket.resize(n);
    vc<tuple<int, int, int>> tmp(int(qs.size()));
    for (int i = int(0); i < int(int(qs.size())); i++)
      tmp[i] = make_tuple(qs[i].first, qs[i].second, i);
    con(0, tmp, f);
  }
};
struct E {
  int to;
  char c;
  operator int() const { return to; }
};
SA sa[2];
vvc<ste> st[2];
int stroot[2];
vi in[2], out[2];
int ord[2];
void dfs(int k, int v) {
  in[k][v] = ord[k]++;
  for (auto e : st[k][v]) dfs(k, e.to);
  out[k][v] = ord[k];
}
string z[2];
struct N {
  int k, v, dig, len;
  void init(int kk) {
    k = kk;
    v = stroot[k];
    dig = -1;
    len = -1;
  }
  N extend(const E& e) const {
    if (v == -1) return N{-1, -1, -1, -1};
    N res = *this;
    if (res.dig == -1) {
      for (int i = int(0); i < int(int(st[k][v].size())); i++) {
        if (z[k][st[k][v][i].l] == e.c) {
          res.dig = i;
          break;
        }
      }
      if (res.dig == -1) {
        return N{-1, -1, -1, -1};
      }
      res.len = 0;
    }
    const auto& f = st[k][v][res.dig];
    if (z[k][f.l + res.len] != e.c) return N{-1, -1, -1, -1};
    res.len++;
    if (f.r - f.l == res.len) {
      return N{k, f.to, -1, -1};
    } else {
      return res;
    }
  }
  pi getlr() {
    if (v == -1) return pi(-1, -1);
    int w = v;
    if (len > 0) {
      w = st[k][v][dig].to;
    }
    return pi(in[k][w], out[k][w]);
  }
};
void slv() {
  int n, m, q;
  cin >> n >> m >> q;
  vvc<E> tr(n);
  for (int i = int(0); i < int(n - 1); i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    string s;
    cin >> s;
    tr[u].push_back(E{v, s[0]});
    tr[v].push_back(E{u, s[0]});
  }
  z[0] = "$";
  vi off(m), len(m);
  for (int i = int(0); i < int(m); i++) {
    off[i] = int(z[0].size());
    string s;
    cin >> s;
    len[i] = int(s.size());
    z[0] += s;
    z[0] += '$';
  }
  z[1] = z[0];
  reverse(z[1].begin(), z[1].end());
  for (int k = int(0); k < int(2); k++) {
    tie(st[k], stroot[k]) = stree(sa[k] = SA(z[k]));
    in[k].resize(int(st[k].size()));
    out[k].resize(int(st[k].size()));
    dfs(k, stroot[k]);
    void(0);
    void(0);
    void(0);
  }
  using P = pair<pi, pi>;
  vc<pi> uv(q);
  vvc<int> baka(m + 1);
  vc<P> ls(q);
  for (int i = int(0); i < int(q); i++) {
    int u, v, l, r;
    cin >> u >> v >> l >> r;
    u--, v--, l--;
    uv[i] = pi(v, u);
    baka[l].push_back(i * 2);
    baka[r].push_back(i * 2 + 1);
  }
  auto unko = [&](int idx, N lf, N rt, int) {
    ls[idx] = P(lf.getlr(), rt.getlr());
  };
  cdecomp<E, N> cd(tr);
  cd.slv(uv, unko);
  void(0);
  Point2D<int> p2d;
  for (int i = int(0); i < int(m); i++) {
    for (int j = int(off[i]); j < int(off[i] + len[i] + 1); j++) {
      int x = in[0][sa[0].as[j]];
      int y = in[1][sa[1].as[int(z[1].size()) - j]];
      void(0);
      p2d.addp(x, y);
    }
  }
  p2d.init();
  vi ans(q);
  for (int i = int(0); i < int(m + 1); i++) {
    for (auto w : baka[i]) {
      auto [xl, xr] = ls[w / 2].first;
      auto [yl, yr] = ls[w / 2].second;
      ans[w / 2] += p2d.rect(xl, xr, yl, yr) * (w % 2 == 0 ? -1 : 1);
    }
    if (i < m) {
      for (int j = int(off[i]); j < int(off[i] + len[i] + 1); j++) {
        int x = in[0][sa[0].as[j]];
        int y = in[1][sa[1].as[int(z[1].size()) - j]];
        p2d.addv(x, y, 1);
      }
    }
  }
  for (int i = int(0); i < int(q); i++) print(ans[i]);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  slv();
}
