#include <bits/stdc++.h>
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
int frac[1001001], invf[1001001], inv[1001001];
inline void init(int N) {
  frac[0] = 1;
  for (int i = 1; i <= N; i++) frac[i] = 1ll * frac[i - 1] * i % 998244353;
  invf[N] = qpow(frac[N], 998244353 - 2);
  for (int i = N; i >= 1; i--) {
    invf[i - 1] = 1ll * invf[i] * i % 998244353;
    inv[i] = 1ll * invf[i] * frac[i - 1] % 998244353;
  }
}
inline long long C(int n, int m) {
  if (n < m || m < 0) return 0;
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
int n, h[202202], d[202202], add[202202];
inline bool check(int mid) {
  for (int i = 1; i <= n; i++) d[i] = h[i], add[i] = 0;
  for (int i = n; i >= 3; i--) {
    if (d[i] < mid - add[i]) return false;
    int D = (d[i] - max(mid - add[i], 0)) / 3;
    add[i - 1] += D, add[i - 2] += 2 * D;
  }
  return add[1] + d[1] >= mid && add[2] + d[2] >= mid;
}
inline void work() {
  n = read<int>();
  for (int i = 1; i <= n; i++) h[i] = read<int>();
  int l = 1, r = 1e9 + 1;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%d\n", l);
}
int main() {
  int t = read<int>();
  while (t--) work();
  return 0;
}
