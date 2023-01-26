#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
constexpr long long mod = 998244353;
const long long INF = mod * mod;
const long double eps = 1e-12;
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
struct uf {
 private:
  vector<int> par, ran;

 public:
  uf(int n) {
    par.resize(n, 0);
    ran.resize(n, 0);
    for (int i = 0; i < n; i++) {
      par[i] = i;
    }
  }
  int find(int x) {
    if (par[x] == x)
      return x;
    else
      return par[x] = find(par[x]);
  }
  void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (ran[x] < ran[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (ran[x] == ran[y]) ran[x]++;
    }
  }
  bool same(int x, int y) { return find(x) == find(y); }
};
const int mn = 1000005;
vector<int> ps;
vector<int> chp[mn];
bool isp[mn];
void init() {
  fill(isp + 2, isp + mn, true);
  for (int i = 2; i < mn; i++) {
    if (!isp[i]) continue;
    ps.push_back(i);
    chp[i].push_back(i);
    for (int j = 2 * i; j < mn; j += i) {
      isp[j] = false;
      chp[j].push_back(i);
    }
  }
}
void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> trans(mn);
  for (int i = 0; i < ps.size(); i++) trans[ps[i]] = i;
  uf u(ps.size());
  for (int i = 0; i < n; i++) {
    int pre = -1;
    for (int j = 0; j < chp[a[i]].size(); j++) {
      int id = trans[chp[a[i]][j]];
      if (pre >= 0) {
        u.unite(id, pre);
      }
      pre = id;
    }
  }
  vector<unordered_map<int, int>> mp(ps.size());
  for (int i = 0; i < n; i++) {
    vector<int> ids;
    ids.push_back(u.find(trans[chp[a[i]][0]]));
    for (int p : chp[a[i] + 1]) {
      int id = trans[p];
      id = u.find(id);
      ids.push_back(id);
    }
    for (int j = 0; j < ids.size(); j++)
      for (int k = j + 1; k < ids.size(); k++) {
        int a = ids[j];
        int b = ids[k];
        if (a == b) continue;
        if (a > b) swap(a, b);
        mp[a][b] = true;
      }
  }
  for (int i = 0; i < q; i++) {
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    s = trans[chp[a[s]][0]];
    t = trans[chp[a[t]][0]];
    s = u.find(s);
    t = u.find(t);
    if (s == t) {
      cout << 0 << "\n";
    } else {
      if (s > t) swap(s, t);
      if (mp[s][t]) {
        cout << 1 << "\n";
      } else {
        cout << 2 << "\n";
      }
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  solve();
  return 0;
}
