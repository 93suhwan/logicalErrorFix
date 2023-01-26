#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> parent1, parent2;
vector<pair<int, int>> ans;
int find(int v, vector<int> &parent) {
  if (parent[v] == v) return v;
  return parent[v] = find(parent[v], parent);
}
void unite(int x, int y, vector<int> &parent) {
  x = find(x, parent);
  y = find(y, parent);
  if (x != y) {
    parent[x] = y;
  }
}
int main() {
  int m1, m2;
  cin >> n >> m1 >> m2;
  parent1.resize(n + 1);
  parent2.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    parent1[i] = parent2[i] = i;
  }
  for (int i = 0; i < m1; i++) {
    int a, b;
    cin >> a >> b;
    unite(a, b, parent1);
  }
  for (int i = 0; i < m2; i++) {
    int a, b;
    cin >> a >> b;
    unite(a, b, parent2);
  }
  if (m1 == n - 1 || m2 == n - 1) {
    cout << 0 << endl;
    exit(0);
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = i + 1; j < n + 1; j++) {
      if (find(i, parent1) != find(j, parent1) &&
          find(i, parent2) != find(j, parent2)) {
        ans.push_back({i, j});
        unite(i, j, parent1);
        unite(i, j, parent2);
      }
    }
  }
  cout << ans.size() << endl;
  for (auto it : ans) {
    cout << it.first << " " << it.second << endl;
  }
  return 0;
}
