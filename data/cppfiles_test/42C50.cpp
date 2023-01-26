#include <bits/stdc++.h>
using namespace std;
template <typename T>
int smin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
int smax(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}
mt19937_64 rng;
const int MX = 5e5 + 10;
const char nl = '\n';
template <int m>
struct ModInt {
  int v;
  static const int MOD = m;
  ModInt(long long val = 0) { v = (val % MOD + MOD) % MOD; }
  ModInt& operator+=(const ModInt& he) {
    v += he.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  ModInt& operator-=(const ModInt& he) {
    v -= he.v;
    if (v < 0) v += MOD;
    return *this;
  }
  ModInt& operator*=(const ModInt& he) {
    v = (long long)v * he.v % MOD;
    return *this;
  }
  friend ModInt pw(ModInt a, long long b) {
    ModInt r = 1;
    assert(b >= 0);
    while (b > 0) {
      if (b & 1) r *= a;
      a *= a;
      b >>= 1;
    }
    return r;
  }
  friend ModInt inv(ModInt a) { return pw(a, MOD - 2); }
  ModInt& operator/=(const ModInt& he) { return *this *= inv(he); }
  friend ModInt operator+(ModInt a, const ModInt& b) { return a += b; }
  friend ModInt operator-(ModInt a, const ModInt& b) { return a -= b; }
  friend ModInt operator*(ModInt a, const ModInt& b) { return a *= b; }
  friend ModInt operator/(ModInt a, const ModInt& b) { return a /= b; }
  friend ostream& operator<<(ostream& out, const ModInt& a) {
    return out << a.v;
  }
  friend bool operator==(const ModInt& a, const ModInt& b) {
    return a.v == b.v;
  }
  friend bool operator!=(const ModInt& a, const ModInt& b) { return !(a == b); }
};
template <typename T>
struct Fenwick {
  int n;
  vector<T> tree;
  Fenwick() {}
  Fenwick(int N) : n(N), tree(N + 1) {}
  void upd(int i, T x) {
    for (++i; i <= n; i += i & -i) tree[i] += x;
  }
  void addRange(int l, int r, T x) {
    upd(l, x);
    upd(r + 1, -1 * x);
  }
  T qry(int i) {
    T s = 0;
    for (++i; i > 0; i -= i & -i) s += tree[i];
    return s;
  }
  T sumRange(int l, int r) { return qry(r) - qry(l - 1); }
};
Fenwick<ModInt<1000000007>> tree(MX);
Fenwick<ModInt<1000000007>> tree_b(MX);
int n, a[MX], b[MX];
ModInt<1000000007> dp[MX];
void solve() {
  cin >> n;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      alive;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    --a[i];
    --b[i];
    alive.push({a[i], i});
  }
  int m;
  cin >> m;
  vector<int> need(m);
  set<pair<int, int>> todo;
  set<pair<int, int>> todo_a;
  for (int i = 0; i < m; i++) {
    cin >> need[i];
    --need[i];
    todo.insert({b[need[i]], need[i]});
    todo_a.insert({a[need[i]], need[i]});
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [](int i, int j) { return b[i] < b[j]; });
  for (int i : order) {
    dp[i] = 1 + tree.sumRange(a[i], b[i]);
    tree.upd(a[i], dp[i]);
    tree_b.upd(b[i], dp[i]);
  }
  ModInt<1000000007> ans = 0;
  while (((int)(todo.size()))) {
    auto [_, i] = *todo.rbegin();
    todo.erase(*todo.rbegin());
    todo_a.erase({a[i], i});
    ans += tree_b.qry(b[i] - 1) + 1;
    while (((int)(alive.size())) && alive.top().first < a[i]) {
      auto [__, j] = alive.top();
      alive.pop();
      tree_b.upd(b[j], -1 * dp[j]);
    }
    while (((int)(todo_a.size())) && todo_a.begin()->first < a[i]) {
      auto [__, j] = *todo_a.begin();
      todo_a.erase({a[j], j});
      todo.erase({b[j], j});
    }
  }
  cout << ans << nl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int te = 1;
  while (te--) {
    solve();
  }
  return 0;
}
