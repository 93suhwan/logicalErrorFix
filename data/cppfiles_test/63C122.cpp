#include <bits/stdc++.h>
using namespace std;
struct dsu {
  vector<int> e;
  dsu(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return get(a) == get(b); }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool uni(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};
void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  dsu d1(n), d2(n);
  vector<vector<bool>> have(n + 1, vector<bool>(n + 1, false));
  for (int i = 0; i < m1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    have[u][v] = have[v][u] = true;
    d1.uni(u, v);
  }
  for (int i = 0; i < m2; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    have[u][v] = have[v][u] = true;
    d2.uni(u, v);
  }
  int ans = 0;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (have[i][j]) continue;
      if (d1.sameSet(i, j) || d2.sameSet(i, j)) continue;
      v.push_back({i + 1, j + 1});
      d1.uni(i, j);
      d2.uni(i, j);
    }
  }
  cout << (int)v.size() << "\n";
  for (auto x : v) {
    cout << x.first << " " << x.second << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
