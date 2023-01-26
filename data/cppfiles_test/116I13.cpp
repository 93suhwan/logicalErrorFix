#include <bits/stdc++.h>
const long long mod = 998244353;
const int N = 1000000 + 10;
int main() {
  std::ios::sync_with_stdio(false);
  std::cout.tie(0);
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int> > a(n);
  std::set<int> ban;
  for (int i = 0; i < n; i++) {
    int c, x;
    std::cin >> c;
    while (c--) {
      std::cin >> x;
      x--;
      a[i].emplace_back(x);
    }
    std::map<int, int> mp;
    for (auto x : a[i]) mp[x]++;
    for (auto p : mp)
      if (p.second >= 2) ban.insert(p.first);
  }
  std::vector<std::vector<int> > vec;
  for (int i = 0; i < n; i++) {
    bool ok = true;
    for (auto x : a[i])
      if (ban.count(x)) ok = false;
    if (ok) vec.emplace_back(a[i]);
  }
  for (auto v : vec)
    for (int i = 0; i < v.size(); i++)
      std::cout << v[i] << " \n"[i == (int)v.size() - 1];
  std::vector<std::set<int> > g(k), rg(k);
  for (auto v : vec) {
    for (int i = 0; i + 1 < v.size(); i++) {
      g[v[i]].insert(v[i + 1]);
      rg[v[i + 1]].insert(v[i]);
    }
  }
  std::vector<int> in(k, 0), out(k, 0);
  for (int i = 0; i < k; i++) {
    out[i] = g[i].size();
    in[i] = rg[i].size();
  }
  std::function<int(int)> dfs = [&](int x) {
    if (out[x] == 0) return 1;
    if (out[x] == 1 && in[*g[x].begin()] == 1) {
      return 1 + dfs(*g[x].begin());
    }
    return -1;
  };
  std::vector<int> F(k + 1, 0);
  for (int i = 0; i < k; i++)
    if (!ban.count(i)) {
      if (in[i] == 0) {
        F[dfs(i)]++;
      }
    }
  std::vector<std::pair<int, int> > key;
  for (int i = 0; i <= k; i++)
    if (F[i] > 0) {
      key.emplace_back(i, F[i]);
    }
  std::vector<int> dp(m + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= m; i++) {
    for (auto [len, w] : key) {
      if (len <= i) dp[i] = (dp[i] + 1ll * w * dp[i - len] % mod) % mod;
    }
  }
  std::cout << dp[m] << "\n";
}
