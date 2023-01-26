#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int P = 998244353;
int T, n;
int ans[N];
vector<int> e[N];
int f[N];
bool dfs(int x, int fa, int y) {
  for (auto v : e[x])
    if (v != fa && !dfs(v, x, y)) return 0;
  if (f[x] % y == 0) {
    f[fa]--;
    return 1;
  }
  f[x]--;
  if (f[x] % y == 0) return 1;
  return 0;
}
vector<int> pri;
bool is[N];
int mu[N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> T;
  for (int i = 2; i < N; i++) {
    if (!is[i]) pri.push_back(i), mu[i] = -1;
    for (int j = 0; j < ((int)pri.size()) && i * pri[j] < N; j++) {
      is[i * pri[j]] = 1;
      mu[i * pri[j]] = i % pri[j] ? -mu[i] : 0;
      if (i % pri[j] == 0) break;
    }
  }
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
    }
    if (n == 2) {
      cout << 2 << " " << 0 << "\n";
    } else {
      int rt = 0;
      for (int i = 1; i <= n; i++)
        if (((int)e[i].size()) > 1) rt = i;
      for (int i = 1; i <= n; i++) ans[i] = 0;
      for (int i = 1; i * i <= (n - 1); i++) {
        if ((n - 1) % i) continue;
        for (int j = 1; j <= n; j++) f[j] = ((int)e[j].size());
        if (dfs(rt, 0, i)) ans[i] = 1;
        for (int j = 1; j <= n; j++) f[j] = ((int)e[j].size());
        if (dfs(rt, 0, (n - 1) / i)) ans[(n - 1) / i] = 1;
      }
      for (int i = 2; i <= n; i++) {
        for (int j = i + i; j <= n; j += i)
          ans[i] = (ans[i] + mu[j / i] * ans[j]);
        ans[i] = (ans[i] + P) % P;
      }
      for (int i = 1; i < n; i++) ans[1] = 2 * ans[1] % P;
      for (int i = 2; i <= n; i++) ans[1] = (ans[1] - ans[i] + P) % P;
      for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
    }
  }
  return 0;
}
