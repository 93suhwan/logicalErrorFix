#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
constexpr long long mod = 1000000007;
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
struct BIT {
 private:
  vector<int> node;
  int n;

 public:
  int f(int a, int b) { return a + b; }
  void init(int n_) {
    n = n_;
    node.resize(n, 0);
  }
  int query(int a) {
    int ret = 0;
    for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1) ret = f(ret, node[i]);
    return ret;
  }
  int query(int a, int b) { return query(b) - query(a); }
  void update(int a, int b) {
    for (int i = a; i < n; i |= i + 1) node[i] = f(node[i], b);
  }
};
struct BIT2 {
 private:
  vector<BIT> node;
  int sz;
  vector<vector<int>> vy;

 public:
  int f(int a, int b) { return a + b; }
  void init(int n) {
    sz = n;
    node.resize(n);
    vy.resize(n);
  }
  void add(int x, int y) {
    for (int i = x; i < sz; i |= i + 1) {
      vy[i].push_back(y);
    }
  }
  void complete() {
    for (int i = 0; i < sz; i++) {
      sort(vy[i].begin(), vy[i].end());
      vector<int> cop = vy[i];
      vy[i].erase(unique(vy[i].begin(), vy[i].end()), vy[i].end());
      int siz = vy[i].size();
      node[i].init(siz);
    }
  }
  int query(int x, int y) {
    int ret = 0;
    for (int i = x - 1; i >= 0; i = (i & (i + 1)) - 1) {
      int idy = lower_bound(vy[i].begin(), vy[i].end(), y) - vy[i].begin();
      ret = f(ret, node[i].query(idy));
    }
    return ret;
  }
  int query(int lx, int rx, int y) { return query(rx, y) - query(lx, y); }
  void update(int x, int y, int k) {
    for (int i = x; i < sz; i |= i + 1) {
      int idy = lower_bound(vy[i].begin(), vy[i].end(), y) - vy[i].begin();
      node[i].update(idy, k);
    }
  }
};
template <typename T>
struct SegT {
 private:
  int sz;
  vector<T> node;
  T init_c;
  function<T(T, T)> f;

 public:
  SegT(vector<T> v, T _init_c, function<T(T, T)> _f) {
    init_c = _init_c;
    f = _f;
    int n = v.size();
    sz = 1;
    while (sz < n) sz *= 2;
    node.resize(2 * sz - 1, init_c);
    for (int i = 0; i < n; i++) {
      node[i + sz - 1] = v[i];
    }
    for (int i = sz - 1 - 1; i >= 0; i--) {
      node[i] = f(node[2 * i + 1], node[2 * i + 2]);
    }
  }
  SegT(int n, T _init_c, function<T(T, T)> _f) {
    init_c = _init_c;
    f = _f;
    sz = 1;
    while (sz < n) sz *= 2;
    node.resize(2 * sz - 1, init_c);
  }
  void update(int k, T a) {
    k += sz - 1;
    node[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
    }
  }
  T query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = sz;
    if (r <= a || b <= l)
      return init_c;
    else if (a <= l && r <= b)
      return node[k];
    else {
      T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return f(vl, vr);
    }
  }
};
using ar = array<int, 3>;
vector<ar> mk(vector<int> a, int x) {
  vector<ar> res;
  vector<pair<int, int>> ori;
  for (int i = 0; i < a.size(); i++) ori.push_back({a[i], i});
  auto f = [&](pair<int, int> a, pair<int, int> b) { return max(a, b); };
  SegT<pair<int, int>> st(ori, {-mod, -1}, f);
  auto g = [&](int a, int b) { return min(a, b); };
  SegT<int> stmi(a, {mod}, g);
  function<void(int, int)> yaru = [&](int l, int r) {
    if (l >= r) return;
    pair<int, int> p = st.query(l, r);
    ar z;
    z[0] = stmi.query(l, r);
    z[1] = p.first;
    int mi = x + 1;
    if (l > 0) mi = min(mi, a[l - 1]);
    if (r < a.size()) mi = min(mi, a[r]);
    z[2] = mi;
    res.push_back(z);
    int id = p.second;
    yaru(l, id);
    yaru(id + 1, r);
  };
  yaru(0, a.size());
  return res;
}
void solve() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> b(m);
  for (int i = 0; i < m; i++) cin >> b[i];
  auto va = mk(a, x);
  auto vb = mk(b, x);
  vector<pair<int, int>> qa, qb;
  for (int i = 0; i < va.size(); i++) {
    qa.push_back({x - va[i][0], i});
  }
  for (int i = 0; i < vb.size(); i++) {
    qb.push_back({vb[i][2], i});
  }
  sort((qa).begin(), (qa).end(), greater<pair<int, int>>());
  sort((qb).begin(), (qb).end(), greater<pair<int, int>>());
  BIT2 bt;
  bt.init(1 << 19);
  for (int i = 0; i < vb.size(); i++) {
    bt.add(vb[i][0], vb[i][1]);
  }
  bt.complete();
  int loc = 0;
  long long ans = 0;
  for (int i = 0; i < qa.size(); i++) {
    while (loc < qb.size() && qb[loc].first > qa[i].first) {
      int id = qb[loc].second;
      loc++;
      bt.update(vb[id][0], vb[id][1], 1);
    }
    int id = qa[i].second;
    int l = x - va[id][2] + 1;
    if (l < 0) l = 0;
    int r = x - va[id][1] + 1;
    if (l < r) {
      int num = bt.query(l, r, x - va[id][0] + 1);
      ans += num;
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
