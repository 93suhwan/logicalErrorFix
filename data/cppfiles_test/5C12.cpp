#include <bits/stdc++.h>
using namespace std;
constexpr long long mod = 1000000007;
const long long INF = mod * mod;
const long double eps = 1e-8;
const long double pi = acosl(-1.0);
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
const int max_n = 1 << 18;
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
using mP = pair<modint, modint>;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort((a).begin(), (a).end());
  vector<mP> memo(n);
  memo[0] = {1, 0};
  for (int c = 0; c <= n - 2; c++) {
    modint A = (long long)n * k - c - (long long)(n - c) * (k - 1);
    modint B = -(long long)c * (k - 1);
    modint x = A * memo[c].first;
    if (c > 0) x += B * memo[c - 1].first;
    modint y = A * memo[c].second;
    if (c > 0) y += B * memo[c - 1].second;
    y -= (long long)n * k;
    x /= n - c;
    y /= n - c;
    memo[c + 1] = {x, y};
  }
  int c = n - 1;
  modint A = (long long)n * k - c - (long long)(n - c) * (k - 1);
  modint B = -(long long)c * (k - 1);
  modint x = A * memo[c].first;
  if (c > 0) x += B * memo[c - 1].first;
  modint y = A * memo[c].second;
  if (c > 0) y += B * memo[c - 1].second;
  y -= (long long)n * k;
  vector<modint> ex(n);
  ex[0] = (modint)-y / x;
  for (int c = 1; c < n; c++) {
    ex[c] = memo[c].first * ex[0] + memo[c].second;
  }
  int ad = 0;
  vector<int> cs;
  int rest = k;
  for (int i = 0; i < n; i++) {
    int le = i;
    while (i + 1 < n && a[i] == a[i + 1]) i++;
    int len = i - le + 1;
    if (a[i] < 0) {
      ad = len;
    } else {
      rest--;
      cs.push_back(len);
    }
  }
  sort((cs).begin(), (cs).end());
  vector<pair<int, int> > ps;
  for (int i = 0; i < cs.size(); i++) {
    int le = i;
    while (i + 1 < cs.size() && cs[i] == cs[i + 1]) i++;
    int cnt = i - le + 1;
    ps.push_back({cs[i], cnt});
  }
  ps.push_back({0, rest});
  modint ans = 0;
  vector<modint> coef(ad + 1);
  for (int i = 0; i < ad + 1; i++) {
    coef[i] = comb(ad, i) * (modint)mod_pow(k - 1, ad - i);
  }
  ex.push_back(0);
  for (pair<int, int> p : ps) {
    for (int i = 0; i <= ad; i++) {
      modint val = ex[p.first + i];
      val *= p.second;
      ans += val * coef[i];
    }
  }
  ans -= (modint)(k - 1) * ex[0] * (modint)mod_pow(k, ad);
  ans /= k;
  ans /= mod_pow(k, ad);
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init_f();
  solve();
  return 0;
}
