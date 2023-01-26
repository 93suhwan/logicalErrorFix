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
long long calc(int w) {
  int l = 0, r = n - w - k, best = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (f(mid - 1) > f(mid)) {
      best = mid, l = mid + 1;
    } else
      r = mid - 1;
  }
  if (best == -1) return f(0);
  return f(best);
}
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
  int l = 0;
  int r = 0;
  for (int i = 1; i <= tot && i <= k; i++) r += len[i];
  r -= k;
  cout << max(calc(l), calc(r)) << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
