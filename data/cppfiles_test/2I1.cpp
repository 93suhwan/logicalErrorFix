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
int get_premitive_root(const long long& p) {
  int primitive_root = 0;
  if (!primitive_root) {
    primitive_root = [&]() {
      set<int> fac;
      int v = p - 1;
      for (long long i = 2; i * i <= v; i++)
        while (v % i == 0) fac.insert(i), v /= i;
      if (v > 1) fac.insert(v);
      for (int g = 1; g < p; g++) {
        bool ok = true;
        for (auto i : fac)
          if (mod_pow(g, (p - 1) / i, p) == 1) {
            ok = false;
            break;
          }
        if (ok) return g;
      }
      return -1;
    }();
  }
  return primitive_root;
}
void dft(vector<long long>& f, const long long& p, const int& proot,
         bool inverse = false) {
  int n = f.size();
  if (n == 1) return;
  vector<long long> w{1}, iw{1};
  for (int m = w.size(); m < n / 2; m *= 2) {
    long long dw = mod_pow(proot, (p - 1) / (4 * m), p),
              dwinv = mod_pow(dw, p - 2, p);
    w.resize(m * 2);
    iw.resize(m * 2);
    for (int i = 0; i < m; i++)
      w[m + i] = w[i] * dw % p, iw[m + i] = iw[i] * dwinv % p;
  }
  if (!inverse) {
    for (int m = n; m >>= 1;) {
      for (int s = 0, k = 0; s < n; s += 2 * m, k++) {
        for (int i = s; i < s + m; i++) {
          long long x = f[i], y = f[i + m] * w[k] % p;
          f[i] = x + y, f[i + m] = x - y;
          if (f[i] >= p) f[i] -= p;
          if (f[i + m] < 0) f[i + m] += p;
        }
      }
    }
  } else {
    for (int m = 1; m < n; m *= 2) {
      for (int s = 0, k = 0; s < n; s += 2 * m, k++) {
        for (int i = s; i < s + m; i++) {
          long long x = f[i], y = f[i + m];
          f[i] = x + y, f[i + m] = (x - y) * iw[k] % p;
          if (f[i] >= p) f[i] -= p;
          if (f[i + m] < 0) f[i + m] += p;
        }
      }
    }
    long long n_inv = mod_pow(n, p - 2, p);
    for (long long& v : f) (v *= n_inv) %= p;
  }
}
vector<long long> multi(vector<long long> g, vector<long long> h,
                        const long long& p, int n) {
  const int proot = get_premitive_root(p);
  dft(g, p, proot, false);
  dft(h, p, proot, false);
  vector<long long> f(n);
  for (int i = 0; i < n; i++) {
    f[i] = g[i] * h[i] % p;
  }
  dft(f, p, proot, true);
  return f;
}
constexpr long long m0 = 469762049;
constexpr long long m1 = 167772161;
constexpr long long m2 = 595591169;
const long long inv01 = mod_pow(m0, m1 - 2, m1);
const long long inv012 = mod_pow(m0 * m1, m2 - 2, m2);
long long calc(long long& a, long long& b, long long& c, const long long& p) {
  long long res = 0;
  long long x1 = a;
  long long x2 = (b - x1) * inv01;
  x2 %= m1;
  if (x2 < 0) x2 += m1;
  long long x3 = (c - x1 - x2 * m0) % m2 * inv012;
  x3 %= m2;
  if (x3 < 0) x3 += m2;
  res = x1 + x2 * m0 % p + x3 * m0 % p * m1;
  return res % p;
}
vector<long long> multiply(vector<long long> g, vector<long long> h,
                           const long long& p) {
  int resz = g.size() + h.size() - 1;
  int n = 1;
  int pi = 0, qi = 0;
  for (int i = 0; i < g.size(); i++)
    if (g[i]) pi = i;
  for (int i = 0; i < h.size(); i++)
    if (h[i]) qi = i;
  int sz = pi + qi + 2;
  while (n < sz) n *= 2;
  g.resize(n);
  h.resize(n);
  vector<long long> vp[3];
  vp[0] = multi(g, h, m0, n);
  vp[1] = multi(g, h, m1, n);
  vp[2] = multi(g, h, m2, n);
  vector<long long> res(resz);
  for (int i = 0; i < res.size(); i++) {
    long long a, b, c;
    if (i < vp[0].size())
      a = vp[0][i];
    else
      a = 0;
    if (i < vp[1].size())
      b = vp[1][i];
    else
      b = 0;
    if (i < vp[2].size())
      c = vp[2][i];
    else
      c = 0;
    res[i] = calc(a, b, c, p);
  }
  return res;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> l(n), r(n);
  for (int i = 0; i < n - 1; i++) {
    l[i + 1] = (l[i] + a[i]) % k;
  }
  for (int i = 0; i < n - 1; i++) {
    r[i + 1] = (r[i] + a[n - 1 - i]) % k;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    sum %= k;
  }
  vector<long long> f(k), g(k), h(k);
  for (int i = 0; i < n; i++) {
    f[l[i]] += 1;
    g[r[i]] += 1;
  }
  for (int c = 0; c <= m - 2; c++) {
    h[(long long)sum * c % k] += 1;
  }
  vector<long long> fg = multiply(f, g, mod);
  modint ans = 0;
  for (int i = 0; i < fg.size(); i++) {
    int id = i % k;
    int to = k - id;
    to %= k;
    ans += fg[i] * h[to];
  }
  vector<int> cnt(k);
  int obj = (long long)(m - 1) * sum % k;
  obj = k - obj;
  obj %= k;
  for (int c = n - 1; c >= 0; c--) {
    cnt[l[n - 1 - c]]++;
    int to = obj - r[c];
    if (to < 0) to += k;
    ans += cnt[to];
  }
  ans *= m;
  if ((long long)sum * m % k == 0) ans += 1;
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
