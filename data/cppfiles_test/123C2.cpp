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
ll val(ll r, ll b, ll n) { return (n - r - b) * (r - b); }
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
  ll r = 0, b = n, ans = -1e18;
  for (r = 1; r <= k; r++) {
    if (!active.empty()) {
      auto best = *active.begin();
      b += best[0];
      go(best[1], adjacency, size, active);
    }
    ll low = 0, high = b;
    while (low < high) {
      ll mid = (low + high) / 2;
      if (val(r, mid, n) > val(r, mid + 1, n)) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    if (low > (n + 1) / 2) {
      cout << n << " " << r << " " << low << endl;
      return;
    }
    ans = max(ans, val(r, low, n));
  }
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
