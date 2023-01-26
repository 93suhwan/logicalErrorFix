#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7, N = 2e5 + 10;
const ll M = 810;
template <typename T>
class SegTreeSum {
 public:
  vector<T> t, lazy, A;
  ll n;
  SegTreeSum(ll n) {
    this->n = n;
    this->t.assign(4 * n + 10, 0);
    this->lazy.assign(4 * n + 10, 0);
  }
  SegTreeSum(vector<T> a) : SegTreeSum(a.size()) {
    this->A = a;
    build(1, 0, n - 1);
  }
  void build(ll v, ll tl, ll tr) {
    if (tl == tr) {
      t[v] = A[tl];
      return;
    }
    ll tm = (tl + tr) / 2;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    t[v] = t[v << 1] + t[v << 1 | 1];
  }
  void push(ll v, ll tl, ll tr) {
    if (lazy[v]) {
      t[v] += (tr - tl + 1) * lazy[v];
      if (tl != tr) {
        lazy[v << 1] += lazy[v];
        lazy[v << 1 | 1] += lazy[v];
      }
      lazy[v] = 0;
    }
  }
  void update(ll v, ll tl, ll tr, ll l, ll r, T val) {
    push(v, tl, tr);
    if (tl > r or tr < l) return;
    if (tl >= l and tr <= r) {
      lazy[v] += val;
      push(v, tl, tr);
      return;
    }
    ll tm = (tl + tr) / 2;
    update(v << 1, tl, tm, l, r, val);
    update(v << 1 | 1, tm + 1, tr, l, r, val);
    t[v] = t[v << 1] + t[v << 1 | 1];
  }
  T query(ll v, ll tl, ll tr, ll l, ll r) {
    if (tr < l or tl > r) return 0;
    push(v, tl, tr);
    if (tl >= l and tr <= r) return t[v];
    ll tm = (tl + tr) / 2;
    return query(v << 1, tl, tm, l, r) + query(v << 1 | 1, tm + 1, tr, l, r);
  }
  T query(ll l, ll r) { return query(1, 0, n - 1, l, r); }
  T query(ll p) { return query(1, 0, n - 1, p, p); }
  void update(ll l, ll r, T val) { update(1, 0, n - 1, l, r, val); }
  void update(ll p, T val) { update(1, 0, n - 1, p, p, val); }
};
SegTreeSum<ll> st(N);
ll seg[M][M];
ll strt[N];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  cin >> n >> m;
  vector<array<ll, 2>> a(n);
  for (ll i = 0, x, y; i < n; ++i) {
    cin >> x >> y;
    a[i] = {x, y};
  }
  ll ans = 0;
  for (ll i = 0; i < m; ++i) {
    ll op, k;
    cin >> op >> k;
    --k;
    auto [x, y] = a[k];
    ll inc = (op == 1 ? 1 : -1);
    if (op == 1) {
      strt[k] = i;
    }
    ll s = x + y;
    if (x + y < M) {
      for (ll j = strt[k] + x; j < strt[k] + s; ++j) {
        seg[s][j % s] += inc;
      }
    } else {
      for (ll j = strt[k]; j < n; j += s) {
        if (j + x < n) {
          st.update(j + x, min(j + s - 1, n - 1), inc);
        }
      }
    }
    ll ans = st.query(i);
    for (ll j = 2; j < M; ++j) {
      ans += seg[j][i % j];
    }
    cout << ans << '\n';
  }
  return 0;
}
