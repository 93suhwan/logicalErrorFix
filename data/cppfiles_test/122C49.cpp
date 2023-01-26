#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void mine(T1 &x, const T2 &y) {
  if (y < x) x = y;
}
template <typename T1, typename T2>
inline void maxe(T1 &x, const T2 &y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &b) {
  os << b.first << ' ' << b.second;
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &b) {
  for (const auto &k : b) os << k << ' ';
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &b) {
  for (auto &k : b) is >> k;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &b) {
  for (const auto &k : b) os << k << ' ';
  return os;
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << "   " << H;
  dbg_out(T...);
}
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
using str = string;
template <typename T>
using V = vector<T>;
using vi = V<int>;
using vl = V<ll>;
using vch = V<char>;
using vpii = V<pii>;
using vvi = V<vi>;
using vvl = V<vl>;
using vvch = V<vch>;
template <typename T>
int Bit(T x, int sh) {
  return (x >> sh) & 1;
}
template <typename T>
int Bits(T x) {
  return __builtin_popcountll(x);
}
template <typename T>
int FirstBit(T x) {
  return __builtin_ctzll(x);
}
template <typename T>
int LastBit(T x) {
  return 63 - __builtin_clzll(x);
}
ll div_up(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll div_down(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct e {
  int a;
  int b;
  int val;
  int to(int v) { return a ^ b ^ v; }
};
const int N = 2e5 + 10;
e ide[N];
bool nice = true;
struct Dsu {
  vector<int> p;
  vector<int> sz;
  vector<int> x;
  Dsu(int n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    sz.resize(n);
    x.resize(n);
    fill(sz.begin(), sz.end(), 1);
    fill(x.begin(), x.end(), 0);
  }
  pii get(int v) {
    if (p[v] == v) return {v, 0};
    auto [a, b] = get(p[v]);
    p[v] = a;
    x[v] ^= b;
    return {p[v], x[v]};
  }
  bool unite(int a, int b, int &v) {
    auto [ra, xa] = get(a);
    auto [rb, xb] = get(b);
    a = ra;
    b = rb;
    if (a == b) {
      if (v == -1) {
        v = xa ^ xb;
      } else {
        nice &= v == (xa ^ xb);
      }
      return false;
    }
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
    if (v == -1) v = 0;
    x[b] = xa ^ xb ^ v;
    return true;
  }
};
void solve() {
  int n, m;
  cin >> n >> m;
  Dsu dsu(n);
  nice = true;
  vi was(n, -1);
  for (int i = 0; i < n - 1; ++i) {
    int a, b, v;
    cin >> a >> b >> v;
    --a, --b;
    if (v != -1) {
      was[i] = v;
      v = Bits(v) & 1;
      dsu.unite(a, b, v);
    }
    ide[i] = {a, b, v};
  }
  for (int i = 0; i < m; ++i) {
    int a, b, p;
    cin >> a >> b >> p;
    --a, --b;
    dsu.unite(a, b, p);
  }
  for (int i = 0; i < n; ++i) {
    if (ide[i].val == -1) {
      dsu.unite(ide[i].a, ide[i].b, ide[i].val);
    }
  }
  if (nice) {
    cout << "YES\n";
    for (int i = 0; i + 1 < n; ++i) {
      if (was[i] != -1) {
        ide[i].val = was[i];
      }
      cout << ide[i].a + 1 << ' ' << ide[i].b + 1 << ' ' << ide[i].val << '\n';
    }
  } else {
    cout << "NO\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test_ = 1;
  cin >> test_;
  while (test_--) solve();
  return 0;
}
