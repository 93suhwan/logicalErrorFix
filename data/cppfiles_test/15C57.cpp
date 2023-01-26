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
Mint<> fact[MAX], inv[MAX];
vector<int> adj[MAX];
Mint<> dp[MAX][MAX];
inline Mint<> choose(int a, int b) {
  if (a < b) return 0;
  return fact[a] * inv[b] * inv[a - b];
}
inline void getLevel(int node, int par, int h, vector<int> &level) {
  level[h]++;
  for (int to : adj[node]) {
    if (to != par) getLevel(to, node, h + 1, level);
  }
}
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
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
  const auto get = [&](vector<int> nums) -> Mint<> {
    int sz = (int)nums.size();
    for (int i = 0; i <= sz; ++i) dp[i][0] = 1;
    for (int i = 1; i <= sz; ++i)
      for (int j = 1; j <= min(i, k); ++j)
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * nums[i - 1];
    return dp[sz][k];
  };
  Mint<> res = 0;
  for (int node = 1; node <= n; ++node) {
    if ((int)adj[node].size() < k) continue;
    vector<vector<int>> vec;
    for (int to : adj[node]) {
      vector<int> level(n, 0);
      getLevel(to, node, 0, level);
      vec.push_back(level);
    }
    for (int i = 0; i < n; ++i) {
      vector<int> tmp;
      for (int j = 0; j < (int)vec.size(); ++j) {
        if (vec[j][i]) tmp.push_back(vec[j][i]);
      }
      if ((int)tmp.size() >= k) res += get(tmp);
    }
  }
  cout << res << '\n';
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
