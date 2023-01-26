#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(unsigned long long &x) { scanf("%llu", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
const int MOD = 998244353, mod = 998244353;
long long qpow(long long a, long long b) {
  long long res = 1;
  a %= MOD;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
const int MAXN = 4e5 + 10, MAXM = 1e7 + 10;
const int INF = INT_MAX, SINF = 0x3f3f3f3f;
const long long llINF = LLONG_MAX;
const int inv2 = (MOD + 1) / 2;
const int Lim = 1 << 20;
template <int _P>
struct Modint {
  static constexpr int P = _P;

 private:
  int v;

 public:
  Modint() : v(0) {}
  Modint(long long _v) {
    v = _v % P;
    if (v < 0) v += P;
  }
  explicit operator int() const { return v; }
  explicit operator long long() const { return v; }
  explicit operator bool() const { return v > 0; }
  bool operator==(const Modint &o) const { return v == o.v; }
  bool operator!=(const Modint &o) const { return v != o.v; }
  Modint operator-() const { return Modint(v ? P - v : 0); }
  Modint operator+() const { return *this; }
  Modint &operator++() {
    v++;
    if (v == P) v = 0;
    return *this;
  }
  Modint &operator--() {
    if (v == 0) v = P;
    v--;
    return *this;
  }
  Modint operator++(int) {
    Modint r = *this;
    ++*this;
    return r;
  }
  Modint operator--(int) {
    Modint r = *this;
    --*this;
    return r;
  }
  Modint &operator+=(const Modint &o) {
    v += o.v;
    if (v >= P) v -= P;
    return *this;
  }
  Modint operator+(const Modint &o) const { return Modint(*this) += o; }
  Modint &operator-=(const Modint &o) {
    v -= o.v;
    if (v < 0) v += P;
    return *this;
  }
  Modint operator-(const Modint &o) const { return Modint(*this) -= o; }
  Modint &operator*=(const Modint &o) {
    v = (int)(((long long)v) * o.v % P);
    return *this;
  }
  Modint operator*(const Modint &o) const { return Modint(*this) *= o; }
  Modint &operator/=(const Modint &o) { return (*this) *= o.Inv(); }
  Modint operator/(const Modint &o) const { return Modint(*this) /= o; }
  friend Modint operator+(const Modint &x, const long long &o) {
    return x + (Modint)o;
  }
  friend Modint operator+(const long long &o, const Modint &x) {
    return x + (Modint)o;
  }
  friend Modint operator-(const Modint &x, const long long &o) {
    return x - (Modint)o;
  }
  friend Modint operator-(const long long &o, const Modint &x) {
    return (Modint)o - x;
  }
  friend Modint operator*(const Modint &x, const long long &o) {
    return x * (Modint)o;
  }
  friend Modint operator*(const long long &o, const Modint &x) {
    return x * (Modint)o;
  }
  friend Modint operator/(const Modint &x, const long long &o) {
    Modint c = o;
    return x * c.Inv();
  }
  friend Modint operator/(const long long &o, const Modint &x) {
    Modint c = o;
    return c * x.Inv();
  }
  Modint operator^(long long o) const {
    Modint r = 1, t = v;
    while (o) {
      if (o & 1) r *= t;
      t *= t;
      o >>= 1;
    }
    return r;
  }
  Modint operator~() { return (*this) ^ (P - 2); }
  Modint Inv() const { return (*this) ^ (P - 2); }
};
using mi = Modint<MOD>;
template <int P>
void _W(Modint<P> x) {
  printf("%d", (int)x);
}
template <int P>
void _R(Modint<P> &x) {
  long long t;
  scanf("%lld", &t);
  x = t;
}
mi fac[MAXN], inc[MAXN];
void fac_pre(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
  inc[n] = ~fac[n];
  for (int i = n; i; i--) inc[i - 1] = inc[i] * i;
}
mi c(int di, int gao) {
  if (di < gao || gao < 0 || di < 0) return 0;
  return fac[di] * inc[gao] * inc[di - gao];
}
int n, k;
char s[MAXN];
mi ans[MAXN];
int sum[MAXN];
void solve() {
  R(n, k, s);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (s[i - 1] == '1');
  if (k > sum[n]) return W(1);
  for (int i = 0; i <= k; i++) {
    int l = 0, r = 0;
    for (int j = 1; j <= n; j++)
      if (s[j - 1] == '1') {
        if (sum[n] - sum[j - 1] < i) break;
        while (sum[j] - sum[l] > k - i + 1) l++;
        while (r < n && sum[r + 1] - sum[j - 1] <= k) r++;
        ans[i] += c(r - l - (sum[r] - sum[l]) + i, i);
      }
  }
  ans[0] = 1;
  mi res = 0, op = 1;
  for (int i = k; ~i; i--) {
    res += op * ans[i] / c(k, i);
    op = -op;
  }
  W(res);
}
int main() {
  fac_pre(5555);
  int T = 1;
  for (int kase = 1; kase <= T; kase++) {
    solve();
  }
  return 0;
}
