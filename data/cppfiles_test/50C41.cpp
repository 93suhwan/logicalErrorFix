#include <bits/stdc++.h>
using namespace std;
constexpr int log2(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
bool umin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool umax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
using ll = long long;
using ld = long double;
using str = string;
const int inf = (int)1e9 + 5;
const ll infl = (ll)1e18 + 5;
const int MOD = 998244353;
const int N = 2e5 + 10;
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char* x) { cout << '\"' << x << '\"'; }
void __print(const string& x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template <typename T, typename vector>
void __print(const pair<T, vector>& x) {
  cout << '{';
  __print(x.first);
  cout << ", ";
  __print(x.second);
  cout << '}';
}
template <typename T>
void __print(const T& x) {
  int first = 0;
  cout << '{';
  for (auto& i : x) cout << (first++ ? ", " : ""), __print(i);
  cout << "}";
}
void _print() { cout << "]\n"; }
template <typename T, typename... vector>
void _print(T t, vector... v) {
  __print(t);
  if (sizeof...(v)) cout << ", ";
  _print(v...);
}
struct F {
  ll inc = 0;
  bool neg = 0, isz = 0;
  F() {}
  F(ll x) { inc = x; }
  F& operator*=(const F& a) {
    if (a.isz) {
      inc = 0;
      neg = 0;
      isz = a.isz;
    }
    if (a.neg) {
      inc *= -1;
      neg ^= 1;
    }
    (inc += a.inc) %= MOD;
    return *this;
  }
};
struct T {
  ll x = 0, sum = 0;
  T() {}
  T(ll x) : x(x) {}
  friend T operator+(const T& a, const T& b) {
    T res;
    res.sum = (a.sum + b.sum) % MOD;
    res.x = a.x + b.x;
    return res;
  }
  T& operator*=(const F& a) {
    if (a.isz) {
      sum = 0;
    }
    if (a.neg) {
      sum *= -1;
    }
    (sum += x * a.inc) %= MOD;
    return *this;
  }
};
struct LazySeg {
  vector<F> lazy;
  vector<T> seg;
  int SZ = 1;
  void init(const vector<T>& _seg) {
    while (SZ < (int)(_seg).size()) SZ *= 2;
    seg.resize(2 * SZ);
    lazy.resize(2 * SZ);
    for (int i = 0; i < (SZ); ++i) seg[SZ + i] = _seg[i];
    for (int i = (SZ - 1); i > 0; --i) pull(i);
  }
  void push(int ind) {
    seg[ind] *= lazy[ind];
    if (ind < SZ)
      for (int i = 0; i < (2); ++i) lazy[2 * ind + i] *= lazy[ind];
    lazy[ind] = F();
  }
  void pull(int ind) { seg[ind] = seg[2 * ind] + seg[2 * ind + 1]; }
  void upd(int lo, int hi, F inc, int ind, int L, int R) {
    push(ind);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
      lazy[ind] = inc;
      push(ind);
      return;
    }
    int M = (L + R) / 2;
    upd(lo, hi, inc, 2 * ind, L, M);
    upd(lo, hi, inc, 2 * ind + 1, M + 1, R);
    pull(ind);
  }
  void upd(int lo, int hi, ll inc) { upd(lo, hi, {inc}, 1, 0, SZ - 1); }
  void upd(int lo, int hi, F inc) { upd(lo, hi, inc, 1, 0, SZ - 1); }
  T query(int lo, int hi, int ind, int L, int R) {
    push(ind);
    if (lo > R || L > hi) return T();
    if (lo <= L && R <= hi) return seg[ind];
    int M = (L + R) / 2;
    return query(lo, hi, 2 * ind, L, M) + query(lo, hi, 2 * ind + 1, M + 1, R);
  }
  T query(int lo, int hi) { return query(lo, hi, 1, 0, SZ - 1); }
};
LazySeg second;
vector<T> v(1 << 18);
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b;
  for (auto& x : a) cin >> x;
  b = a;
  sort((b).begin(), (b).end());
  b.erase(unique((b).begin(), (b).end()), b.end());
  auto ind = [&b](int x) {
    return (lower_bound((b).begin(), (b).end(), x) - b.begin());
  };
  for (int i = 0; i < ((int)(b).size()); ++i) {
    v[i].x = b[i] - (i ? b[i - 1] : 0);
  }
  second.init(v);
  for (int i = 0; i < (n); ++i) {
    int j = ind(a[i]);
    ll S = second.query(0, N).sum;
    if (i == 0) ++S;
    F t;
    t.isz = 1;
    second.upd(j + 1, N, t);
    t.isz = 0;
    t.neg = 1;
    second.upd(0, j, t);
    t.neg = 0;
    t.inc = S;
    second.upd(0, j, t);
  }
  ll ans = second.query(0, N).sum;
  ans = (ans % MOD + MOD) % MOD;
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
