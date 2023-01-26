#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
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
void print(const F a[], int n) {
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << ' ';
    cout << a[i];
  }
  cout << '\n';
}
template <class F>
void print(const vector<F> &a) {
  for (int i = 0; i < (int)a.size(); i++) {
    if (i > 0) cout << ' ';
    cout << a[i];
  }
  cout << '\n';
}
template <class F>
void print2(const vector<vector<F>> &a) {
  for (int i = 0; i < (int)a.size(); i++) {
    for (int j = 0; j < (int)a[i].size(); j++) {
      if (j > 0) cout << ' ';
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
struct mi {
  ll v;
  explicit operator ll() const { return v; }
  mi() { v = 0; }
  mi(ll _v) {
    v = (-(int)(1e9 + 7) < _v && _v < (int)(1e9 + 7)) ? _v
                                                      : _v % (int)(1e9 + 7);
    if (v < 0) v += (int)(1e9 + 7);
  }
  friend bool operator==(const mi &a, const mi &b) { return a.v == b.v; }
  friend bool operator!=(const mi &a, const mi &b) { return !(a == b); }
  friend bool operator<(const mi &a, const mi &b) { return a.v < b.v; }
  mi &operator+=(const mi &m) {
    if ((v += m.v) >= (int)(1e9 + 7)) v -= (int)(1e9 + 7);
    return *this;
  }
  mi &operator-=(const mi &m) {
    if ((v -= m.v) < 0) v += (int)(1e9 + 7);
    return *this;
  }
  mi &operator*=(const mi &m) {
    v = v * m.v % (int)(1e9 + 7);
    return *this;
  }
  mi &operator/=(const mi &m) { return (*this) *= inv(m); }
  friend mi pow(mi a, ll p) {
    mi ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  friend mi inv(const mi &a) {
    assert(a.v != 0);
    return pow(a, (int)(1e9 + 7) - 2);
  }
  mi operator-() const { return mi(-v); }
  mi &operator++() { return *this += 1; }
  mi &operator--() { return *this -= 1; }
  mi operator++(int) {
    mi temp;
    temp.v = v++;
    return temp;
  }
  mi operator--(int) {
    mi temp;
    temp.v = v--;
    return temp;
  }
  friend mi operator+(mi a, const mi &b) { return a += b; }
  friend mi operator-(mi a, const mi &b) { return a -= b; }
  friend mi operator*(mi a, const mi &b) { return a *= b; }
  friend mi operator/(mi a, const mi &b) { return a /= b; }
  friend ostream &operator<<(ostream &os, const mi &m) {
    os << m.v;
    return os;
  }
  friend istream &operator>>(istream &is, mi &m) {
    ll x;
    is >> x;
    m.v = x;
    return is;
  }
};
const int MX = 1e6;
bool facinit = false;
mi facs[MX];
mi facInvs[MX];
mi ncr(mi _a, mi _b) {
  ll a = (ll)_a;
  ll b = (ll)_b;
  assert(facinit && a < MX && b < MX);
  assert(a >= 0 && b >= 0 && b <= a);
  if (b > a || a < 0 || b < 0) return 0;
  mi cur = facs[a];
  cur = cur * facInvs[b];
  cur = cur * facInvs[a - b];
  return cur;
}
void initFacs() {
  facs[0] = 1;
  for (int i = (1); i < (MX); ++i) facs[i] = i * facs[i - 1];
  facInvs[MX - 1] = inv(facs[MX - 1]);
  for (int i = (MX - 1) - 1; i >= 0; i--) facInvs[i] = facInvs[i + 1] * (i + 1);
  facinit = true;
}
void solve() {
  int n;
  cin >> n;
  int d;
  cin >> d;
  vector<int> a = vector<int>((n));
  for (int i = 0; i < (n); ++i) cin >> a[i];
  ;
  vector<bool> visited(n, false);
  int longest = 0;
  for (int i = 0; i < (n); ++i) {
    if (!visited[i]) {
      int start = i;
      int j = i;
      while (a[j] != 0) {
        j = (n + j - d) % n;
        if (j == i) {
          {
            cout << "-1\n";
            return;
          };
        }
      }
      int zerostart = j;
      int c = 0;
      j = (n + j - d) % n;
      while (j != zerostart) {
        if (a[j] == 1) c++;
        j = (n + j - d) % n;
        if (a[j] == 0) {
          ckmax(longest, c);
        }
      }
    }
  }
  cout << longest << '\n';
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
