#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
constexpr long long mod = 1000000007;
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
const int max_n = 1 << 10;
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
const long double eps = 1e-8;
const long double pi = acosl(-1.0);
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
using mP = pair<modint, modint>;
int par[1 << 18][18];
void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> l(n), r(n);
  par[0][0] = -1;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
    if (l[i] >= 0) par[l[i]][0] = i;
    if (r[i] >= 0) par[r[i]][0] = i;
  }
  for (int j = 0; j < 17; j++) {
    for (int i = 0; i < n; i++) {
      if (par[i][j] < 0)
        par[i][j + 1] = -1;
      else
        par[i][j + 1] = par[par[i][j]][j];
    }
  }
  vector<int> ids;
  function<void(int)> dfs = [&](int id) {
    if (l[id] >= 0) dfs(l[id]);
    ids.push_back(id);
    if (r[id] >= 0) dfs(r[id]);
  };
  dfs(0);
  vector<bool> b(n);
  for (int i = 0; i < n; i++) {
    int le = i;
    while (i + 1 < n && s[ids[i]] == s[ids[i + 1]]) i++;
    if (i + 1 == n || s[ids[i + 1]] < s[ids[i]]) {
      for (int j = le; j <= i; j++) b[ids[j]] = true;
    }
  }
  vector<bool> used(n);
  string ans;
  function<void(int)> dfs3 = [&](int id) {
    if (l[id] >= 0) dfs3(l[id]);
    ans.push_back(s[id]);
    if (r[id] >= 0) dfs3(r[id]);
  };
  function<void(int)> dfs2 = [&](int id) {
    if (l[id] >= 0) dfs2(l[id]);
    if (!used[id]) {
      if (!b[id]) {
        int cur = id;
        int ad = 1;
        for (int j = 18 - 1; j >= 0; j--) {
          int p = par[cur][j];
          if (p >= 0 && !used[p]) {
            ad += (1 << j);
            cur = p;
          }
        }
        if (ad <= k) {
          k -= ad;
          cur = id;
          while (cur >= 0 && !used[cur]) {
            used[cur] = true;
            cur = par[cur][0];
          }
        }
      }
    }
    if (used[id]) {
      ans.push_back(s[id]);
      ans.push_back(s[id]);
      if (r[id] >= 0) dfs2(r[id]);
    } else {
      ans.push_back(s[id]);
      if (r[id] >= 0) dfs3(r[id]);
    }
  };
  dfs2(0);
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  solve();
  return 0;
}
