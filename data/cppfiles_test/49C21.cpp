#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using std::cin;
using std::cout;
using std::endl;
using ll = long long;
using ld = long double;
ll ILL = 1167167167167167167;
const int INF = 2100000000;
const ll mod = 998244353;
template <class T>
using _pq = priority_queue<T, vector<T>, greater<T>>;
template <class T>
ll LB(vector<T> &v, T a) {
  return lower_bound(v.begin(), v.end(), a) - v.begin();
}
template <class T>
ll UB(vector<T> &v, T a) {
  return upper_bound(v.begin(), v.end(), a) - v.begin();
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  } else
    return 0;
}
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  } else
    return 0;
}
template <class T>
void So(vector<T> &v) {
  sort(v.begin(), v.end());
}
template <class T>
void Sore(vector<T> &v) {
  sort(v.begin(), v.end(), [](T x, T y) { return x > y; });
}
void yneos(bool a) {
  if (a)
    cout << "Yes\n";
  else
    cout << "No\n";
}
namespace atcoder {
namespace internal {
int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n)) x++;
  return x;
}
int bsf(unsigned int n) { return __builtin_ctz(n); }
}  // namespace internal
template <class S, S (*op)(S, S), S (*e)()>
struct segtree {
 public:
  segtree() : segtree(0) {}
  segtree(int n) : segtree(std::vector<S>(n, e())) {}
  segtree(const std::vector<S> &v) : _n(int(v.size())) {
    log = internal::ceil_pow2(_n);
    size = 1 << log;
    d = std::vector<S>(2 * size, e());
    for (int i = 0; i < _n; i++) d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }
  void set(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    d[p] = x;
    for (int i = 1; i <= log; i++) update(p >> i);
  }
  S get(int p) {
    assert(0 <= p && p < _n);
    return d[p + size];
  }
  S prod(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    S sml = e(), smr = e();
    l += size;
    r += size;
    while (l < r) {
      if (l & 1) sml = op(sml, d[l++]);
      if (r & 1) smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }
  S all_prod() { return d[1]; }
  template <bool (*f)(S)>
  int max_right(int l) {
    return max_right(l, [](S x) { return f(x); });
  }
  template <class F>
  int max_right(int l, F f) {
    assert(0 <= l && l <= _n);
    assert(f(e()));
    if (l == _n) return _n;
    l += size;
    S sm = e();
    do {
      while (l % 2 == 0) l >>= 1;
      if (!f(op(sm, d[l]))) {
        while (l < size) {
          l = (2 * l);
          if (f(op(sm, d[l]))) {
            sm = op(sm, d[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = op(sm, d[l]);
      l++;
    } while ((l & -l) != l);
    return _n;
  }
  template <bool (*f)(S)>
  int min_left(int r) {
    return min_left(r, [](S x) { return f(x); });
  }
  template <class F>
  int min_left(int r, F f) {
    assert(0 <= r && r <= _n);
    assert(f(e()));
    if (r == 0) return 0;
    r += size;
    S sm = e();
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!f(op(d[r], sm))) {
        while (r < size) {
          r = (2 * r + 1);
          if (f(op(d[r], sm))) {
            sm = op(d[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = op(d[r], sm);
    } while ((r & -r) != r);
    return 0;
  }

 private:
  int _n, size, log;
  std::vector<S> d;
  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};
}  // namespace atcoder
using namespace atcoder;
using F = int;
F op(F a, F b) { return a + b; }
F e() { return 0; }
int target;
bool f(F x) { return (x < target); }
void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  for (ll i = 0; i < t; i++) solve();
}
void solve() {
  int n, Q;
  cin >> n >> Q;
  vector<vector<int>> G(n);
  vector<int> p(n), c(n + 1);
  for (ll i = 0; i < n; i++) cin >> p[i];
  for (ll i = 0; i < n - 1; i++) {
    int a;
    cin >> a;
    a--;
    G[a].push_back(i + 1);
    G[i + 1].push_back(a);
  }
  vector<vector<tuple<int, int, int>>> q(n);
  for (ll i = 0; i < Q; i++) {
    int u, l, k;
    cin >> u >> l >> k;
    u--;
    q[u].push_back({i, l, k});
  }
  stack<int> s;
  vector<set<int>> A(n + 1);
  segtree<F, op, e> seg(n + 2);
  seg.set(n + 1, INF);
  s.push(0);
  vector<int> seen(n, 1), ans(Q);
  seen[0] = 0;
  while (!s.empty()) {
    int a = s.top();
    s.pop();
    if (a < n) {
      seg.set(c[p[a]], seg.get(c[p[a]]) - 1);
      A[c[p[a]]].erase(p[a]);
      c[p[a]]++;
      A[c[p[a]]].insert(p[a]);
      seg.set(c[p[a]], seg.get(c[p[a]]) + 1);
      s.push(a + n);
      for (auto x : G[a]) {
        if (seen[x]) {
          seen[x] = 0;
          s.push(x);
        }
      }
    } else {
      a -= n;
      for (auto x : q[a]) {
        int ind, l, k;
        tie(ind, l, k) = x;
        target = k;
        int b = seg.max_right<f>(l);
        if (b == n + 1)
          ans[ind] = -1;
        else
          ans[ind] = (*A[b].begin());
      }
      seg.set(c[p[a]], seg.get(c[p[a]]) - 1);
      A[c[p[a]]].erase(p[a]);
      c[p[a]]--;
      A[c[p[a]]].insert(p[a]);
      seg.set(c[p[a]], seg.get(c[p[a]]) + 1);
    }
  }
  for (ll i = 0; i < Q; i++) {
    if (i != 0) cout << " ";
    cout << ans[i];
  }
  cout << "\n";
}
