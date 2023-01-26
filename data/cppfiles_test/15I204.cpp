#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int pct(long long x) { return __builtin_popcountll(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
constexpr int bits(long long x) { return x == 0 ? 0 : 63 - __builtin_clzll(x); }
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
template <class T, class U>
T ipow(T a, U p) {
  T ans = 1;
  assert(p >= 0);
  for (; p; p /= 2, a *= a)
    if (p & 1) ans *= a;
  return ans;
}
template <class T, class U>
T ipow(T a, U p, T m) {
  T ans = 1;
  assert(p >= 0);
  for (; p; p /= 2, a = (a * a) % m)
    if (p & 1) ans = (ans * a) % m;
  return ans;
}
template <class T, class U>
T fstTrue(T lo, T hi, U f) {
  hi++;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo) / 2;
    f(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
template <class T, class U>
T lstTrue(T lo, T hi, U f) {
  lo--;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo + 1) / 2;
    f(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}
template <class T>
T sum(vector<T> &v) {
  if (v.empty()) return 0LL;
  T sum = v[0];
  for (int i = 1; i < (int)v.size(); i++) {
    sum += v[i];
  }
  return sum;
}
template <class F>
F posmod(F a, F b) {
  return ((a % b) + b) % b;
}
template <class F>
struct Point {
  F x, y;
  Point() : x(0), y(0) {}
  Point(const F &cx, const F &cy) : x(cx), y(cy) {}
};
template <class F>
F ceildiv(F a, F d) {
  F res = a / d;
  if (res * d != a) res += 1 & ((a < 0) ^ (d > 0));
  return res;
}
template <class F>
F sq(F a) {
  return a * a;
}
long long inv(long long a, long long b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
int rint(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
double rdouble(double a, double b) {
  return uniform_real_distribution<double>(a, b)(rng);
}
template <class T>
void remdup(vector<T> &v) {
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), end(v));
}
template <class F>
void print(const Point<F> &point) {
  cout << "x: " << point.x << "\ty: " << point.y << '\n';
}
template <class F>
void print(const vector<F> &a) {
  for (int i = 0; i < (int)a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}
template <class F>
void print2(const vector<vector<F>> &a) {
  for (int i = 0; i < (int)a.size(); i++) {
    for (int j = 0; j < (int)a[i].size(); j++) {
      if (j > 0) {
        cout << ' ';
      }
      cout << a[i][j];
    }
    cout << '\n';
  }
}
template <class F>
void fill2(vector<vector<F>> &a, F val) {
  for (int i = 0; i < (int)a.size(); i++) {
    for (int j = 0; j < (int)a[i].size(); j++) {
      a[i][j] = val;
    }
  }
}
template <class F>
void fill3(vector<vector<vector<F>>> &a, F val) {
  for (int i = 0; i < (int)a.size(); i++) {
    for (int j = 0; j < (int)a[i].size(); j++) {
      for (int k = 0; k < (int)a[i][j].size(); k++) {
        a[i][j][k] = val;
      }
    }
  }
}
int gen_base(const int before, const int after) {
  int base = rint(before + 1, after);
  return base % 2 == 0 ? base - 1 : base;
}
struct phash {
  static const int mod = (int)1e9 + 123;
  static vector<int> pow1;
  static vector<ull> pow2;
  static int base;
  vector<int> pref1;
  vector<ull> pref2;
  phash(const string &s)
      : pref1(int((s).size()) + 1u, 0), pref2(int((s).size()) + 1u, 0) {
    assert(base < mod);
    const int n = int((s).size());
    while (int((pow1).size()) <= n) {
      pow1.push_back((int)((ll)pow1.back() * base % mod));
      pow2.push_back(pow2.back() * base);
    }
    for (int i = 0; i < n; i++) {
      assert(base > s[i]);
      pref1[i + 1] = (int)((pref1[i] + (ll)s[i] * pow1[i]) % mod);
      pref2[i + 1] = pref2[i] + s[i] * pow2[i];
    }
  }
  inline std::pair<int, ull> operator()(const int pos, const int len,
                                        int mxPow = -1) const {
    if (mxPow == -1) mxPow = (int)pref1.size() - 1;
    int hash1 = pref1[pos + len] - pref1[pos];
    ull hash2 = pref2[pos + len] - pref2[pos];
    if (hash1 < 0) hash1 += mod;
    if (mxPow != 0) {
      hash1 = (int)((ll)hash1 * pow1[mxPow - (pos + len - 1)] % mod);
      hash2 *= pow2[mxPow - (pos + len - 1)];
    }
    return {hash1, hash2};
  }
};
vector<int> phash::pow1{1};
vector<ull> phash::pow2{1};
int phash::base = gen_base(256, phash::mod);
vector<vector<int>> adj;
int n, k;
vector<int> visited(100, false);
vector<ll> facts(101, 0);
ll f(int n) {
  if (facts[n] != 0) {
    return facts[n];
  }
  if (n == 0) return 1;
  facts[n] = (n * f(n - 1)) % (int)(1e9 + 7);
  return facts[n];
}
ll nCrs[101][101];
ll nCr(int n, int r) {
  if (nCrs[n][r] != 0) {
    return nCrs[n][r];
  }
  ll fn = f(n);
  ll fk = f(r);
  ll fo = f(n - r);
  ll fkinv = inv(fk, (int)(1e9 + 7));
  ll foinv = inv(fo, (int)(1e9 + 7));
  nCrs[n][r] = (((fn * fkinv) % (int)(1e9 + 7)) * foinv) % (int)(1e9 + 7);
  return nCrs[n][r];
}
int depth(int u) {
  assert(!visited[u]);
  visited[u] = true;
  int maxdepth = 1;
  for (auto &v : adj[u]) {
    if (!visited[v]) {
      ckmax(maxdepth, 1 + depth(v));
    }
  }
  return maxdepth;
}
ll value(vector<int> &depths) {
  ll tot = 0;
  int last = 0;
  for (int i = 0; i < (int((depths).size())); ++i) {
    int delta = depths[i] - last;
    int size = int((depths).size()) - i;
    if (size >= k) {
      tot += delta * nCr(size, k);
      tot %= (int)(1e9 + 7);
    }
    last = depths[i];
  }
  return tot;
}
ll calc(int u) {
  vector<int> depths;
  for (auto &v : adj[u]) {
    visited.assign(100, false);
    visited[u] = true;
    depths.emplace_back(depth(v));
  }
  sort((depths).begin(), (depths).end());
  return value(depths);
}
ll calcedge(int u, int v) {
  vector<int> depths;
  visited.assign(100, false);
  visited[u] = true;
  depths.emplace_back(depth(v));
  visited.assign(100, false);
  visited[v] = true;
  depths.emplace_back(depth(u));
  sort((depths).begin(), (depths).end());
  return value(depths);
}
void solve() {
  cin >> n >> k;
  adj.assign(n, vector<int>());
  for (int i = 0; i < (n - 1); ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  ll ans = 0;
  for (int i = 0; i < (n); ++i) {
    ans += calc(i);
    ans %= (int)(1e9 + 7);
  }
  if (k == 2) {
    for (int u = 0; u < (n); ++u) {
      for (auto &v : adj[u]) {
        if (v > u) continue;
        ans += calcedge(u, v);
        ans %= (int)(1e9 + 7);
      }
    }
  }
  cout << ans << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
