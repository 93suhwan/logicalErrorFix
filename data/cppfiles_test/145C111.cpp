#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, INF = 2e9 + 5, NN = 100000;
struct triplet {
  int f, s, i;
};
int cmp1(const triplet a, const triplet b) {
  return a.f < b.f || a.f == b.f && a.s < b.s;
}
int cmp2(const triplet a, const triplet b) {
  return a.s < b.s || a.s == b.s && a.f < b.f;
}
int dfs(vector<vector<int>> &g, vector<int> &vis, vector<int> &t, int u) {
  if (vis[u]) return t[u];
  vis[u] = 1;
  for (auto v : g[u]) t[u] = min(t[u], dfs(g, vis, t, v));
  return t[u];
}
void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  triplet b[n];
  vector<vector<int>> g(n, vector<int>());
  vector<int> vis(n, 0), cc, t(n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &b[i].f, &b[i].s, &t[i]);
    b[i].i = i;
  }
  sort(b, b + n, cmp1);
  for (int i = 1; i < n; i++) {
    if (b[i].f == b[i - 1].f && b[i].s - b[i - 1].s <= k) {
      int u = b[i].i, v = b[i - 1].i;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  sort(b, b + n, cmp2);
  for (int i = 1; i < n; i++) {
    if (b[i].s == b[i - 1].s && b[i].f - b[i - 1].f <= k) {
      int u = b[i].i, v = b[i - 1].i;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) cc.push_back(dfs(g, vis, t, i));
  }
  sort(cc.begin(), cc.end());
  int A = cc.size() - 1;
  for (int i = 0; i < cc.size(); i++)
    A = min(A, max(cc[i], (int)cc.size() - 2 - i));
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
