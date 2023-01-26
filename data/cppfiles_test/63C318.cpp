#include <bits/stdc++.h>
using namespace std;
typedef struct DSU {
  int n;
  vector<long long int> par, sz;
  DSU(int n) {
    this->n = n;
    par.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; i++) {
      par[i] = i;
      sz[i] = 1;
    }
  };
  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
  };
  int unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return x;
    if (sz[x] > sz[y]) {
      sz[x] += sz[y];
      par[y] = x;
    } else {
      sz[y] += sz[x];
      par[x] = y;
      x = y;
    }
    return x;
  }
} DSU;
void dfs(vector<vector<int>> &a, vector<bool> &vis, int root,
         vector<int> &list) {
  vis[root] = true;
  list.push_back(root);
  for (auto v : a[root]) {
    if (vis[v]) continue;
    dfs(a, vis, v, list);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  DSU dsu1(n), dsu2(n);
  vector<vector<int>> a1(n), a2(n);
  for (int i = 0; i < m1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    a1[u].push_back(v);
    a1[v].push_back(u);
  }
  for (int i = 0; i < m2; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    a2[u].push_back(v);
    a2[v].push_back(u);
  }
  vector<bool> vis1(n, false), vis2(n, false);
  for (int i = 0; i < n; i++) {
    if (!vis1[i]) {
      vector<int> temp;
      dfs(a1, vis1, i, temp);
      int length = temp.size();
      for (int j = 0; j < length - 1; j++) {
        dsu1.unite(temp[j], temp[j + 1]);
      }
    }
    if (!vis2[i]) {
      vector<int> temp;
      dfs(a2, vis2, i, temp);
      int length = temp.size();
      for (int j = 0; j < length - 1; j++) {
        dsu2.unite(temp[j], temp[j + 1]);
      }
    }
  }
  int ans = 0;
  vector<pair<int, int>> output;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (dsu1.find(i) == dsu1.find(j) || dsu2.find(i) == dsu2.find(j))
        continue;
      ans++;
      output.push_back({i + 1, j + 1});
      dsu1.unite(i, j);
      dsu2.unite(i, j);
    }
  }
  cout << ans << '\n';
  for (auto edge : output) {
    cout << edge.first << ' ' << edge.second << '\n';
  }
}
