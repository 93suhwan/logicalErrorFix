#include <bits/stdc++.h>
using namespace std;
mt19937_64 myrand(chrono::system_clock::now().time_since_epoch().count());
const long long INF = 1e18, P = 998244353, MXN = 1e6 + 5;
const pair<long long, long long> go[] = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                                         {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
long long n, m, tot, spc;
long long arr[MXN];
template <class T>
T qpow(T x, long long y) {
  T r(1);
  while (y) {
    if (y & 1) r = r * x;
    x = x * x, y >>= 1;
  }
  return r;
}
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
template <class T>
void umx(T &x, T y) {
  x = max(x, y);
}
template <class T>
void umn(T &x, T y) {
  x = min(x, y);
}
long long abs(pair<long long, long long> x) {
  return abs(x.first) + abs(x.second);
}
long long randint(long long l, long long r) {
  uniform_int_distribution<long long> res(l, r);
  return res(myrand);
}
long double randdb(long double l, long double r) {
  uniform_real_distribution<long double> res(l, r);
  return res(myrand);
}
pair<long long, long long> operator+(const pair<long long, long long> &x,
                                     const pair<long long, long long> &y) {
  return pair<long long, long long>(x.first + y.first, x.second + y.second);
}
pair<long long, long long> operator-(const pair<long long, long long> &x,
                                     const pair<long long, long long> &y) {
  return pair<long long, long long>(x.first - y.first, x.second - y.second);
}
pair<long long, long long> operator*(const pair<long long, long long> &x,
                                     const long long &y) {
  return pair<long long, long long>(x.first * y, x.second * y);
}
struct mll {
  long long v;
  explicit mll(long long _v = 0) : v(_v) {}
  long long redu(const long long &x) const {
    if (x < P) return x;
    if (x < (P << 1)) return x - P;
    return x % P;
  }
  explicit operator long long() const { return v; }
  mll operator+(const mll &y) const { return mll(redu(v + y.v)); }
  mll operator-(const mll &y) const { return mll(redu(P + v - y.v)); }
  mll operator*(const mll &y) const { return mll(redu(v * y.v)); }
  mll operator/(const mll &y) const {
    return mll(redu(v * (long long)qpow(y, P - 2)));
  }
  mll &operator=(const mll &y) { return v = y.v, *this; }
  mll &operator+=(const mll &y) { return v = redu(v + y.v), *this; }
  mll &operator-=(const mll &y) { return v = redu(P + v - y.v), *this; }
  mll &operator*=(const mll &y) { return v = redu(v * y.v), *this; }
  mll &operator/=(const mll &y) {
    return v = redu(v * (long long)qpow(y, P - 2)), *this;
  }
  bool operator==(const mll &y) const { return v == y.v; }
  bool operator!=(const mll &y) const { return v != y.v; }
};
template <class T>
struct myvec {
  T *v;
  int sz, dsz;
  myvec() { v = NULL, sz = dsz = 0; }
  ~myvec() { free(v); }
  operator T *() const { return v; }
  T *begin() { return v; }
  T *end() { return v + sz; }
  void rsz(int x) { v = (T *)realloc(v, sizeof(T) * (dsz = sz = x)); }
  void push_back(T x) {
    if (sz == dsz) v = (T *)realloc(v, sizeof(T) * (dsz = dsz << 1 | 1));
    v[sz++] = x;
  }
  void fill(T x) {
    for (int i = 0; i < sz; i++) v[i] = x;
  }
};
char str[MXN][4];
bool match(char *x, const char *y) {
  for (int i = 0; i < 2; i++)
    if (x[i] != y[i] && x[i] != '?') return 0;
  return 1;
}
void solve() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", str[i]);
    for (int j = 0; j < 2; j++) {
      if (str[i][j] == 'W')
        tot++;
      else if (str[i][j] == 'B')
        tot--;
      else
        spc++;
    }
  }
  long long tmp = (spc + tot) >> 1;
  mll ans(1);
  for (int i = 0; i < tmp; i++) ans = ans * mll(spc - i);
  for (int i = 1; i <= tmp; i++) ans = ans * qpow((mll)i, P - 2);
  mll del(1);
  long long f = 1, g = 1;
  for (int i = 1; i <= n; i++) {
    long long tmp = match(str[i], "WB") + match(str[i], "BW");
    f &= match(str[i], "WB");
    g &= match(str[i], "BW");
    del *= (mll)tmp;
  }
  ans -= del - (mll)(f + g);
  printf("%lld", (long long)ans);
}
int main() {
  solve();
  return 0;
}
