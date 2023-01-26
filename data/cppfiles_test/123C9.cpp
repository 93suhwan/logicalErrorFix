#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, k;
int dep[N];
int len[N], tot = 0;
vector<int> son[N];
void dfs(int u, int fa) {
  int dson = -1;
  int deg = 0;
  for (int v : son[u])
    if (v != fa) {
      dfs(v, u), deg++;
      if (dson == -1 || dep[v] > dep[dson]) dson = v;
    }
  if (deg == 0) {
    dep[u] = 1;
    return;
  }
  for (int v : son[u])
    if (v != fa) {
      if (v != dson) {
        len[++tot] = dep[v];
      }
    }
  dep[u] = dep[dson] + 1;
  return;
}
long long f(int b) { return 1ll * (n - k - b) * (k - b); }
void solve() {
  tot = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) son[i].clear();
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    son[u].emplace_back(v), son[v].emplace_back(u);
  }
  dfs(1, 0);
  len[++tot] = dep[1];
  sort(len + 1, len + tot + 1, greater<int>());
  if (k >= tot) {
    long long ans = 0;
    for (int i = tot; i <= k; i++) ans = max(ans, 1ll * i * (n - i));
    cout << ans << endl;
  } else {
    int r = 0;
    for (int i = 1; i <= k; i++) r += len[i];
    r -= k;
    long long ans = f(0);
    for (int i = 1; i <= n - r - k; i++) ans = min(ans, f(i));
    cout << ans << endl;
  }
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
