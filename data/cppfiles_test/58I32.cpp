#include <bits/stdc++.h>
using namespace std;
const int MOD = 119 << 23 | 1;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int)1e9 + 23111992;
const long long LINF = (long long)1e18 + 23111992;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline unsigned long long isqrt(unsigned long long k) {
  unsigned long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() { return abs((int)mt()); }
inline int mrand(int k) { return abs((int)mt()) % k; }
template <typename num_t>
struct node_t {
  node_t *l, *r;
  int h, size, rev;
  num_t key, lz;
  node_t(num_t key, node_t* l = 0, node_t* r = 0, int h = rand())
      : key(key), l(0), r(0), h(h) {
    size = (l ? l->size : 0) + 1 + (r ? r->size : 0);
    rev = lz = 0;
  }
};
template <typename num_t>
int size(node_t<num_t>* x) {
  return x ? x->size : 0;
}
template <typename num_t>
void pull(node_t<num_t>* x) {
  x->size = size(x->l) + 1 + size(x->r);
}
template <typename num_t>
void push(node_t<num_t>* x) {
  node_t<num_t>* u = x->l;
  node_t<num_t>* v = x->r;
  if (x->rev) {
    if (u) swap(u->l, u->r), u->rev ^= 1;
    if (v) swap(v->l, v->r), v->rev ^= 1;
    x->rev = 0;
  }
  if (x->lz) {
    if (u) u->key += x->lz, u->lz += x->lz;
    if (v) v->key += x->lz, v->lz += x->lz;
    x->lz = 0;
  }
}
template <typename num_t>
node_t<num_t>* join(node_t<num_t>* x, node_t<num_t>* y) {
  if (!x) return y;
  if (!y) return x;
  if (x->h < y->h) {
    push(x);
    x->r = join(x->r, y);
    pull(x);
    return x;
  }
  push(y);
  y->l = join(x, y->l);
  pull(y);
  return y;
}
template <typename num_t>
void split(node_t<num_t>* x, node_t<num_t>*& l, node_t<num_t>*& r, int pos) {
  if (!x) {
    l = r = 0;
    return;
  }
  push(x);
  if (size(x->l) + 1 <= pos) {
    split(x->r, x->r, r, pos - size(x->l) - 1);
    pull(l = x);
  } else {
    split(x->l, l, x->l, pos);
    pull(r = x);
  }
}
template <typename num_t>
void split(node_t<num_t>* t, node_t<num_t>*& x, node_t<num_t>*& y,
           node_t<num_t>*& z, int l, int r) {
  split(t, x, y, l);
  split(y, y, z, r - l + 1);
}
template <typename num_t>
void reverse(node_t<num_t>*& x, int l, int r) {
  node_t<num_t>*y, *z;
  split(x, x, y, z, l, r);
  y->rev ^= 1;
  swap(y->l, y->r);
  x = join(x, join(y, z));
}
template <typename num_t>
void upd(node_t<num_t>*& x, int l, int r, num_t val) {
  node_t<num_t>*y, *z;
  split(x, x, y, z, l, r);
  y->lz += val;
  y->key += val;
  x = join(x, join(y, z));
}
template <typename num_t>
void split(node_t<num_t>* x, node_t<num_t>*& l, node_t<num_t>*& r,
           const function<bool(node_t<num_t>*)>& go_right) {
  if (!x) {
    l = r = 0;
    return;
  }
  push(x);
  if (go_right(x)) {
    split(x->r, x->r, r, go_right);
    pull(l = x);
  } else {
    split(x->l, l, x->l, go_right);
    pull(r = x);
  }
}
template <typename num_t>
void insert(node_t<num_t>*& x, num_t key) {
  node_t<num_t>* y;
  split<num_t>(x, x, y, [&](node_t<num_t>* x) { return x->key < key; });
  x = join(x, join(new node_t<num_t>(key), y));
}
template <typename num_t>
node_t<num_t>* erase(node_t<num_t>*& x, num_t key) {
  node_t<num_t>*l, *r, *res;
  split<num_t>(x, l, res, [&](node_t<num_t>* x) { return x->key < key; });
  split<num_t>(res, res, r, [&](node_t<num_t>* x) { return x->key <= key; });
  x = join(l, r);
  return res;
}
template <typename num_t>
void free(node_t<num_t>*& x) {
  if (!x) return;
  free(x->l);
  free(x->r);
  delete x;
  x = 0;
}
template <typename num_t>
int depth(node_t<num_t>* x) {
  if (!x) return 0;
  push(x);
  return 1 + max(depth(x->l), depth(x->r));
}
template <typename num_t>
void trace(node_t<num_t>* x, vector<int>& a, int isrt = 1) {
  if (!x) return;
  push(x);
  trace(x->l, a, 0);
  a.push_back(x->key);
  trace(x->r, a, 0);
}
void chemthan() {
  int C = 1e6 + 5;
  vector<int> fac(C, 1);
  for (int i = (1); i < (C); ++i) fac[i] = mult(fac[i - 1], i);
  vector<int> inv_fac(C);
  for (int i = (0); i < (C); ++i) inv_fac[i] = inv(fac[i]);
  auto binom = [&](int n, int k) {
    return mult(fac[n], mult(inv_fac[k], inv_fac[n - k]));
  };
  int test;
  cin >> test;
  while (test--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > v;
    vector<int> dc;
    for (int i = (0); i < (m); ++i) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      v.push_back({x, y});
      dc.push_back(x), dc.push_back(y);
      if (x) dc.push_back(x - 1);
      if (y + 1 < n) dc.push_back(y + 1);
    }
    dc.push_back(0), dc.push_back(n - 1);
    sort((dc).begin(), (dc).end()),
        (dc).erase(unique((dc).begin(), (dc).end()), (dc).end());
    int k = int((dc).size());
    vector<int> g(k, -1);
    for (int i = (0); i < (int((v).size())); ++i) {
      v[i].first =
          lower_bound((dc).begin(), (dc).end(), v[i].first) - dc.begin();
      v[i].second =
          lower_bound((dc).begin(), (dc).end(), v[i].second) - dc.begin();
      g[v[i].first] = v[i].second;
    }
    node_t<int>* rt = 0;
    rt = join(rt, new node_t<int>(0));
    vector<int> vv;
    for (int i = (1); i < (k); ++i) {
      if (g[i] != -1) {
        node_t<int>*x, *y, *z;
        split(rt, x, y, g[i]);
        split(y, y, z, 1);
        vv.push_back(y->key);
        y = join(y, z);
        rt = join(x, new node_t<int>(i));
        rt = join(rt, y);
      } else {
        rt = join(rt, new node_t<int>(i));
      }
    }
    vector<int> a;
    trace(rt, a);
    sort((vv).begin(), (vv).end()),
        (vv).erase(unique((vv).begin(), (vv).end()), (vv).end());
    int num = int((vv).size());
    if (num <= n - 1) {
      cout << binom(n - num - 1 + n, n) << "\n";
    } else {
      cout << 0 << "\n";
    }
  }
}
int32_t main(int32_t argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
