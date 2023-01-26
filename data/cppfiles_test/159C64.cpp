#include <bits/stdc++.h>
using std::cerr;
using std::endl;
using std::swap;
template <class T>
inline T read() {
  T r = 0, f = 0;
  char c;
  while (!isdigit(c = getchar())) f |= (c == '-');
  while (isdigit(c)) r = (r << 1) + (r << 3) + (c ^ 48), c = getchar();
  return f ? -r : r;
}
inline char getc() {
  char c;
  while (!isalpha(c = getchar()))
    ;
  return c;
}
template <class T>
inline T abs(T a) {
  return a < 0 ? -a : a;
}
template <class T>
inline T min(T a, T b) {
  return a < b ? a : b;
}
template <class T>
inline T max(T a, T b) {
  return a > b ? a : b;
}
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long qpow(long long a, int b, int MOD = 998244353) {
  long long ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) (ans *= a) %= MOD;
    (a *= a) %= MOD;
  }
  return ans;
}
struct Z {
  int x;
  inline int val() const { return x; }
  inline int inv() const { return qpow(x, 998244353 - 2); }
  Z(int x = 0) : x(x) {}
  Z operator-() const {
    return Z((998244353 - x >= 998244353 ? 998244353 - x - 998244353
                                         : 998244353 - x));
  }
  Z &operator+=(const Z &z) {
    x = (x + z.x >= 998244353 ? x + z.x - 998244353 : x + z.x);
    return *this;
  }
  Z &operator-=(const Z &z) {
    x = (x - z.x < 0 ? x - z.x + 998244353 : x - z.x);
    return *this;
  }
  Z &operator*=(const Z &z) {
    x = 1ll * x * z.x % 998244353;
    return *this;
  }
  Z &operator/=(const Z &z) {
    x = 1ll * x * z.inv() % 998244353;
    return *this;
  }
  Z operator+(const Z &z) const {
    return Z((x + z.x >= 998244353 ? x + z.x - 998244353 : x + z.x));
  }
  Z operator-(const Z &z) const {
    return Z((x - z.x < 0 ? x - z.x + 998244353 : x - z.x));
  }
  Z operator*(const Z &z) const { return Z(1ll * x * z.x % 998244353); }
  Z operator/(const Z &z) const { return Z(1ll * x * z.inv() % 998244353); }
};
template <int T, class Tt>
struct Hash {
  struct E {
    Tt v;
    int w, nxt;
    E() {}
    E(Tt v, int w, int nxt) : v(v), w(w), nxt(nxt) {}
  } e[T + 100];
  int s_e, head[T + 100];
  std::vector<int> d;
  inline void a_e(int u, Tt v, int w) {
    e[++s_e] = E(v, w, head[u]);
    head[u] = s_e;
  }
  inline int H(Tt x) { return (1ll * x * x + (x & T) + (x ^ T)) % T + 1; }
  inline bool find(Tt x) {
    int u = H(x);
    for (int i = head[u]; i; i = e[i].nxt)
      if (e[i].v == x) return true;
    return false;
  }
  int &operator[](const Tt x) {
    int u = H(x);
    for (int i = head[u]; i; i = e[i].nxt)
      if (e[i].v == x) return e[i].w;
    a_e(u, x, 0);
    d.push_back(x);
    return e[head[u]].w;
  }
  inline void clear() {
    s_e = 0;
    for (auto u : d) head[H(u)] = 0;
    d.clear();
  }
};
namespace Math {
long long frac[1001001], invf[1001001], inv[1001001];
inline void init(int N) {
  frac[0] = 1;
  for (int i = 1; i <= N; i++) frac[i] = frac[i - 1] * i % 998244353;
  invf[N] = qpow(frac[N], 998244353 - 2);
  for (int i = N; i >= 1; i--) {
    invf[i - 1] = invf[i] * i % 998244353;
    inv[i] = invf[i] * frac[i - 1] % 998244353;
  }
}
inline long long C(int n, int m) {
  return 1ll * frac[n] * invf[m] % 998244353 * invf[n - m] % 998244353;
}
}  // namespace Math
using namespace Math;
template <int T>
struct Polyn {
  int n, a[T];
  Polyn(int _n = 0) {
    n = _n;
    for (int i = 0; i < n; i++) a[i] = 0;
  }
  int &operator[](const int x) { return a[x]; }
  inline Polyn R() {
    Polyn b(n);
    for (int i = 0; i * 2 < n; i++) b[i] = a[n - 1 - i];
    return b;
  }
  inline Polyn Der() {
    Polyn b(n - 1);
    for (int i = 1; i < n; i++) b[i - 1] = 1ll * a[i] * i % 998244353;
    return b;
  }
  inline Polyn Int() {
    Polyn b(n + 1);
    for (int i = 1; i <= n; i++) b[i] = 1ll * a[i - 1] * inv[i] % 998244353;
    return b;
  }
  inline Polyn Inv() {
    Polyn b(n);
    b[0] = qpow(a[0], 998244353 - 2);
    long long inv = b[0];
    for (int i = 1; i < n; i++) {
      long long res = 0;
      for (int j = 0; j < i; j++) (res += 1ll * b[j] * a[i - j]) %= 998244353;
      b[i] = (998244353 - res) * inv % 998244353;
    }
    return b;
  }
  Polyn operator-() {
    Polyn b(*this);
    for (int i = 0; i < n; i++) b[i] = (998244353 - b[i]) % 998244353;
    return b;
  }
  Polyn operator+(int x) {
    Polyn b(*this);
    (b[0] += x) %= 998244353;
    return b;
  }
  Polyn operator-(int x) {
    Polyn b(*this);
    (b[0] += 998244353 - x) %= 998244353;
    return b;
  }
  Polyn operator*(int x) {
    Polyn b(*this);
    for (int i = 0; i < n; i++) b[i] = 1ll * b[i] * x % 998244353;
    return b;
  }
  Polyn operator+(Polyn b) {
    Polyn c = b;
    for (int i = 0; i < n; i++) (c[i] += a[i]) %= 998244353;
    return c;
  }
  Polyn operator-(Polyn b) {
    Polyn c = (*this);
    for (int i = 0; i < n; i++) (c[i] += 998244353 - b[i]) %= 998244353;
    return c;
  }
  Polyn operator*(Polyn b) {
    Polyn c(n + b.n - 1);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < b.n; j++)
        (c[i + j] += 1ll * a[i] * b[j] % 998244353) %= 998244353;
    return c;
  }
  Polyn operator/(Polyn b) { return (*this) * b.Inv(); }
  Polyn operator%(Polyn b) {
    Polyn r = (*this);
    for (int i = n - 1; i >= b.n - 1; i--) {
      int inv = r[i] * qpow(b[b.n - 1], 998244353 - 2);
      for (int j = i; j >= i - b.n + 1; j--)
        (r[j] += 998244353 - 1ll * b[j - i + b.n - 1] * inv % 998244353) %=
            998244353;
    }
    r.n = min(n, b.n - 1);
    return r;
  }
  inline int Y(int x) {
    int Sum = 0;
    for (int i = n - 1; ~i; i--) Sum = (1ll * Sum * x + a[i]) % 998244353;
    return Sum;
  }
};
template <int T>
struct Mat {
  int n, m, a[T + 3][T + 3];
  inline void init(int _n = 0, int _m = 0, bool o = 1) {
    n = _n, m = _m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) a[i][j] = i ^ j ? 0 : o;
  }
  Mat operator+(const Mat &b) const {
    Mat c(*this);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) (c.a[i][j] += b.a[i][j]) %= 998244353;
    return c;
  }
  Mat operator-(const Mat &b) const {
    Mat c(*this);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        (c.a[i][j] += 998244353 - b.a[i][j]) %= 998244353;
    return c;
  }
  Mat operator*(const Mat &b) const {
    Mat c;
    c.init(n, b.m);
    for (int i = 0; i < n; i++)
      for (int k = 0; k < m; k++)
        for (int j = 0; j < b.m; j++)
          (c.a[i][j] += 1ll * a[i][k] * b.a[k][j] % 998244353) %= 998244353;
    return c;
  }
  Mat &operator+=(const Mat &b) {
    (*this) = (*this) + b;
    return *this;
  }
  Mat &operator-=(const Mat &b) {
    (*this) = (*this) - b;
    return *this;
  }
  Mat &operator*=(const Mat &b) {
    (*this) = (*this) * b;
    return *this;
  }
  bool operator==(const Mat &b) const {
    if (n != b.n || m != b.m) return false;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (a[i][j] != b.a[i][j]) return false;
    return true;
  }
  bool operator!=(const Mat &b) const { return !((*this) == b); }
};
std::mt19937_64 RAND(time(0));
int n, s_p, p[1001001], Minp[1001001];
bool n_p[1001001];
unsigned long long val[1001001];
inline void init() {
  for (int i = 2; i <= n; i++) {
    if (!n_p[i]) p[++s_p] = i, Minp[i] = i;
    for (int j = 1; j <= s_p && p[j] <= n / i; j++) {
      n_p[i * p[j]] = 1;
      Minp[i * p[j]] = p[j];
      if (!(i % p[j])) break;
    }
  }
  for (int i = 1; i <= s_p; i++) val[p[i]] = RAND();
}
unsigned long long F, f[1001001];
bool cant[1001001];
inline void out(int size) {
  printf("%d\n", size);
  for (int i = 1; i <= n; i++)
    if (!cant[i]) printf("%d ", i);
}
std::map<unsigned long long, int> in;
int main() {
  n = read<int>(), init();
  for (int i = 2; i <= n; i++) {
    int x = i;
    f[i] = f[i - 1];
    while (x > 1) {
      f[i] ^= val[Minp[x]];
      x /= Minp[x];
    }
    F ^= f[i];
    in[f[i]] = i;
  }
  if (!F) return out(n), 0;
  if (in[F]) {
    cant[in[F]] = 1;
    return out(n - 1), 0;
  }
  for (int i = 1; i <= n; i++) {
    if (!in[F ^ f[i]]) continue;
    cant[in[F ^ f[i]]] = cant[i] = 1;
    return out(n - 2), 0;
  }
  cant[2] = cant[n / 2] = cant[n] = 1;
  out(n - 3);
  return 0;
}
