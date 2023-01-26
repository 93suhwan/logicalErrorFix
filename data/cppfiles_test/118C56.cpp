#include <bits/stdc++.h>
const int mod = 998244353;
const int gmod = 3;
const int inf = 1039074182;
const double eps = 1e-9;
const double pi = 3.141592653589793238462643383279;
const long long llinf = 2LL * inf * inf;
template <typename T1, typename T2>
inline void chmin(T1 &x, T2 b) {
  if (b < x) x = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &x, T2 b) {
  if (b > x) x = b;
}
inline void chadd(int &x, int b) {
  x += b - mod;
  x += (x >> 31 & mod);
}
template <typename T1, typename T2>
inline void chadd(T1 &x, T2 b) {
  x += b;
  if (x >= mod) x -= mod;
}
template <typename T1, typename T2>
inline void chmul(T1 &x, T2 b) {
  x = 1LL * x * b % mod;
}
template <typename T1, typename T2>
inline void chmod(T1 &x, T2 b) {
  x %= b, x += b;
  if (x >= b) x -= b;
}
template <typename T>
inline T mabs(T x) {
  return (x < 0 ? -x : x);
}
using namespace std;
using namespace std;
template <typename T>
ostream &operator<<(ostream &cout, const vector<T> &vec) {
  cout << "{";
  for (int i = 0; i < (int)vec.size(); i++) {
    cout << vec[i];
    if (i != (int)vec.size() - 1) cout << ',';
  }
  cout << "}";
  return cout;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &cout, pair<T1, T2> p) {
  cout << "(" << p.first << ',' << p.second << ")";
  return cout;
}
template <typename T, typename T2>
ostream &operator<<(ostream &cout, set<T, T2> s) {
  vector<T> t;
  for (auto x : s) t.push_back(x);
  cout << t;
  return cout;
}
template <typename T, typename T2>
ostream &operator<<(ostream &cout, multiset<T, T2> s) {
  vector<T> t;
  for (auto x : s) t.push_back(x);
  cout << t;
  return cout;
}
template <typename T>
ostream &operator<<(ostream &cout, queue<T> q) {
  vector<T> t;
  while (q.size()) {
    t.push_back(q.front());
    q.pop();
  }
  cout << t;
  return cout;
}
template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &cout, map<T1, T2, T3> m) {
  for (auto &x : m) {
    cout << "Key: " << x.first << ' ' << "Value: " << x.second << endl;
  }
  return cout;
}
template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x, const pair<T1, T2> y) {
  x.first += y.first;
  x.second += y.second;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &x, const pair<T1, T2> &y) {
  return make_pair(x.first + y.first, x.second + y.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &x, const pair<T1, T2> &y) {
  return make_pair(x.first - y.first, x.second - y.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> x) {
  return make_pair(-x.first, -x.second);
}
template <typename T>
vector<vector<T>> operator~(vector<vector<T>> vec) {
  vector<vector<T>> v;
  int n = vec.size(), m = vec[0].size();
  v.resize(m);
  for (int i = 0; i < m; i++) {
    v[i].resize(n);
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j] = vec[j][i];
    }
  }
  return v;
}
void print0x(int x) {
  std::vector<int> vec;
  while (x) {
    vec.push_back(x & 1);
    x >>= 1;
  }
  std::reverse(vec.begin(), vec.end());
  for (int i = 0; i < (int)vec.size(); i++) {
    std::cout << vec[i];
  }
  std::cout << ' ';
}
template <typename T>
void print0x(T x, int len) {
  std::vector<int> vec;
  while (x) {
    std::cout << (x & 1);
    x >>= 1;
    len--;
  }
  while (len--) cout << 0;
}
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
  cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if (idx > 0)
    cerr << ", ";
  else
    cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
