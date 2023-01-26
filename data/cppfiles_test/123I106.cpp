#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void build(int p, int u, vector<vector<int>> &adjacency, vector<int> &size,
           set<vector<int>> &active) {
  for (auto v : adjacency[u]) {
    if (v == p) {
      continue;
    }
    build(u, v, adjacency, size, active);
    size[u] = max(size[v], size[u]);
  }
  size[u]++;
  active.insert({-size[u], u});
  return;
}
void go(int u, vector<vector<int>> &adjacency, vector<int> &size,
        set<vector<int>> &active) {
  active.erase({-size[u], u});
  for (auto v : adjacency[u]) {
    if (size[v] == size[u] - 1) {
      go(v, adjacency, size, active);
      break;
    }
  }
  return;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> adjacency(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adjacency[u].push_back(v);
    adjacency[v].push_back(u);
  }
  vector<int> size(n);
  set<vector<int>> active;
  build(-1, 0, adjacency, size, active);
  int r = min(k, n / 2), b = n;
  for (int i = 0; i < r && !active.empty(); i++) {
    auto best = *active.begin();
    go(best[1], adjacency, size, active);
    b += best[0];
  }
  b = min(b, n / 2);
  b = min(b, n - r);
  ll ans = n - r - b;
  ans *= (r - b);
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
