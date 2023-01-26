#include <bits/stdc++.h>
using namespace std;
const int md = 998244353, N = 1e5 + 5;
int T, n, ans[N], deg[N], head[N], cnt, d[N];
struct edge {
  int to, nxt;
} e[N * 2];
inline int pow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = (unsigned long long)a * a % md)
    if (b & 1) res = (unsigned long long)res * a % md;
  return res;
}
bool dfs(int u, int p, int t) {
  for (int i = head[u]; i; i = e[i].nxt)
    if (e[i].to != p) {
      if (!dfs(e[i].to, u, t)) return 0;
    }
  if ((d[u] - 1) % t == 0 && u != 1) return 1;
  if (d[u] % t == 0) {
    --d[p];
    return 1;
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> T; T--;) {
    cin >> n;
    for (int i = 1; i <= n; ++i) deg[i] = head[i] = ans[i] = 0;
    cnt = 0;
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      e[++cnt] = (edge){v, head[u]}, head[u] = cnt;
      e[++cnt] = (edge){u, head[v]}, head[v] = cnt;
      ++deg[u], ++deg[v];
    }
    ans[1] = pow(2, n - 1);
    for (int t = 2; t < n; ++t)
      if ((n - 1) % t == 0) {
        for (int i = 1; i <= n; ++i) d[i] = deg[i];
        ans[t] = dfs(1, 0, t);
        ans[1] = (ans[1] - ans[t] + md) % md;
      }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
  }
  return 0;
}