template <int mod>
struct ModInt {
  int x;
  ModInt() { x = 0; }
  ModInt(const int &_x) {
    x = _x % mod;
    if (x < 0) x += mod;
  }
  ModInt(const long long &_x) {
    x = _x % mod;
    if (x < 0) x += mod;
  }
  ModInt<mod> &operator++() {
    ++x;
    if (x == mod) x = 0;
    return *this;
  }
  ModInt<mod> operator++(int) {
    int t = x;
    x++;
    if (x == mod) x = 0;
    return t;
  }
  ModInt<mod> &operator--() {
    --x;
    if (x == -1) x += mod;
    return *this;
  }
  ModInt<mod> operator--(int) {
    int t = x;
    x--;
    if (x == -1) x += mod;
    return t;
  }
  ModInt<mod> operator-() const { return ModInt<mod>((x == 0 ? 0 : mod - x)); }
};
template <int mod>
inline ModInt<mod> operator*(const ModInt<mod> &a, const int &c) {
  return 1LL * a.x * c % mod;
}
template <int mod>
inline int mabs(const ModInt<mod> &a) {
  return a.x;
}
template <int mod>
bool operator==(const ModInt<mod> &a, const ModInt<mod> &b) {
  return a.x == b.x;
}
template <int mod>
bool operator!=(const ModInt<mod> &a, const ModInt<mod> &b) {
  return (a.x != b.x);
}
template <int mod>
inline ModInt<mod> operator+(const ModInt<mod> &a, const ModInt<mod> &b) {
  int tmp = a.x + b.x;
  if (tmp >= mod) tmp -= mod;
  return tmp;
}
template <int mod>
inline ModInt<mod> operator-(const ModInt<mod> &a, const ModInt<mod> &b) {
  int tmp = a.x - b.x;
  if (tmp < 0) tmp += mod;
  return tmp;
}
template <int mod>
inline void operator-=(ModInt<mod> &a, const ModInt<mod> &b) {
  a.x -= b.x;
  a.x += (a.x >> 31 & mod);
}
template <int mod>
inline ModInt<mod> operator*(const ModInt<mod> &a, const ModInt<mod> &b) {
  return 1LL * a.x * b.x % mod;
}
template <int mod>
inline void operator*=(ModInt<mod> &a, const ModInt<mod> &b) {
  a.x = 1LL * a.x * b.x % mod;
}
template <int mod>
inline void operator+=(ModInt<mod> &a, const ModInt<mod> &b) {
  a.x += b.x;
  if (a.x >= mod) a.x -= mod;
}
template <int mod>
inline ModInt<mod> mod_inv(ModInt<mod> x) {
  int m = mod - 2;
  ModInt<mod> basic = x;
  x = 1;
  while (m) {
    if (m & 1) x *= basic;
    m >>= 1;
    basic *= basic;
  }
  return x;
}
template <int mod>
ModInt<mod> operator/(const ModInt<mod> &a, const ModInt<mod> &b) {
  return a * mod_inv(b);
}
template <int mod>
void operator/=(ModInt<mod> &a, const ModInt<mod> &b) {
  a = a / b;
}
template <int mod>
inline ModInt<mod> operator^(const ModInt<mod> &basic, int x) {
  ModInt<mod> res = 1;
  while (x) {
    if (x & 1) res *= basic;
    basic *= basic;
    x >>= 1;
  }
  return res;
}
template <int mod>
istream &operator>>(istream &cin, const ModInt<mod> &x) {
  cin >> x.x;
  x.x %= mod;
  if (x.x < 0) x.x += mod;
  return cin;
}
template <int mod>
ostream &operator<<(ostream &cout, const ModInt<mod> x) {
  cout << x.x;
  return cout;
}
template <int mod, int root, int LogN>
struct NTT {
  using Int = ModInt<mod>;
  static const int MaxN = (1 << LogN);
  int w[MaxN + 5];
  int fac[MaxN + 5], ifac[MaxN + 5], inum[MaxN + 5];
  int fastpow(int basic, int x) {
    int res = 1;
    while (x) {
      if (x & 1) res = 1LL * res * basic % mod;
      basic = 1LL * basic * basic % mod;
      x >>= 1;
    }
    return res;
  }
  int inv[MaxN + 5];
  int buf[MaxN + 5];
  int ww[MaxN + 5];
  inline void ntt(vector<int> &v, int rev, int lg) {
    int n = (1 << lg);
    memset(buf, 0, sizeof(int) * n);
    v.resize(n, 0);
    for (int i = 0; i < n; i++) {
      inv[i] = (inv[i >> 1] >> 1) | ((i & 1) << (lg - 1));
    }
    for (int i = 0; i < n; i++) {
      buf[i] = v[inv[i]];
    }
    int lvl = LogN;
    int *ba, *bb, *wa, *wb;
    int tmp;
    for (int b = 1; b < n; b *= 2) {
      lvl--;
      for (int i = 0; i < b * 2; i++)
        ww[i] = (rev ? w[MaxN - (i << lvl)] : w[i << lvl]);
      for (int i = 0; i < n; i += b * 2) {
        ba = buf + i;
        bb = buf + i + b;
        wa = ww;
        for (int j = 0; j < b; j++) {
          tmp = 1LL * *wa * *bb % mod;
          *bb = *ba - tmp;
          *ba += tmp - mod;
          *ba += ((*ba) >> 31 & mod);
          *bb += ((*bb) >> 31 & mod);
          ba++;
          bb++;
          wa++;
        }
      }
    }
    int t = fastpow(n, mod - 2);
    if (rev) {
      for (int i = 0; i < (1 << lg); i++) {
        buf[i] = 1LL * buf[i] * t % mod;
      }
    }
    for (int i = 0; i < (1 << lg); i++) v[i] = buf[i];
  }
  void add(const vector<int> &a, const vector<int> &b, vector<int> &c) {
    int n = a.size(), m = b.size();
    c.resize(max(n, m), 0);
    for (int i = 0; i < max(n, m); i++) {
      c[i] = (i >= n ? 0 : a[i]) + (i >= m ? 0 : b[i]) - mod;
      c[i] += (c[i] >> 31) & mod;
    }
  }
  void multiply(vector<int> a, vector<int> b, vector<int> &c) {
    int n = (int)a.size() + b.size() - 1;
    if (min(a.size(), b.size()) <= 30) {
      c.clear();
      c.resize(max(0, n), 0);
      for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)b.size(); j++) {
          c[i + j] = (1LL * a[i] * b[j] + c[i + j]) % mod;
        }
      }
      while (c.size() && c.back() == 0) c.pop_back();
      return;
    }
    int nn = 1, lg = 0;
    while (nn < n) {
      nn <<= 1;
      lg++;
    }
    c.resize(nn);
    a.resize(nn, 0);
    b.resize(nn, 0);
    ntt(a, 0, lg);
    ntt(b, 0, lg);
    for (int i = 0; i < nn; i++) {
      c[i] = 1LL * a[i] * b[i] % mod;
    }
    ntt(c, 1, lg);
    while (c.size() && c.back() == 0) c.pop_back();
  }
  inline void togf(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n; i++) v[i] = 1LL * v[i] * fac[i] % mod;
  }
  inline void toegf(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n; i++) v[i] = 1LL * v[i] * ifac[i] % mod;
  }
  void sqr(vector<int> &a) {
    int n = (int)a.size() + a.size() - 1;
    if (a.size() <= 20) {
      vector<int> res(n, 0);
      for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)a.size(); j++) {
          chadd(res[i + j], 1LL * a[i] * a[j] % mod);
        }
      }
      a = res;
      return;
    }
    int nn = 1, lg = 0;
    while (nn < n) {
      nn <<= 1;
      lg++;
    }
    a.resize(nn, 0);
    ntt(a, 0, lg);
    for (int i = 0; i < nn; i++) {
      a[i] = 1LL * a[i] * a[i] % mod;
    }
    ntt(a, 1, lg);
    while (a.size() && a.back() == 0) a.pop_back();
  }
  inline vector<int> derivative(const vector<int> &v) {
    int n = v.size();
    if (n == 0) return v;
    vector<int> rv(n - 1);
    for (int i = 0; i < n - 1; i++) {
      rv[i] = 1LL * v[i + 1] * (i + 1) % mod;
    }
    return rv;
  }
  inline void integral(vector<int> &v, int c = 0) {
    int n = v.size() + 1;
    v.emplace_back(0);
    for (int i = n - 1; i >= 1; i--) {
      v[i] = 1LL * inum[i] * v[i - 1] % mod;
    }
    v[0] = c;
  }
  inline void multiply(vector<int> &v, int c) {
    for (auto &x : v) {
      x = 1LL * x * c % mod;
    }
  }
  inline vector<int> add(const vector<int> &a, const vector<int> &b) {
    vector<int> v = a;
    if (v.size() < b.size()) v.resize(b.size(), 0);
    for (int i = 0; i < (int)b.size(); i++) {
      v[i] += b[i] - mod;
      v[i] += ((v[i] >> 31) & mod);
    }
    return v;
  }
  inline vector<int> sub(const vector<int> &a, const vector<int> &b) {
    vector<int> v = a;
    if (v.size() < b.size()) v.resize(b.size(), 0);
    for (int i = 0; i < (int)b.size(); i++) {
      v[i] -= b[i];
      v[i] += ((v[i] >> 31) & mod);
    }
    return v;
  }
  void inverse(vector<int> &v) {
    int n = v.size();
    if (n == 1) {
      v[0] = fastpow(v[0], mod - 2);
      return;
    }
    int tn = (n - 1) / 2 + 1;
    vector<int> f0(tn);
    for (int i = 0; i < tn; i++) f0[i] = v[i];
    inverse(f0);
    vector<int> rv = f0;
    multiply(rv, 2);
    sqr(f0);
    multiply(v, f0, f0);
    v = sub(rv, f0);
    v.resize(n);
  }
  void div(const vector<int> &F, const vector<int> &G, vector<int> &Q,
           vector<int> &R) {
    int n = F.size(), m = G.size();
    if (n < m) {
      Q.clear();
      R = F;
      return;
    }
    vector<int> f = F, g = G;
    reverse(f.begin(), f.end());
    reverse(g.begin(), g.end());
    g.resize(n - m + 1, 0);
    inverse(g);
    multiply(f, g, Q);
    Q.resize(n - m + 1, 0);
    reverse(Q.begin(), Q.end());
    multiply(G, Q, R);
    R.resize(m - 1, 0);
    for (int i = 0; i < m - 1; i++) {
      R[i] = (F[i] - R[i] + mod) % mod;
    }
  }
  void internal_multipoint_eval(const vector<int> &v, const vector<int> &u,
                                int x, int l, int r, vector<int> &res,
                                vector<int> *f) {
    if (l >= res.size()) return;
    if (r - l == 1) {
      res[l] = v[0];
      return;
    }
    vector<int> Q, R;
    div(v, f[x * 2], Q, R);
    internal_multipoint_eval(R, u, x * 2, l, l + r >> 1, res, f);
    div(v, f[x * 2 + 1], Q, R);
    internal_multipoint_eval(R, u, x * 2 + 1, l + r >> 1, r, res, f);
  }
  vector<int> multipoint_eval(vector<int> &v, const vector<int> &u) {
    if ((int)u.size() <= 32) {
      int n = u.size(), m = v.size();
      vector<int> res(n, 0);
      for (int i = 0; i < n; i++) {
        int ex = 1;
        for (int j = 0; j < m; j++) {
          chadd(res[i], 1LL * ex * v[j] % mod);
          ex = 1LL * ex * u[i] % mod;
        }
      }
      return res;
    }
    vector<int> *f;
    int n = u.size(), nn = 1;
    while (nn < n) nn <<= 1;
    f = new vector<int>[nn + nn];
    for (int i = 0; i < n; i++) f[nn + i] = {mod - u[i], 1};
    for (int i = n; i < nn; i++) f[nn + i] = {1};
    for (int i = nn - 1; i >= 2; i--) {
      multiply(f[i * 2], f[i * 2 + 1], f[i]);
    }
    vector<int> res(n);
    internal_multipoint_eval(v, u, 1, 0, nn, res, f);
    delete[] f;
    return res;
  }
  vector<int> interpolation(const vector<int> &x, vector<int> y) {
    int n = x.size();
    vector<int> *f = new vector<int>[n];
    vector<int> *f2 = new vector<int>[n];
    for (int i = 0; i < n; i++) {
      f[i] = {mod - x[i], 1};
    }
    for (int b = 1; b < n; b *= 2) {
      for (int i = 0; i < n; i += b * 2) {
        if (i + b < n) multiply(f[i], f[i + b], f[i]);
      }
    }
    vector<int> M = f[0], dM = derivative(M);
    vector<int> tmp = multipoint_eval(dM, x);
    for (int i = 0; i < n; i++) {
      y[i] = 1LL * y[i] * fastpow(tmp[i], mod - 2) % mod;
    }
    for (int i = 0; i < n; i++) {
      f[i] = {mod - x[i], 1};
      f2[i] = {y[i]};
    }
    for (int b = 1; b < n; b <<= 1) {
      for (int i = 0; i < n; i += b * 2) {
        if (i + b < n) {
          vector<int> tmp;
          multiply(f2[i], f[i + b], tmp);
          multiply(f[i], f2[i + b], f2[i]);
          f2[i] = add(f2[i], tmp);
          multiply(f[i], f[i + b], f[i]);
        }
      }
    }
    vector<int> res = f2[0];
    delete[] f2;
    delete[] f;
    return res;
  }
  vector<int> log(const vector<int> &v) {
    int n = v.size();
    vector<int> dv = derivative(v), iv = v;
    inverse(iv);
    multiply(dv, iv, dv);
    integral(dv);
    dv.resize(n);
    return dv;
  }
  vector<int> exp(const vector<int> &v) {
    int n = v.size(), tn = (n - 1) / 2 + 1;
    vector<int> rv;
    if (n == 1) {
      rv.push_back(1);
      return rv;
    }
    vector<int> f0(tn);
    for (int i = 0; i < tn; i++) f0[i] = v[i];
    f0 = exp(f0);
    f0.resize(n, 0);
    vector<int> rhs(1, 1);
    rhs = sub(rhs, log(f0));
    rhs = add(rhs, v);
    multiply(f0, rhs, f0);
    f0.resize(n);
    return f0;
  }
  inline void multiply(const vector<Int> &a, const vector<Int> &b,
                       vector<Int> &c) {
    vector<int> ta(a.size()), tb(b.size());
    for (int i = 0; i < (int)a.size(); i++) ta[i] = a[i].x;
    for (int i = 0; i < (int)b.size(); i++) tb[i] = b[i].x;
    vector<int> tc;
    multiply(ta, tb, tc);
    c.clear();
    c.resize(tc.size());
    for (int i = 0; i < (int)c.size(); i++) c[i].x = tc[i];
  }
  vector<Int> multiply(const vector<Int> &a, const vector<Int> &b) {
    vector<int> ta(a.size()), tb(b.size());
    for (int i = 0; i < (int)a.size(); i++) ta[i] = a[i].x;
    for (int i = 0; i < (int)b.size(); i++) tb[i] = b[i].x;
    vector<int> tc;
    multiply(ta, tb, tc);
    vector<Int> c(tc.size());
    for (int i = 0; i < (int)c.size(); i++) c[i].x = tc[i];
    return c;
  }
  vector<int> pow(vector<int> bas, int n, int n2) {
    int c0 = 0;
    for (int i = 0; i < (int)bas.size(); i++) {
      if (bas[i]) break;
      c0 = i + 1;
    }
    for (int i = 0; i < (int)bas.size() - c0; i++) bas[i] = bas[i + c0];
    for (int i = 0; i < c0; i++) bas.pop_back();
    int c = bas[0], inum = fastpow(bas[0], mod - 2);
    for (auto &x : bas) x = 1LL * x * inum % mod;
    bas = log(bas);
    for (auto &x : bas) x = 1LL * x * (n % mod) % mod;
    bas = exp(bas);
    c = fastpow(c, n2);
    for (auto &x : bas) x = 1LL * x * c % mod;
    auto safepow = [](int x, long long n, long long lim) -> int {
      if (x == 1) return min(1LL, lim);
      if (x == 0) return 0;
      long long res = 1;
      for (int i = 0; i < n; i++) {
        res *= x;
        if (res > lim) break;
      }
      res = min(res, lim);
    };
    c0 = safepow(c0, n, bas.size());
    for (int i = c0; i < (int)bas.size(); i++) {
      bas[i] = bas[i - c0];
    }
    for (int i = 0; i < c0; i++) bas[i] = 0;
    return bas;
  }
  NTT() {
    w[0] = 1;
    int ur = fastpow(root, (mod - 1) >> LogN);
    fac[0] = 1;
    for (int i = 1; i <= MaxN; i++) {
      w[i] = 1LL * w[i - 1] * ur % mod;
      fac[i] = 1LL * fac[i - 1] * i % mod;
    }
    ifac[MaxN] = fastpow(fac[MaxN], mod - 2);
    for (int i = MaxN - 1; i >= 0; i--) {
      ifac[i] = 1LL * ifac[i + 1] * (i + 1) % mod;
    }
    for (int i = 1; i <= MaxN; i++) {
      inum[i] = 1LL * ifac[i] * fac[i - 1] % mod;
    }
  }
};
namespace combinatorics {
int *fac;
int *ifac;
int __Tmod;
inline int add(int a, int b) { return (a + b) % __Tmod; }
inline int sub(int a, int b) { return (a - b + __Tmod) % __Tmod; }
inline int mult(int a, int b) { return (1LL * a * b) % __Tmod; }
inline int fastpow(int basic, int x) {
  chmod(x, __Tmod - 1);
  if (x == 0) return 1;
  int res = 1;
  while (x) {
    if (x & 1) res = mult(res, basic);
    basic = mult(basic, basic);
    x >>= 1;
  }
  return res;
}
inline int inv(int x) { return fastpow(x, __Tmod - 2); }
inline int div(int a, int b) { return mult(a, inv(b)); }
void init(int n, int tmod) {
  __Tmod = tmod;
  fac = new int[n + 5];
  ifac = new int[n + 5];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = mult(fac[i - 1], i);
  }
  ifac[n] = inv(fac[n]);
  for (int i = n - 1; i >= 0; i--) {
    ifac[i] = mult(ifac[i + 1], i + 1);
  }
}
inline int C(int n, int m) {
  if (n < m || n < 0 || m < 0) return 0;
  return mult(mult(fac[n], ifac[m]), ifac[n - m]);
}
inline int Cat(int x) { return mult(C(x * 2, x), inv(x + 1)); }
}  // namespace combinatorics
using namespace std;
int n;
vector<int> edges[250005];
int s;
map<int, int> degs;
vector<int> F[250005];
NTT<mod, 3, 19> ntt;
int vis[250005];
void dfs(int x, int par) {
  int deg = 0;
  for (auto u : edges[x]) {
    if (u == par) continue;
    dfs(u, x);
    deg++;
  }
  degs[deg]++;
}
inline int fastpow(long long basic, int x) {
  long long res = 1;
  while (x) {
    if (x & 1) (res *= basic) %= mod;
    (basic *= basic) %= mod;
    x >>= 1;
  }
  return res;
}
int pw[250005];
int main() {
  combinatorics::init(250000, mod);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    edges[x].emplace_back(y);
    edges[y].emplace_back(x);
  }
  dfs(0, -1);
  int m = 0;
  int l = 0;
  for (auto [d, s] : degs) {
    if (d == 0) {
      l = s;
      continue;
    }
    F[m].resize(s + 1);
    pw[0] = 1;
    for (int i = 1; i <= s; i++) pw[i] = 1LL * pw[i - 1] * d % mod;
    for (int i = 0; i <= s; i++)
      F[m][i] = 1LL * combinatorics::C(s, i) * pw[s - i] % mod;
    m++;
  }
  for (int i = 0; i < m - 1; i++) {
    int t1 = -1, t2 = -1;
    for (int j = 0; j < m; j++) {
      if (vis[j]) continue;
      if (t1 == -1)
        t1 = j;
      else if (t2 == -1)
        t2 = j;
      else {
        if (F[j].size() < F[t2].size()) t2 = j;
      }
      if (t2 != -1 && F[t2].size() < F[t1].size()) swap(t1, t2);
    }
    if (t1 > t2) swap(t1, t2);
    ntt.multiply(F[t1], F[t2], F[t1]);
    vis[t2] = 1;
  }
  int res = 0;
  for (int i = 0; i <= n - l; i++) {
    int v = 1LL * F[0][i] * combinatorics::fac[i + l] % mod;
    if ((n - l - i) & 1)
      chadd(res, mod - v);
    else
      chadd(res, v);
  }
  cout << res << endl;
  return 0;
}
