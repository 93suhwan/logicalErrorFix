#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 2e5 + 20;
vector<int> g[N];
int leaf[N], h[N], par[N];
bool used[N], marked[N];
bool dp[N];
int maxb = 0;
void dfs1(int v, int p) {
  par[v] = p;
  if (int((g[v]).size()) == 1 && v != 1) {
    h[v] = 0;
    leaf[v] = v;
    return;
  }
  for (auto u : g[v]) {
    if (u != p) {
      dfs1(u, v);
      if (h[u] + 1 > h[v]) h[v] = h[u] + 1, leaf[v] = leaf[u];
    }
  }
}
void dfs2(int v, int p) {
  dp[v] = !marked[v];
  for (auto u : g[v]) {
    if (u == p) continue;
    dfs2(u, v);
    if (!dp[u]) dp[v] = 0;
  }
  maxb += dp[v];
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs1(1, 0);
  int left = k;
  priority_queue<pair<int, int>> pq;
  pq.push({h[1], leaf[1]});
  while (!pq.empty() && left > 0) {
    auto [height, v] = pq.top();
    pq.pop();
    marked[v] = used[v] = 1, v = par[v];
    while (v && !used[v]) {
      used[v] = 1;
      for (auto u : g[v]) {
        if (u != par[v] && !used[u]) pq.push({h[u], leaf[u]});
      }
      v = par[v];
    }
    left--;
  }
  if (pq.empty()) {
    long long ans = 0;
    for (int i = k - left; i <= k; i++) {
      ans = max(ans, (n - i) * 1ll * i);
    }
    cout << ans << '\n';
    return 0;
  }
  dfs2(1, 0);
  long long ans = LLONG_MAX;
  for (int i = 0; i <= maxb; i++) {
    ans = min(ans, (n - k - i) * 1ll * (k - i));
  }
  cout << ans << '\n';
}
