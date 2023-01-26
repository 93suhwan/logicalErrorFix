#include <bits/stdc++.h>
template <typename T>
bool chkmin(T &a, T b) {
  return (b < a) ? a = b, 1 : 0;
}
template <typename T>
bool chkmax(T &a, T b) {
  return (b > a) ? a = b, 1 : 0;
}
long long ksm(long long a, long long b) {
  if (b == 0) return 1;
  long long ns = ksm(a, b >> 1);
  ns = ns * ns % 998244353;
  if (b & 1) ns = ns * a % 998244353;
  return ns;
}
using namespace std;
const int maxn = 200005;
int t, n, m, err;
int dis[maxn], vis[maxn];
vector<pair<int, int> > g[maxn];
void dfs(int u) {
  if (err) return;
  for (auto i : g[u]) {
    int v = i.first, w = i.second;
    if (dis[v] == -1) {
      dis[v] = dis[u] ^ w;
      dfs(v);
    } else if (dis[v] != (dis[u] ^ w)) {
      err = 1;
      return;
    }
  }
}
void solve() {
  err = 0;
  vector<array<int, 3> > ed;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    dis[i] = -1;
  }
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    ed.push_back({u, v, w});
    if (w == -1) continue;
    w = __builtin_parity(w);
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  for (int i = 1; i <= n; i++) {
    if (dis[i] == -1) dis[i] = 0, dfs(i);
  }
  if (err) {
    puts("NO");
    return;
  }
  puts("YES");
  for (auto i : ed) {
    int u = i[0], v = i[1], w = i[2];
    if (w == -1) w = dis[u] ^ dis[v];
    printf("%d %d %d\n", u, v, w);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
