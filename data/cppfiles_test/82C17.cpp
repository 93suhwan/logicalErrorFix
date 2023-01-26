#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
long long gcd(long long x, long long y) {
  x = abs(x), y = abs(y);
  if (x < y) swap(x, y);
  while (y) {
    long long r = x % y;
    x = y;
    y = r;
  }
  return x;
}
struct Seg2T {
 private:
  int sz;
  vector<int> node;
  const int init_c = mod;

 public:
  Seg2T(vector<int> v) {
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
  Seg2T(int n) {
    sz = 1;
    while (sz < n) sz *= 2;
    node.resize(2 * sz - 1, init_c);
  }
  int f(int a, int b) { return min(a, b); }
  void update(int k, int a) {
    k += sz - 1;
    node[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
    }
  }
  int query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = sz;
    if (r <= a || b <= l)
      return init_c;
    else if (a <= l && r <= b)
      return node[k];
    else {
      int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return f(vl, vr);
    }
  }
};
struct SegT {
 private:
  int n;
  vector<pair<long long, long long>> node;
  vector<long long> lazy;
  const pair<long long, long long> init_c = {0, 0};

 public:
  SegT(int sz) {
    n = 1;
    while (n < sz) n <<= 1;
    node.resize(2 * n - 1, {0, 0});
    lazy.resize(2 * n - 1, -1);
  }
  pair<long long, long long> f(pair<long long, long long> a,
                               pair<long long, long long> b) {
    pair<long long, long long> res;
    res.first = a.first + b.first;
    res.second = max(a.second, b.second);
    return res;
  }
  void eval(int k, int l, int r) {
    if (lazy[k] < 0) return;
    node[k] = {lazy[k] * (r - l), lazy[k]};
    if (r - l > 1) {
      lazy[2 * k + 1] = lazy[k];
      lazy[2 * k + 2] = lazy[k];
    }
    lazy[k] = -1;
  }
  void add(long long x, int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    eval(k, l, r);
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
      lazy[k] = x;
      eval(k, l, r);
    } else {
      add(x, a, b, k * 2 + 1, l, (l + r) / 2);
      add(x, a, b, k * 2 + 2, (l + r) / 2, r);
      node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
    }
  }
  void chmin(int le, int val) {
    int k = 0;
    int l = 0, r = n;
    while (k < n - 1) {
      eval(k, l, r);
      eval(2 * k + 1, l, (l + r) / 2);
      eval(2 * k + 2, (l + r) / 2, r);
      if (node[2 * k + 2].second > val) {
        k = 2 * k + 2;
        l = (l + r) / 2;
      } else {
        k = 2 * k + 1;
        r = (l + r) / 2;
      }
    }
    if (node[k].second <= val) k--;
    k -= n - 1;
    if (le + 1 <= k) {
      add(val, le + 1, k + 1);
    }
  }
  pair<long long, long long> query(int a, int b, int k = 0, int l = 0,
                                   int r = -1) {
    if (r < 0) r = n;
    eval(k, l, r);
    if (r <= a || b <= l) return init_c;
    if (a <= l && r <= b)
      return node[k];
    else {
      pair<long long, long long> vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      pair<long long, long long> vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return f(vl, vr);
    }
  }
  void update(int loc, long long x) {
    int k = 0, l = 0, r = n;
    stack<pair<int, int>> st;
    while (k < n - 1) {
      eval(k, l, r);
      st.push({l, r});
      if (loc < (l + r) / 2) {
        k = 2 * k + 1;
        r = (l + r) / 2;
      } else {
        k = 2 * k + 2;
        l = (l + r) / 2;
      }
    }
    eval(k, l, r);
    st.push({l, r});
    node[k] = {x, x};
    while (k > 0) {
      k = (k - 1) / 2;
      st.pop();
      l = st.top().first, r = st.top().second;
      eval(2 * k + 1, l, (l + r) / 2);
      eval(2 * k + 2, (l + r) / 2, r);
      node[k] = f(node[2 * k + 1], node[2 * k + 2]);
    }
  }
};
void solve() {
  int n, q, k;
  cin >> n >> q >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  Seg2T st(a);
  vector<vector<int>> qs(n);
  vector<int> l(q), r(q);
  for (int i = 0; i < q; i++) {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
    qs[l[i]].push_back(i);
  }
  vector<long long> ans(q);
  for (int cr = 0; cr < k; cr++) {
    vector<int> ids;
    for (int i = cr; i < n; i += k) {
      ids.push_back(i);
    }
    if (ids.empty()) continue;
    SegT t(ids.size());
    for (int j = (int)ids.size() - 1; j >= 0; j--) {
      int loc = ids[j];
      int ri = min(loc + k, n);
      int val = st.query(loc, ri);
      t.chmin(loc / k, val);
      t.update(loc / k, a[loc]);
      for (int id : qs[loc]) {
        int len = r[id] - l[id] + 1;
        len = (len + k - 1) / k;
        ans[id] = t.query(loc / k, loc / k + len).first;
      }
    }
  }
  for (int i = 0; i < q; i++) cout << ans[i] << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
