#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> g;
vector<long long> A, B, a, b;
set<int> active;
long long gain = 0;
bool dfs(int u, int pre, long long power) {
  active.insert(u);
  for (int v : g[u]) {
    if (v == pre) continue;
    if (power > a[v]) {
      if (active.count(v) || dfs(v, u, power + b[v])) {
        gain += b[v];
        a[v] = b[v] = 0;
        return true;
      }
    }
  }
  active.erase(u);
  return false;
}
bool check(long long power) {
  a = A;
  b = B;
  active.clear();
  active.insert(0);
  bool found = true;
  while (found) {
    found = false;
    gain = 0;
    set<int> old_active = active;
    for (int u : old_active) {
      for (int v : g[u]) {
        if (!old_active.count(v)) {
          if (power > a[v] && dfs(v, u, power + b[v])) {
            power += gain + b[v];
            found = true;
          }
        }
        if (found) break;
      }
      if (found) break;
    }
  }
  return ((int)(active).size()) == n;
}
void solve() {
  cin >> n >> m;
  g.clear();
  g.resize(n);
  A.assign(n, 0);
  B.assign(n, 0);
  for (int i = 1; i < n; ++i) cin >> A[i];
  for (int i = 1; i < n; ++i) cin >> B[i];
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long lo = 0, hi = 1e9 + 1;
  for (long long mid = (lo + hi); lo < hi; mid = (lo + hi) / 2) {
    if (check(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << lo << "\n";
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
