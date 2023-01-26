#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;
ld const PI = 4 * atan((ld)1);
constexpr int mod = 1e9 + 7;
constexpr int MAX = 107;
template <int MOD = mod>
struct Mint {
  int val;
  Mint() : val(0) {}
  Mint(int64_t _val) : val((int)(_val % MOD)) {
    if (val < 0) val += MOD;
  }
  Mint &operator+=(const Mint &rhs) {
    val += rhs.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  Mint &operator-=(const Mint &rhs) {
    val -= rhs.val;
    if (val < 0) val += MOD;
    return *this;
  }
  Mint &operator*=(const Mint &rhs) {
    val = (int)(1ll * val * rhs.val % MOD);
    return *this;
  }
  friend Mint fpow(Mint x, int64_t y) {
    Mint res = 1;
    for (; y > 0; y >>= 1, x *= x) {
      if (y & 1) res *= x;
    }
    return res;
  }
  friend Mint inverse(Mint x) { return fpow(x, MOD - 2); }
  Mint &operator/=(const Mint &rhs) { return *this *= inverse(rhs); }
  friend Mint operator+(Mint a, const Mint &b) { return a += b; }
  friend Mint operator-(Mint a, const Mint &b) { return a -= b; }
  friend Mint operator-(Mint a) { return 0 - a; }
  friend Mint operator*(Mint a, const Mint &b) { return a *= b; }
  friend Mint operator/(Mint a, const Mint &b) { return a /= b; }
  friend ostream &operator<<(ostream &os, const Mint &a) { return os << a.val; }
  friend bool operator==(const Mint &a, const Mint &b) {
    return a.val == b.val;
  }
  friend bool operator!=(const Mint &a, const Mint &b) {
    return a.val != b.val;
  }
};
int n, k;
int sz[MAX];
bool alive[MAX];
Mint<> fact[MAX], inv[MAX];
Mint<> res[MAX];
vector<int> adj[MAX];
vector<int> all[MAX];
inline Mint<> choose(int a, int b) {
  if (a < b) return 0;
  return fact[a] * inv[b] * inv[a - b];
}
inline void getLevel(int node, int par, int h, vector<int> &level) {
  level[h]++;
  for (int to : adj[node]) {
    if (to != par && alive[to]) getLevel(to, node, h + 1, level);
  }
}
inline void dfs(int node, int par) {
  all[node].push_back(node);
  for (int to : adj[node]) {
    if (to != par) {
      dfs(to, node);
      for (int x : all[to]) all[node].push_back(x);
      res[node] -= res[to];
    }
  }
  alive[node] = true;
  if ((int)all[node].size() < k) return;
  for (int cur : all[node]) {
    vector<int> level(n, 0);
    getLevel(cur, -1, 0, level);
    for (int x : level) res[node] += choose(x, k);
  }
}
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    res[i] = 0;
    alive[i] = true;
    adj[i].clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (k == 2) {
    cout << choose(n, 2) << '\n';
    return;
  }
  dfs(1, -1);
  cout << res[1] << '\n';
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  fact[0] = 1;
  for (int i = 1; i < MAX; ++i) fact[i] = i * fact[i - 1];
  inv[MAX - 1] = inverse(fact[MAX - 1]);
  for (int i = MAX - 2; i >= 0; --i) inv[i] = (i + 1) * inv[i + 1];
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
