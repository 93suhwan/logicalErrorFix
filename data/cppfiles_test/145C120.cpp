#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, INF = 2e9 + 5, NN = 100000;
struct bomb_t {
  int x, y, i;
};
int dfs(vector<vector<int>> &g, vector<int> &vis, vector<int> &t, int u) {
  if (vis[u]) return t[u];
  vis[u] = 1;
  for (auto v : g[u]) t[u] = min(t[u], dfs(g, vis, t, v));
  return t[u];
}
void solve() {
  int n, k;
  cin >> n >> k;
  bomb_t b[n];
  vector<vector<int>> g(n, vector<int>());
  vector<int> vis(n, 0), cc, t(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i].x >> b[i].y >> t[i];
    b[i].i = i;
  }
  sort(b, b + n, [&](const bomb_t a, const bomb_t b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
  });
  for (int i = 1; i < n; i++) {
    if (b[i].x == b[i - 1].x && b[i].y - b[i - 1].y <= k) {
      int u = b[i].i, v = b[i - 1].i;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  sort(b, b + n, [&](const bomb_t a, const bomb_t b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
  });
  for (int i = 1; i < n; i++) {
    if (b[i].y == b[i - 1].y && b[i].x - b[i - 1].x <= k) {
      int u = b[i].i, v = b[i - 1].i;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) cc.push_back(dfs(g, vis, t, i));
  }
  sort(cc.begin(), cc.end());
  int N = cc.size(), A = N - 1;
  for (int i = 0; i < N; i++) {
    A = min(A, max(cc[i], N - 2 - i));
  }
  cout << A;
}
int main() {
  int t = 1;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    solve();
    cout << endl;
  }
}
