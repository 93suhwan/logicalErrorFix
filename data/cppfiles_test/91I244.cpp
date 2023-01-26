#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vc = vector<T>;
template <typename T>
using vv = vc<vc<T>>;
template <typename T>
using PQ = priority_queue<T, vc<T>, greater<T>>;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int, int>;
using T3 = tuple<int, int, int>;
using vi = vc<int>;
using vvi = vv<int>;
using vl = vc<ll>;
using vp = vc<P>;
using vt = vc<T3>;
int getInt() {
  int x;
  scanf("%d", &x);
  return x;
}
vi pm(int n, int s = 0) {
  vi a(n);
  iota(a.begin(), a.end(), s);
  return a;
}
template <typename T>
istream& operator>>(istream& i, vc<T>& v) {
  for (int j = 0; j < ((int)(v).size()); ++j) i >> v[j];
  return i;
}
template <typename T>
string join(const T& v, const string& d = "") {
  stringstream s;
  for (int i = 0; i < ((int)(v).size()); ++i) (i ? s << d : s) << v[i];
  return s.str();
}
template <typename T>
ostream& operator<<(ostream& o, const vc<T>& v) {
  if ((int)(v).size()) o << join(v, " ");
  return o;
}
template <typename T1, typename T2>
istream& operator>>(istream& i, pair<T1, T2>& v) {
  return i >> v.first >> v.second;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& o, const pair<T1, T2>& v) {
  return o << v.first << "," << v.second;
}
vc<string> split(const string& s, char d = ' ') {
  vc<string> r(1);
  for (char c : s)
    if (c == d)
      r.push_back("");
    else
      r.back() += c;
  return r;
}
string operator*(const string& s, int t) { return join(vc<string>(t, s)); }
template <typename T1, typename T2>
bool mins(T1& x, const T2& y) {
  if (x > y) {
    x = y;
    return true;
  } else
    return false;
}
template <typename T1, typename T2>
bool maxs(T1& x, const T2& y) {
  if (x < y) {
    x = y;
    return true;
  } else
    return false;
}
template <typename Tx, typename Ty>
Tx dup(Tx x, Ty y) {
  return (x + y - 1) / y;
}
template <typename T>
ll suma(const vc<T>& a) {
  ll res(0);
  for (auto&& x : a) res += x;
  return res;
}
template <typename T>
void uni(T& a) {
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MX = 200005;
using Q = pair<int, P>;
using vq = vector<Q>;
struct Solver {
  void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    map<P, int> es;
    set<Q> s;
    vc<set<Q>> ss(n);
    auto top3 = [&](int v, const Q& d) {
      int cnt = 0;
      for (auto&& nd : ss[v]) {
        if (d == nd) return true;
        ++cnt;
        if (cnt >= 3) break;
      }
      return false;
    };
    auto adds = [&](int v, bool four = false) {
      int cnt = 0;
      for (auto&& d : ss[v]) {
        ++cnt;
        if (four && cnt == 4) {
          s.erase(d);
        } else {
          int u = d.second.first ^ d.second.second ^ v;
          if (top3(u, d)) s.insert(d);
        }
        if (cnt >= (four ? 4 : 3)) break;
      }
    };
    auto dels = [&](int v) {
      int cnt = 0;
      for (auto&& d : ss[v]) {
        s.erase(d);
        ++cnt;
        if (cnt >= 3) break;
      }
    };
    auto ad = [&](int v, const Q& d) {
      dels(v);
      ss[v].insert(d);
      adds(v, true);
    };
    auto dl = [&](int v, const Q& d) {
      dels(v);
      ss[v].erase(d);
      adds(v);
    };
    auto add = [&](int a, int b, int c) {
      --a;
      --b;
      if (a > b) swap(a, b);
      es[P(a, b)] = c;
      Q d(c, P(a, b));
      ad(a, d);
      ad(b, d);
    };
    auto del = [&](int a, int b) {
      --a;
      --b;
      if (a > b) swap(a, b);
      auto it = es.find(P(a, b));
      int c = it->second;
      es.erase(it);
      Q d(c, P(a, b));
      s.erase(d);
      dl(a, d);
      dl(b, d);
    };
    for (int i = 0; i < (m); ++i) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      add(a, b, c);
    }
    auto answer = [&] {
      int cnt = 0;
      vq ds;
      for (auto&& d : s) {
        ds.push_back(d);
        ++cnt;
        if (cnt == 6) break;
      }
      int ans = INF * 2;
      for (int i = 0; i < ((int)(ds).size()); ++i)
        for (int j = 0; j < (i); ++j) {
          auto [a, b] = ds[i].second;
          auto [x, y] = ds[j].second;
          if (a == x || a == y || b == x || b == y) continue;
          mins(ans, ds[i].first + ds[j].first);
        }
      {
        auto [a, b] = ds[0].second;
        auto [x, y] = ds[1].second;
        if (a == x || a == y || b == x || b == y) {
          if (a == x)
            a = y;
          else if (a == y)
            a = x;
          else if (b == x)
            b = y;
          else
            b = x;
          if (a > b) swap(a, b);
          for (int i = 2; i < (4); ++i) {
            auto [u, v] = ds[i].second;
            if (a == u && b == v) continue;
            mins(ans, ds[0].first + ds[1].first + ds[i].first);
            break;
          }
        }
      }
      printf("%d\n", ans);
    };
    answer();
    int q;
    scanf("%d", &q);
    for (int qi = 0; qi < (q); ++qi) {
      int type, a, b;
      scanf("%d%d%d", &type, &a, &b);
      if (type == 0) {
        del(a, b);
      } else {
        int c;
        scanf("%d", &c);
        add(a, b, c);
      }
      answer();
    }
  }
};
int main() {
  int ts = 1;
  for (int ti = 1; ti <= (ts); ++ti) {
    Solver solver;
    solver.solve();
  }
  return 0;
}
