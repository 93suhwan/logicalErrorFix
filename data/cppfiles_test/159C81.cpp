#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
constexpr long long mod = 998244353;
const long long INF = mod * mod;
template <typename T>
void chmin(T& a, T b) {
  a = min(a, b);
}
template <typename T>
void chmax(T& a, T b) {
  a = max(a, b);
}
template <typename T>
void cinarray(vector<T>& v) {
  for (int i = 0; i < v.size(); i++) cin >> v[i];
}
template <typename T>
void coutarray(vector<T>& v) {
  for (int i = 0; i < v.size(); i++) {
    if (i > 0) cout << " ";
    cout << v[i];
  }
  cout << "\n";
}
long long mod_pow(long long x, long long n, long long m = mod) {
  if (n < 0) {
    long long res = mod_pow(x, -n, m);
    return mod_pow(res, m - 2, m);
  }
  if (abs(x) >= m) x %= m;
  if (x < 0) x += m;
  if (x == 0) return 0;
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}
struct modint {
  int n;
  modint() : n(0) { ; }
  modint(long long m) {
    if (m < 0 || mod <= m) {
      m %= mod;
      if (m < 0) m += mod;
    }
    n = m;
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
const int max_n = 1 << 20;
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
long long gcd(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  if (a < b) swap(a, b);
  while (b) {
    long long r = a % b;
    a = b;
    b = r;
  }
  return a;
}
mt19937 mt(time(0));
uniform_int_distribution<> ud(0, (1 << 20) - 1);
unsigned long long ranum() {
  unsigned long long res = 0;
  res |= ud(mt);
  res |= (unsigned long long)ud(mt) << 20;
  res |= (unsigned long long)ud(mt) << 40;
  return res;
}
const int mn = 1 << 20;
bool isp[mn];
int chp[mn];
unsigned long long h[mn];
unsigned long long hs[mn];
unsigned long long hfact[mn];
void init() {
  fill(isp + 2, isp + mn, true);
  for (int i = 2; i < mn; i++) {
    if (!isp[i]) continue;
    h[i] = ranum();
    chp[i] = i;
    for (int j = 2 * i; j < mn; j += i) {
      isp[j] = false;
      chp[j] = i;
    }
  }
  hs[1] = 0;
  for (int i = 2; i < mn; i++) {
    hs[i] = hs[i / chp[i]] ^ h[chp[i]];
    hfact[i] = hfact[i - 1] ^ hs[i];
  }
}
void solve() {
  int n;
  cin >> n;
  unsigned long long z = 0;
  for (int i = 1; i <= n; i++) {
    z ^= hfact[i];
  }
  vector<int> ans;
  if (z == 0) {
    for (int i = 1; i <= n; i++) ans.push_back(i);
  } else {
    map<unsigned long long, int> mp;
    for (int i = 1; i <= n; i++) mp[hfact[i]] = i;
    for (int cnt = 1;; cnt++) {
      vector<int> del;
      unsigned long long cs = z;
      function<bool(int, int)> dfs = [&](int dep, int loc) {
        if (dep == cnt - 1) {
          if (mp.find(cs) != mp.end()) {
            del.push_back(mp[cs]);
            return true;
          }
          return false;
        }
        if (loc > n) return false;
        del.push_back(loc);
        cs ^= hfact[loc];
        if (dfs(dep + 1, loc + 1)) return true;
        del.pop_back();
        cs ^= hfact[loc];
        if (dfs(dep, loc + 1)) return true;
        return false;
      };
      if (dfs(0, 2)) {
        vector<bool> can(n + 1, true);
        for (int id : del) can[id] = false;
        for (int i = 1; i <= n; i++)
          if (can[i]) ans.push_back(i);
        break;
      }
    }
  }
  cout << ans.size() << "\n";
  coutarray(ans);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  solve();
  return 0;
}
