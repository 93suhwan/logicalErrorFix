#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, INF = 2e9 + 5, NN = 100000;
struct bomb_t {
  int x, y, timer, i;
};
int dfs(bomb_t b[], vector<vector<int>> &g, vector<int> &vis, int u) {
  if (vis[u]) return b[u].timer;
  vis[u] = 1;
  for (auto v : g[u]) {
    b[u].timer = min(b[u].timer, dfs(b, g, vis, v));
  }
  return b[u].timer;
}
void solve() {
  int n, k;
  cin >> n >> k;
  bomb_t b[n];
  vector<vector<int>> g(n, vector<int>());
  vector<int> vis(n, 0), cc;
  for (int i = 0; i < n; i++) {
    bomb_t &t = b[i];
    cin >> t.x >> t.y >> t.timer;
    t.i = i;
  }
  sort(b, b + n, [&](const bomb_t a, const bomb_t b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
  });
  for (int i = 1; i < n; i++) {
    if (b[i].x == b[i - 1].x && b[i].y - b[i - 1].y <= k) {
      int u = b[i].i, v = b[i - 1].i;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  sort(b, b + n, [&](const bomb_t a, const bomb_t b) {
    return a.y < b.y || a.y == b.y && a.x < b.x;
  });
  for (int i = 1; i < n; i++) {
    if (b[i].y == b[i - 1].y && b[i].x - b[i - 1].x <= k) {
      int u = b[i].i, v = b[i - 1].i;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) cc.push_back(dfs(b, g, vis, i));
  }
  int A = min(cc[cc.size() - 1], (int)cc.size() - 1);
  sort(cc.begin(), cc.end());
  for (int i = 0; i < cc.size(); i++) {
    A = min(A, max(cc[i], (int)cc.size() - 2 - i));
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
