#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v1(1005), v2(1005);
int parent1[1005], parent2[1005];
void dfs(int u, int p, int ind) {
  if (ind == 1) {
    parent1[u] = parent1[p];
    for (auto it : v1[u]) {
      if (parent1[it] == 0) {
        dfs(it, u, ind);
      }
    }
  } else {
    parent2[u] = parent2[p];
    for (auto it : v2[u]) {
      if (parent2[it] == 0) {
        dfs(it, u, ind);
      }
    }
  }
}
int getParent(int u, int ind) {
  if (ind == 1) {
    int p = parent1[u];
    if (p == u) {
      return u;
    } else {
      return parent1[u] = getParent(parent1[p], ind);
    }
  } else {
    int p = parent2[u];
    if (p == u) {
      return u;
    } else {
      return parent2[u] = getParent(parent2[p], ind);
    }
  }
}
int main() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  for (int i = 0; i < m1; i++) {
    int u, v;
    cin >> u >> v;
    v1[u].push_back(v);
    v1[v].push_back(u);
  }
  for (int i = 0; i < m2; i++) {
    int u, v;
    cin >> u >> v;
    v2[u].push_back(v);
    v2[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (parent1[i] == 0) {
      parent1[i] = i;
      dfs(i, i, 1);
    }
    if (parent2[i] == 0) {
      parent2[i] = i;
      dfs(i, i, 2);
    }
  }
  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int p1 = getParent(i, 1), p2 = getParent(j, 1), p3 = getParent(i, 2),
          p4 = getParent(j, 2);
      if (p1 != p2 && p3 != p4) {
        ans.push_back({i, j});
        parent1[p2] = p1;
        parent2[p4] = p3;
      }
    }
  }
  cout << ans.size() << endl;
  for (auto it : ans) {
    cout << it.first << " " << it.second << endl;
  }
}
