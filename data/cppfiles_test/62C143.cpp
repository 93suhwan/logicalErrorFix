#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
template <typename T>
using V = vector<T>;
template <typename T>
using VV = vector<vector<T>>;
template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using PQR = priority_queue<T, vector<T>, greater<T>>;
constexpr ll mod = 1000000007;
constexpr ll INF = 1000000099;
constexpr ll LINF = (ll)(1e18 + 99);
constexpr ll dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
template <typename T, typename U>
inline bool chmin(T &t, const U &u) {
  if (t > u) {
    t = u;
    return 1;
  }
  return 0;
}
template <typename T, typename U>
inline bool chmax(T &t, const U &u) {
  if (t < u) {
    t = u;
    return 1;
  }
  return 0;
}
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
inline void Yes() { cout << "Yes" << '\n'; }
inline void No() { cout << "No" << '\n'; }
inline void YES() { cout << "YES" << '\n'; }
inline void NO() { cout << "NO" << '\n'; }
template <typename T, typename Y>
inline T mpow(T a, Y n) {
  T res = 1;
  for (; n; n >>= 1) {
    if (n & 1) res = res * a;
    a = a * a;
  }
  return res;
}
template <typename T>
vector<T> finddivisor(T x) {
  vector<T> divisor;
  for (T i = 1; (i * i) <= x; i++) {
    if (x % i == 0) {
      divisor.push_back(i);
      if (i * i != x) {
        divisor.push_back(x / i);
      }
    }
  }
  sort(divisor.begin(), divisor.end());
  return divisor;
}
template <typename T>
V<T> prefix_sum(const V<T> &v) {
  int n = v.size();
  V<T> ret(n + 1);
  for (ll i = 0; i < (ll)(n); ++i) ret[i + 1] = ret[i] + v[i];
  return ret;
}
template <typename T>
void get_unique(V<T> &v) {
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), v.end());
  return;
}
template <typename T>
T rand(T l, T r) {
  static random_device rd;
  static mt19937 g(rd());
  return uniform_int_distribution<T>(l, r)(g);
}
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &&x : vec) is >> x;
  return is;
}
template <typename T, typename Y>
ostream &operator<<(ostream &os, const pair<T, Y> &p) {
  return os << "{" << p.first << "," << p.second << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const V<T> &v) {
  os << "{";
  for (auto e : v) os << e << ",";
  return os << "}";
}
template <typename... Args>
void debug(Args &...args) {
  return;
}
template <typename T>
struct RangeSet {
  set<pair<T, T>> st;
  RangeSet() {
    st.emplace(LINF, LINF);
    st.emplace(-LINF, -LINF);
  }
  bool covered(T l, T r) {
    assert(l <= r);
    auto ite = prev(st.lower_bound({l + 1, l + 1}));
    return ite->first <= l and r <= ite->second;
  }
  bool covered(T x) { return covered(x, x); }
  pair<T, T> covered_by(T l, T r) {
    if (l > r) return make_pair(-LINF, -LINF);
    auto ite = prev(st.lower_bound({l + 1, l + 1}));
    if (ite->first <= l and r <= ite->second) return *ite;
    return make_pair(-LINF, -LINF);
  }
  pair<T, T> covered_by(T x) { return covered_by(x, x); }
  T insert(T l, T r) {
    if (l > r) return 0;
    auto ite = prev(st.lower_bound({l + 1, l + 1}));
    if (ite->first <= l and r <= ite->second) return T(0);
    T sum_erased = T(0);
    if (ite->first <= l and l <= ite->second + 1) {
      l = ite->first;
      sum_erased += ite->second - ite->first + 1;
      ite = st.erase(ite);
    } else
      ite = next(ite);
    while (r > ite->second) {
      sum_erased += ite->second - ite->first + 1;
      ite = st.erase(ite);
    }
    if (ite->first - 1 <= r and r <= ite->second) {
      sum_erased += ite->second - ite->first + 1;
      r = ite->second;
      st.erase(ite);
    }
    st.emplace(l, r);
    return r - l + 1 - sum_erased;
  }
  T insert(T x) { return insert(x, x); }
  T erase(T l, T r) {
    if (l > r) return 0;
    auto ite = prev(st.lower_bound({l + 1, l + 1}));
    if (ite->first <= l and r <= ite->second) {
      if (ite->first < l) st.emplace(ite->first, l - 1);
      if (r < ite->second) st.emplace(r + 1, ite->second);
      st.erase(ite);
      return r - l + 1;
    }
    T ret = T(0);
    if (ite->first <= l and l <= ite->second) {
      ret += ite->second - l + 1;
      if (ite->first < l) st.emplace(ite->first, l - 1);
      ite = st.erase(ite);
    } else
      ite = next(ite);
    while (ite->second <= r) {
      ret += ite->second - ite->first + 1;
      ite = st.erase(ite);
    }
    if (ite->first <= r and r <= ite->second) {
      ret += r - ite->first + 1;
      if (r < ite->second) st.emplace(r + 1, ite->second);
      st.erase(ite);
    }
    return ret;
  }
  T erase(T x) { return erase(x, x); }
  int size() { return (int)st.size() - 2; }
  int mex(T x = 0) {
    auto ite = prev(st.lower_bound({x + 1, x + 1}));
    if (ite->first <= x and x <= ite->second)
      return ite->second + 1;
    else
      return x;
  }
  void output() {
    cout << "RangeSet : ";
    for (auto &p : st) {
      if (p.first == -LINF or p.second == LINF) continue;
      cout << "[" << p.first << ", " << p.second << "] ";
    }
    cout << "\n";
  }
};
ll com2(ll x) { return x * (x - 1) / 2; }
signed main() {
  cin.tie(0);
  cerr.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, m, q;
  cin >> n >> m >> q;
  ll ans = n * m;
  V<RangeSet<ll>> rs(n + m);
  VV<pair<ll, ll>> v(n + m, V<pair<ll, ll>>(0));
  for (ll i = 0; i < (ll)(n); ++i)
    for (ll j = 0; j < (ll)(m); ++j) {
      ll dis = abs(i) + abs(m - 1 - j);
      v[dis].emplace_back(i, j);
      if (dis) {
        v[dis - 1].emplace_back(i, j);
      }
    }
  for (ll i = 0; i < (ll)(n + m); ++i) sort((v[i]).begin(), (v[i]).end());
  for (ll i = 0; i < (ll)(n + m); ++i) {
    rs[i].insert(0, (ll)(v[i]).size() - 1);
    ans += com2((ll)(v[i]).size());
  }
  while (q--) {
    ll x, y;
    cin >> x >> y;
    --x;
    --y;
    ll dis = abs(x) + abs(m - 1 - y);
    ll id = distance(
        (v[dis]).begin(),
        lower_bound((v[dis]).begin(), (v[dis]).end(), (make_pair(x, y))));
    if (rs[dis].covered(id)) {
      auto seg = rs[dis].covered_by(id);
      rs[dis].erase(id);
      rs[dis].insert(seg.first, id - 1);
      rs[dis].insert(id + 1, seg.second);
      ans -= com2(seg.second - seg.first + 1);
      ans += com2(id - seg.first);
      ans += com2(seg.second - id);
      --ans;
    } else {
      rs[dis].insert(id);
      auto seg = rs[dis].covered_by(id);
      ans += com2(seg.second - seg.first + 1);
      ans -= com2(id - seg.first);
      ans -= com2(seg.second - id);
      ++ans;
    }
    if (dis) {
      --dis;
      id = distance(
          (v[dis]).begin(),
          lower_bound((v[dis]).begin(), (v[dis]).end(), (make_pair(x, y))));
      if (rs[dis].covered(id)) {
        auto seg = rs[dis].covered_by(id);
        rs[dis].erase(id);
        rs[dis].insert(seg.first, id - 1);
        rs[dis].insert(id + 1, seg.second);
        ans -= com2(seg.second - seg.first + 1);
        ans += com2(id - seg.first);
        ans += com2(seg.second - id);
      } else {
        rs[dis].insert(id);
        auto seg = rs[dis].covered_by(id);
        ans += com2(seg.second - seg.first + 1);
        ans -= com2(id - seg.first);
        ans -= com2(seg.second - id);
      }
    }
    cout << ans << '\n';
  }
}
