#include <bits/stdc++.h>
const int N = 1e5 + 5;
const int mod = 998244353;
int fp(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) r = r * 1ll * a % mod;
  return r;
}
std::set<int> adj[N];
std::set<int> tmp[N];
int n;
int ans[N];
void solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    tmp[i].clear();
    ans[i] = 0;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  std::set<int> vaild;
  for (int i = 1; i <= n; i++) vaild.insert((int)adj[i].size());
  for (auto it = vaild.rbegin(); it != vaild.rend() && *it != 1; it++) {
    int gcd = *it;
    bool skip = 0;
    for (int i = gcd; i <= n && !skip; i += gcd)
      if (ans[i]) skip = 1;
    if (skip) continue;
    std::set<int> ed;
    for (int i = 1; i <= n; i++) {
      if ((int)adj[i].size() == gcd) ed.insert(i);
      tmp[i] = adj[i];
    }
    auto erase = [&](int x) {
      ed.erase(x);
      for (auto y : tmp[x]) {
        tmp[y].erase(x);
        ed.erase(y);
        if ((int)tmp[y].size() == gcd) ed.insert(y);
      }
      tmp[x].clear();
    };
    while (!ed.empty()) {
      int x = *ed.begin();
      erase(x);
    }
    bool flag = 0;
    for (int i = 1; !flag && i <= n; i++)
      if (!tmp[i].empty()) flag = 1;
    if (!flag) ans[gcd] = 1;
  }
  ans[1] = fp(2, n - 1);
  for (int i = 2; i <= n; i++) ans[1] -= ans[i];
  ans[1] = (ans[1] + mod) % mod;
  for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
}
signed main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0), std::cout.tie(0);
  int T;
  std::cin >> T;
  while (T--) solve();
}
