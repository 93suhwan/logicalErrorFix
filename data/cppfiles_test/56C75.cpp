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
const int MOD = 1e9 + 7, mod = 998244353;
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
int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(long long x) { return __builtin_popcountll(x); }
int ctz(int x) { return __builtin_ctz(x); }
int ctz(long long x) { return __builtin_ctzll(x); }
int clz(int x) { return 31 - __builtin_clz(x); }
int clz(long long x) { return 63 - __builtin_clzll(x); }
struct ans {
  mi a[7];
} fund[80];
ans operator*(ans a, ans b) {
  ans ini;
  memset((ini.a), 0, sizeof((ini.a)));
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      for (int k = 0; k < 6; k++) {
        if ((i & 6) == (j & 6) || (i & 6) == (k & 6)) continue;
        ini.a[i] += a.a[j] * b.a[k];
      }
  return ini;
}
int n;
map<long long, ans> dp;
mi ct[80];
ans cd(long long x) {
  if (!dp.count(x))
    return fund[n - clz(x)];
  else
    return dp[x];
}
vector<pair<long long, long long> > vec[MAXN];
int cs(string &s) {
  if (s[0] == 'w') return 0;
  if (s[0] == 'y') return 1;
  if (s[0] == 'g') return 2;
  if (s[0] == 'b') return 3;
  if (s[0] == 'r') return 4;
  if (s[0] == 'o') return 5;
  return 6;
}
void print(ans a) {
  for (int i = 0; i < 6; i++) printf("%lld ", a.a[i]);
  W("");
}
void solve() {
  R(n);
  ct[1] = 1;
  for (int i = 2; i <= n; i++) ct[i] = ct[i - 1] * ct[i - 1] * 16;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 6; j++) fund[i].a[j] = ct[i];
  int m;
  R(m);
  for (int i = 1; i <= m; i++) {
    long long x;
    string s;
    R(x, s);
    vec[clz(x)].push_back({x, cs(s)});
  }
  vector<long long> tmp;
  for (int i = n - 1; ~i; i--) {
    vector<long long> vz;
    for (auto u : tmp) {
      dp[u] = cd((u << 1)) * cd((u << 1 | 1));
      vz.push_back(u / 2);
    }
    swap(vz, tmp);
    for (auto j : vec[i]) {
      long long u = j.first;
      tmp.push_back(u / 2);
      ans c;
      if (i < n - 1)
        c = cd((u << 1)) * cd((u << 1 | 1));
      else
        c = cd(u);
      dp[u] = c;
      for (int k = 0; k < 6; k++)
        if (k != j.second) dp[u].a[k] = 0;
    }
    sort((tmp).begin(), (tmp).end()),
        tmp.resize(unique((tmp).begin(), (tmp).end()) - tmp.begin());
  }
  auto t = cd(1);
  mi res = 0;
  for (int i = 0; i < 6; i++) res += t.a[i];
  W(res);
}
int main() {
  int T = 1;
  for (int kase = 1; kase <= T; kase++) {
    solve();
  }
  return 0;
}
