#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma comment(linker, "/STACK:256000000")
using namespace std;
mt19937 rd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1000 * 1000 * 1000 + 322;
const long long LLINF =
    2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL + 57;
constexpr int MOD = 1000 * 1000 * 1000 + 7;
constexpr int FFT_MOD = 998244353;
const int P1E6 = 1336337;
const int P1E3 = 1009;
const long long P1E14 = 100000000000031;
const long long P1E17 = 100000000000000003;
const long double PI = acosl(-1.);
const long double EPS = 1e-9;
template <typename T, typename U>
inline ostream& operator<<(ostream& _out, const pair<T, U>& _p) {
  _out << _p.x << " " << _p.y;
  return _out;
}
template <typename T, typename U>
inline istream& operator>>(istream& _in, pair<T, U>& _p) {
  _in >> _p.x >> _p.y;
  return _in;
}
template <typename T>
inline ostream& operator<<(ostream& _out, const vector<T>& _v) {
  if (_v.empty()) return _out;
  _out << _v.front();
  for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline istream& operator>>(istream& _in, vector<T>& _v) {
  for (auto& _i : _v) _in >> _i;
  return _in;
}
template <typename T>
inline ostream& operator<<(ostream& _out, const set<T>& _s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream& operator<<(ostream& _out, const multiset<T>& _s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream& operator<<(ostream& _out, const unordered_set<T>& _s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T>
inline ostream& operator<<(ostream& _out, const unordered_multiset<T>& _s) {
  if (_s.empty()) return _out;
  _out << *_s.begin();
  for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it;
  return _out;
}
template <typename T, typename U>
inline ostream& operator<<(ostream& _out, const map<T, U>& _m) {
  if (_m.empty()) return _out;
  _out << "{\"" << _m.begin()->x << "\", \"" << _m.begin()->y << "\"}";
  for (auto _it = ++_m.begin(); _it != _m.end(); ++_it)
    _out << ", { \"" << _it->x << "\", \"" << _it->y << "\"}";
  return _out;
}
template <typename T, typename U>
inline ostream& operator<<(ostream& _out, const unordered_map<T, U>& _m) {
  if (_m.empty()) return _out;
  _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
  for (auto _it = ++_m.begin(); _it != _m.end(); ++_it)
    _out << ", (" << _it->x << ": " << _it->y << ')';
  return _out;
}
const char* infile = "";
const char* outfile = "";
inline long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline int pwm(long long xx, long long pow, int MD) {
  if (pow < 0) {
    pow = pow % (long long(MD) - 1) + MD - 1;
  }
  long long mlt = 1;
  while (pow) {
    if (pow & 1) {
      mlt *= xx;
      mlt %= MD;
    }
    xx *= xx;
    pow >>= 1;
    xx %= MD;
  }
  return (int)mlt;
}
inline long long gcdex(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long xx, yy;
  long long gc = gcdex(b, a % b, yy, xx);
  x = xx;
  y = yy - (a / b) * xx;
  return gc;
}
inline int inv(long long r, int _mod) {
  return pwm(r % _mod, long long(_mod) - 2, _mod);
}
const int N = 100 * 1000 + 57;
int ss[N];
int l[N], r[N];
int nxt[N];
int h[N];
int par[N];
long long tr[4 * N];
vector<int> g[N];
int t = 0;
void dfs_sz(int v, int p, int ht = 0) {
  ss[v] = 1;
  h[v] = ht;
  par[v] = p;
  for (auto& u : g[v]) {
    if (u != p) {
      dfs_sz(u, v, ht + 1);
      ss[v] += ss[u];
      if (ss[u] != ss[g[v][0]]) {
        swap(u, g[v][0]);
      }
    }
  }
}
void dfs_hld(int v, int p) {
  l[v] = t++;
  for (auto u : g[v]) {
    if (u == p) {
      continue;
    }
    nxt[u] = (u == g[v][0] ? nxt[v] : u);
    dfs_hld(u, v);
  }
  r[v] = t;
}
int n;
long long get_t(int v, int l, int r, int L, int R) {
  if (l >= R || r <= L) {
    return 0;
  }
  if (L <= l && r <= R) {
    return tr[v];
  }
  return get_t(v << 1, l, (l + r) >> 1, L, R) +
         get_t(v << 1 | 1, (l + r) >> 1, r, L, R);
}
void set_t(int v, int l, int r, int pos, int vl) {
  if (pos >= r || pos < l) {
    return;
  }
  if (r - l == 1) {
    tr[v] = vl;
    return;
  }
  set_t(v << 1, l, (l + r) >> 1, pos, vl);
  set_t(v << 1 | 1, (l + r) >> 1, r, pos, vl);
  tr[v] = tr[v << 1] + tr[v << 1 | 1];
}
long long get_on_path(int u, int v) {
  if (u == v) {
    return 0LL;
  }
  long long sum =
      -get_t(1, 0, n, l[v], l[v] + 1) - get_t(1, 0, n, l[u], l[u] + 1);
  while (nxt[u] != nxt[v]) {
    if (h[nxt[u]] < h[nxt[v]]) {
      swap(u, v);
    }
    sum += 2 * get_t(1, 0, n, l[nxt[u]], l[u] + 1);
    u = par[nxt[u]];
  }
  if (h[u] < h[v]) swap(u, v);
  cout << "path " << u << " - " << v << '\n';
  sum += 2 * get_t(1, 0, n, l[v], l[u] + 1);
  return sum;
}
inline void solve() {
  int q;
  cin >> n >> q;
  vector<int> a(n);
  cin >> a;
  for (auto& aa : a) aa = abs(aa);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  dfs_sz(1, 0);
  dfs_hld(1, 0);
  for (int i = 0; i < n; ++i) {
    set_t(1, 0, n, l[i + 1], a[i]);
  }
  for (int i = 0; i < q; ++i) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      int u, c;
      cin >> u >> c;
      set_t(1, 0, n, l[u], abs(c));
    } else {
      int u, v;
      cin >> u >> v;
      cout << get_on_path(u, v) << '\n';
    }
  }
}
signed main() {
  if (*infile != '\0') {
    assert(freopen(infile, "r", stdin));
  }
  if (*outfile != '\0') {
    assert(freopen(outfile, "w", stdout));
  }
  cout.tie(nullptr);
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << setprecision(20);
  cout << fixed;
  solve();
  return 0;
}
