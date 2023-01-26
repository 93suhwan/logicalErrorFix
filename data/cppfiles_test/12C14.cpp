#include <bits/stdc++.h>
using namespace std;
constexpr long long mod = 1000000007;
const long long INF = mod * mod;
const double eps = 1e-8;
const double pi = acosl(-1.0);
long long mod_pow(long long x, long long n, long long m = mod) {
  if (n < 0) {
    long long res = mod_pow(x, -n, m);
    return mod_pow(res, m - 2, m);
  }
  if (abs(x) >= m) x %= m;
  if (x < 0) x += m;
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}
struct modint {
  long long n;
  modint() : n(0) { ; }
  modint(long long m) : n(m) {
    if (n >= mod)
      n %= mod;
    else if (n < 0)
      n = (n % mod + mod) % mod;
  }
  operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) {
  a.n += b.n;
  if (a.n >= mod) a.n -= mod;
  return a;
}
modint operator-=(modint& a, modint b) {
  a.n -= b.n;
  if (a.n < 0) a.n += mod;
  return a;
}
modint operator*=(modint& a, modint b) {
  a.n = ((long long)a.n * b.n) % mod;
  return a;
}
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, long long n) {
  if (n == 0) return modint(1);
  modint res = (a * a) ^ (n / 2);
  if (n % 2) res = res * a;
  return res;
}
long long inv(long long a, long long p) {
  return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) {
  a = a / b;
  return a;
}
const int max_n = 1 << 2;
modint fact[max_n], factinv[max_n];
void init_f() {
  fact[0] = modint(1);
  for (int i = 0; i < max_n - 1; i++) {
    fact[i + 1] = fact[i] * modint(i + 1);
  }
  factinv[max_n - 1] = modint(1) / fact[max_n - 1];
  for (int i = max_n - 2; i >= 0; i--) {
    factinv[i] = factinv[i + 1] * modint(i + 1);
  }
}
modint comb(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return fact[a] * factinv[a - b];
}
struct CHT {
  vector<pair<long long, long long> > v;
  vector<pair<long long, long long> > memo;
  int l;
  bool check(pair<long long, long long> a, pair<long long, long long> b,
             pair<long long, long long> c) {
    return (b.first - a.first) * (c.second - b.second) >=
           (b.second - a.second) * (c.first - b.first);
  }
  void build(vector<pair<long long, long long> > a) {
    l = 0;
    sort(a.begin(), a.end());
    for (int i = (int)a.size() - 1; i >= 0; i--) {
      while (v.size() >= 2 && check(v[v.size() - 2], v[v.size() - 1], a[i]))
        v.pop_back();
      v.push_back(a[i]);
    }
  }
  void build() {
    for (int i = (int)memo.size() - 1; i >= 0; i--) {
      while (v.size() >= 2 && check(v[v.size() - 2], v[v.size() - 1], memo[i]))
        v.pop_back();
      v.push_back(memo[i]);
    }
    memo.clear();
  }
  void add(pair<long long, long long> a) { memo.push_back(a); }
  long long f(pair<long long, long long> a, long long x) {
    return a.first * x + a.second;
  }
  long long query(long long x) {
    while (l + 1 < v.size() && f(v[l], x) > f(v[l + 1], x)) l++;
    return f(v[l], x);
  }
};
char s[2005][2005];
int up[2005][2005];
int dow[2005][2005];
void solve() {
  int n, m;
  cin >> n >> m;
  n++;
  m++;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> s[i][j];
  for (int j = 0; j < m; j++) {
    int cur = -1;
    for (int i = 0; i < n; i++) {
      if (s[i][j] == '1') cur = i;
      up[i][j] = cur;
    }
    cur = n;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i][j] == '1') cur = i;
      dow[i][j] = cur;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    CHT ct;
    vector<pair<long long, long long> > ps;
    for (int j = 0; j < m; j++) {
      int d = mod;
      if (up[i][j] >= 0) d = min(d, i - up[i][j]);
      if (dow[i][j] < n) d = min(d, dow[i][j] - i);
      if (d < mod) {
        pair<long long, long long> p = {-2 * j, j * j + d * d};
        ps.push_back(p);
      }
    }
    ct.build(ps);
    for (int j = 0; j < m; j++) {
      long long val = ct.query(j);
      val += j * j;
      ans += val;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
