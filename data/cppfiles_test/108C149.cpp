#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
const int N = 1000005;
int n, m, t;
array<int, N> a, b, vis;
array<vector<int>, N> g;
vector<int> p, q;
void dfs(int u) {
  if (vis[u] != 0) {
    return;
  }
  vis[u] = 1;
  for (int v : g[u]) {
    dfs(v);
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> t;
  while ((t--) != 0) {
    cin >> n;
    p.clear();
    q.clear();
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
      p.push_back(i);
      q.push_back(i);
      g[i].clear();
      vis[i] = 0;
    }
    sort(p.begin(), p.end(), [](int x, int y) { return a[x] < a[y]; });
    sort(q.begin(), q.end(), [](int x, int y) { return b[x] < b[y]; });
    for (int i = 1; i < n; i++) {
      g[p[i - 1]].push_back(p[i]);
      g[q[i - 1]].push_back(q[i]);
    }
    dfs(p.back());
    for (int i = 1; i <= n; i++) {
      cout << vis[i];
    }
    cout << endl;
  }
  return 0;
}
