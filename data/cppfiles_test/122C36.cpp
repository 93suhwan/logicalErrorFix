#include <bits/stdc++.h>
using namespace std;
long long i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
long long c[200010], w, dist[200010];
bool vis[200010];
vector<array<long long, 2>> adj[200010], gr[200010];
void dfs(long long s) {
  vis[s] = true;
  for (auto [u, w] : adj[s]) {
    if (vis[u]) continue;
    if (w != -1) {
      w = __builtin_popcountll(w) % 2;
      gr[s].push_back({u, w});
      gr[u].push_back({s, w});
    }
    dist[u] = dist[s] + 1;
    dfs(u);
  }
}
void bip(long long s) {
  vis[s] = true;
  for (auto [u, w] : gr[s]) {
    if (vis[u] == true && c[u] != (c[s] ^ w)) {
      flag[0] = 0;
      break;
    }
    if (vis[u]) continue;
    c[u] = c[s] ^ w;
    bip(u);
  }
}
void fns(long long s) {
  vis[s] = true;
  for (auto &u : adj[s]) {
    if (vis[u[0]]) continue;
    if (u[1] == -1) u[1] = c[u[0]] ^ c[s];
    fns(u[0]);
  }
}
void rst() {
  long long i;
  flag[0] = 1;
  for (i = 1; i <= n; i++) {
    adj[i].clear();
    gr[i].clear();
    vis[i] = false;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    rst();
    for (i = 1; i <= n - 1; i++) {
      cin >> a >> b >> w;
      adj[a].push_back({b, w});
      adj[b].push_back({a, w});
    }
    for (i = 1; i <= m; i++) {
      cin >> a >> b >> w;
      gr[a].push_back({b, w});
      gr[b].push_back({a, w});
    }
    dfs(1);
    for (i = 1; i <= n; i++) vis[i] = false;
    for (i = 1; i <= n; i++) {
      if (vis[i]) continue;
      bip(i);
    }
    if (flag[0] == 0) {
      cout << "NO"
           << "\n";
      continue;
    }
    for (i = 1; i <= n; i++) vis[i] = false;
    fns(1);
    cout << "YES"
         << "\n";
    for (i = 1; i <= n; i++) {
      for (auto [u, w] : adj[i]) {
        if (dist[u] < dist[i]) continue;
        cout << i << ' ' << u << ' ' << w << "\n";
      }
    }
  }
  return 0;
}
