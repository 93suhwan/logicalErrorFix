#include <bits/stdc++.h>
using namespace std;
struct DSU {
  vector<int> parent, rank;
  DSU(int n) {
    parent.assign(n, -1);
    rank.resize(n, 0);
  }
  int find(int v) {
    if (parent[v] == -1) {
      return v;
    }
    return parent[v] = find(parent[v]);
  }
  void merge(int v, int u) {
    v = find(v);
    u = find(u);
    if (v == u) {
      return;
    }
    if (rank[v] > rank[u]) {
      swap(v, u);
    }
    parent[v] = u;
    if (rank[v] == rank[u]) {
      rank[u]++;
    }
  }
};
void solve() {
  int n;
  cin >> n;
  DSU dsu1(n), dsu2(n);
  int m1, m2;
  cin >> m1 >> m2;
  for (int i = 0; i < m1; i++) {
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    dsu1.merge(v, u);
  }
  for (int i = 0; i < m2; i++) {
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    dsu2.merge(v, u);
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (dsu1.find(i) != dsu1.find(j)) {
        if (dsu2.find(i) != dsu2.find(j)) {
          ans.push_back({i, j});
          dsu1.merge(i, j);
          dsu2.merge(i, j);
        }
      }
    }
  }
  cout << ans.size() << endl;
  for (auto i : ans) {
    cout << i.first + 1 << ' ' << i.second + 1 << endl;
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
