#include <bits/stdc++.h>
using namespace std;
constexpr long long mod = 998244353;
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
struct Seg2T {
 private:
  vector<int> node;
  int sz;
  vector<int> vy;
  const int init_c = -mod;

 public:
  int f(int a, int b) { return max(a, b); }
  void add(int y) { vy.push_back(y); }
  void complete() {
    sort(vy.begin(), vy.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    int n = vy.size();
    sz = 1;
    while (sz < n) sz *= 2;
    node.resize(2 * sz - 1, init_c);
  }
  void update(int k, int c) {
    k = lower_bound(vy.begin(), vy.end(), k) - vy.begin();
    k += sz - 1;
    node[k] = f(node[k], c);
    while (k > 0) {
      k = (k - 1) / 2;
      node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
    }
  }
  int query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return init_c;
    if (a <= l && r <= b)
      return node[k];
    else {
      long long vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      long long vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return f(vl, vr);
    }
  }
  int query(int a, int b) {
    a = lower_bound(vy.begin(), vy.end(), a) - vy.begin();
    b = lower_bound(vy.begin(), vy.end(), b) - vy.begin();
    return query(a, b, 0, 0, sz);
  }
};
struct SegT {
 private:
  int sz;
  vector<Seg2T> node;
  const int init_c = -mod;

 public:
  int f(int a, int b) { return max(a, b); }
  SegT(vector<pair<int, int> > v, int n) {
    sz = 1;
    while (sz < n) sz *= 2;
    node.resize(sz * 2 - 1);
    for (int i = 0; i < v.size(); i++) {
      int k = v[i].first, y = v[i].second;
      k += sz - 1;
      node[k].add(y);
      while (k > 0) {
        k = (k - 1) / 2;
        node[k].add(y);
      }
    }
    for (int i = 0; i < 2 * sz - 1; i++) node[i].complete();
  }
  void update(int x, int y, int c) {
    x += sz - 1;
    node[x].update(y, c);
    while (x) {
      x = (x - 1) / 2;
      node[x].update(y, c);
    }
  }
  int query(int a, int b, int x, int y, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = sz;
    if (r <= a || b <= l)
      return init_c;
    else if (a <= l && r <= b)
      return node[k].query(x, y);
    else {
      int vl = query(a, b, x, y, k * 2 + 1, l, (l + r) / 2);
      int vr = query(a, b, x, y, k * 2 + 2, (l + r) / 2, r);
      return f(vl, vr);
    }
  }
};
int a[1000][1000];
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> d(n);
  for (int i = 0; i < n; i++) d[i] = a[i] - i;
  vector<int> vd = d;
  sort((vd).begin(), (vd).end());
  vd.erase(unique((vd).begin(), (vd).end()), vd.end());
  for (int i = 0; i < n; i++)
    d[i] = lower_bound((vd).begin(), (vd).end(), d[i]) - vd.begin();
  vector<pair<int, int> > ori(n);
  for (int i = 0; i < n; i++) ori[i] = {i, d[i]};
  SegT st(ori, n);
  vector<pair<int, int> > vp;
  for (int i = 0; i < n; i++) vp.push_back({a[i], -i});
  sort((vp).begin(), (vp).end());
  for (pair<int, int> p : vp) {
    int id = -p.second;
    int val = st.query(0, id, d[id], vd.size());
    if (id + 1 >= a[id]) val = max(val, 0);
    val += 1;
    st.update(id, d[id], val);
  }
  int ans = 0;
  ans = max(ans, st.query(0, n, 0, vd.size()));
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
