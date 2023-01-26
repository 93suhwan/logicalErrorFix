#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
using namespace std;
template <class T>
using rque = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmax(T &a, const T &b) {
  if (b > a) {
    a = b;
    return 1;
  }
  return 0;
}
__int128_t gcd(__int128_t a, __int128_t b) {
  if (a == 0) return b;
  if (b == 0) return a;
  __int128_t cnt = a % b;
  while (cnt != 0) {
    a = b;
    b = cnt;
    cnt = a % b;
  }
  return b;
}
long long extGCD(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = extGCD(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
struct UnionFind {
  vector<long long> data;
  int num;
  UnionFind(int sz) {
    data.assign(sz, -1);
    num = sz;
  }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return (false);
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    num--;
    return (true);
  }
  int find(int k) {
    if (data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
  long long size(int k) { return (-data[find(k)]); }
  bool same(int x, int y) { return find(x) == find(y); }
};
template <int mod>
struct Mod_Int {
  int x;
  Mod_Int() : x(0) {}
  Mod_Int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  static int get_mod() { return mod; }
  Mod_Int &operator+=(const Mod_Int &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  Mod_Int &operator-=(const Mod_Int &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  Mod_Int &operator*=(const Mod_Int &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  Mod_Int &operator/=(const Mod_Int &p) {
    *this *= p.inverse();
    return *this;
  }
  Mod_Int &operator++() { return *this += Mod_Int(1); }
  Mod_Int operator++(int) {
    Mod_Int tmp = *this;
    ++*this;
    return tmp;
  }
  Mod_Int &operator--() { return *this -= Mod_Int(1); }
  Mod_Int operator--(int) {
    Mod_Int tmp = *this;
    --*this;
    return tmp;
  }
  Mod_Int operator-() const { return Mod_Int(-x); }
  Mod_Int operator+(const Mod_Int &p) const { return Mod_Int(*this) += p; }
  Mod_Int operator-(const Mod_Int &p) const { return Mod_Int(*this) -= p; }
  Mod_Int operator*(const Mod_Int &p) const { return Mod_Int(*this) *= p; }
  Mod_Int operator/(const Mod_Int &p) const { return Mod_Int(*this) /= p; }
  bool operator==(const Mod_Int &p) const { return x == p.x; }
  bool operator!=(const Mod_Int &p) const { return x != p.x; }
  Mod_Int inverse() const {
    assert(*this != Mod_Int(0));
    return pow(mod - 2);
  }
  Mod_Int pow(long long k) const {
    Mod_Int now = *this, ret = 1;
    for (; k > 0; k >>= 1, now *= now) {
      if (k & 1) ret *= now;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const Mod_Int &p) {
    return os << p.x;
  }
  friend istream &operator>>(istream &is, Mod_Int &p) {
    long long a;
    is >> a;
    p = Mod_Int<mod>(a);
    return is;
  }
};
long long mpow2(long long x, long long n, long long mod) {
  long long ans = 1;
  x %= mod;
  while (n != 0) {
    if (n & 1) ans = ans * x % mod;
    x = x * x % mod;
    n = n >> 1;
  }
  return ans;
}
long long modinv2(long long a, long long mod) {
  long long b = mod, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= mod;
  if (u < 0) u += mod;
  return u;
}
constexpr int mod = 1000000007;
using mint = Mod_Int<mod>;
mint mpow(mint x, long long n) {
  mint ans = 1;
  while (n != 0) {
    if (n & 1) ans *= x;
    x *= x;
    n = n >> 1;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cout << fixed << setprecision(15);
  int n, m, q;
  cin >> n >> m >> q;
  vector<long long> a(n), b(m);
  for (long long i = 0; i < (n); i++) cin >> a[i];
  for (long long i = 0; i < (m); i++) cin >> b[i];
  vector<pair<long long, int>> v;
  for (long long i = 0; i < (n); i++) v.emplace_back(a[i], 1);
  for (long long i = 0; i < (m); i++) v.emplace_back(b[i], 0);
  sort(v.begin(), v.end());
  set<int> s;
  for (long long i = 0; i < (n + m); i++) s.insert(i);
  vector<int> num(n + m);
  for (long long i = 0; i < (n + m); i++) num[i] = v[i].second;
  vector<long long> sum(n + m + 1, 0);
  for (long long i = 0; i < (n + m); i++) sum[i + 1] = sum[i] + v[i].first;
  vector<pair<int, int>> ev;
  for (long long i = 0; i < (n + m - 1); i++)
    ev.emplace_back(v[i + 1].first - v[i].first, i);
  int k;
  for (long long i = 0; i < (q); i++) cin >> k, ev.emplace_back(k, n + m + i);
  sort(ev.begin(), ev.end());
  vector<long long> ans(q);
  long long val = 0;
  for (long long i = 0; i < (n); i++) val += a[i];
  for (auto [unko, no] : ev) {
    if (no >= n + m)
      ans[no - (n + m)] = val;
    else {
      auto r = *s.upper_bound(no);
      s.erase(no);
      val -= sum[no + 1] - sum[no + 1 - num[no]];
      val += sum[r + 1 - num[r]] - sum[r + 1 - num[r] - num[no]];
      num[r] += num[no];
    }
  }
  for (long long i = 0; i < (q); i++) cout << ans[i] << '\n';
}
