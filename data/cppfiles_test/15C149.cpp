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
void depth(int u, int p, int d, vector<int> &depths) {
  depths[d]++;
  for (auto &v : adj[u]) {
    if (v != p) {
      depth(v, u, d + 1, depths);
    }
  }
}
ll dp[100][100];
ll comb(vector<int> &tot, int i, int rem) {
  if (rem == 0) return 1;
  if (i == int((tot).size()) - 1) {
    if (tot[i] == 0) return 1;
    return tot[i];
  } else {
    if (dp[i][rem] != -1) return dp[i][rem];
    ll t = tot[i] * comb(tot, i + 1, rem - 1);
    t %= (int)(1e9 + 7);
    if (int((tot).size()) - (i + 1) >= rem) {
      t += comb(tot, i + 1, rem);
    }
    t %= (int)(1e9 + 7);
    dp[i][rem] = t;
    return t;
  }
}
ll value(vector<vector<int>> &depths) {
  ll tot = 0;
  for (int z = 0; z < (101); ++z) {
    int sum = 0;
    vector<int> act;
    for (int i = 0; i < (int((depths).size())); ++i) {
      if (depths[i][z] != 0) {
        sum += depths[i][z];
        act.push_back(depths[i][z]);
      }
    }
    if (sum == 0 || int((act).size()) < k) return tot;
    for (int i = 0; i < (int((act).size())); ++i) {
      for (int j = 0; j < (k + 1); ++j) {
        dp[i][j] = -1;
      }
    }
    tot += comb(act, 0, k);
  }
  return tot;
}
ll calc(int u) {
  vector<vector<int>> depths;
  for (auto &v : adj[u]) {
    vector<int> dv(100, 0);
    depth(v, u, 0, dv);
    depths.push_back(dv);
  }
  return value(depths);
}
ll calcedge(int u, int v) {
  vector<vector<int>> depths;
  vector<int> d1(100, 0);
  depth(v, u, 0, d1);
  depths.push_back(d1);
  vector<int> d2(100, 0);
  depth(u, v, 0, d2);
  depths.push_back(d2);
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
  for (int u = 0; u < (n); ++u) {
    for (auto &v : adj[u]) {
      if (v > u) continue;
      ans += calcedge(u, v);
      ans %= (int)(1e9 + 7);
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
