#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,tune=native")
template <typename T>
using Prior = std::priority_queue<T>;
template <typename T>
using prior = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using namespace std;
const long long md = 1e9 + 7;
inline long long mod(long long x) { return (x % md + md) % md; }
int n, k;
vector<vector<long long>> g;
int tra(int src, int dir, int step) {
  if (!step) return 1;
  int ret = 0;
  for (auto nbr : g[dir]) {
    if (nbr == src) continue;
    ret += tra(dir, nbr, step - 1);
  }
  return ret;
}
long long h(const vector<long long>& cef, int k) {
  const int m = cef.size();
  assert(m >= k);
  vector<vector<long long>> dp(m + 1, vector<long long>(k + 1));
  for (int i = 0; i <= m; ++i) dp[i][0] = 1;
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= min(i, k); ++j)
      dp[i][j] = mod(dp[i - 1][j] + mod(dp[i - 1][j - 1] * cef[i - 1]));
  return dp[m][k];
}
void solve() {
  cin >> n >> k;
  g = vector<vector<long long>>(n);
  for (auto [u, v] : vector<pair<long long, long long>>(n - 1)) {
    cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  };
  ;
  if (k == 2) return cout << (n * (n - 1LL) >> 1) << '\n', void();
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int m = g[i].size();
    for (int step = 1; step < n; ++step) {
      vector<long long> cnt;
      for (auto dir : g[i])
        if (int tmp = tra(i, dir, step - 1)) cnt.push_back(tmp);
      if (cnt.size() < k) continue;
      ans = mod(ans + h(cnt, k));
    }
  }
  return cout << ans << '\n', void();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  vector<long long> __(_);
  iota(begin(__), end(__), 1);
  for (auto i : __) {
    solve();
  }
  return 0;
}
