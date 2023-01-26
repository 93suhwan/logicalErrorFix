#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> parent1, parent2;
vector<int> rank1, rank2;
vector<pair<int, int>> ans;
int find(int v, vector<int> &parent) {
  if (parent[v] == v) return v;
  return parent[v] = find(parent[v], parent);
}
void unite(int x, int y, vector<int> &rank, vector<int> &parent) {
  x = find(x, parent);
  y = find(y, parent);
  if (x != y) {
    if (rank[x] < rank[y]) swap(x, y);
    parent[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
  }
}
int main() {
  int m1, m2;
  cin >> n >> m1 >> m2;
  parent1.resize(n + 1);
  parent2.resize(n + 1);
  rank1.resize(n + 1);
  rank2.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    parent1[i] = parent2[i] = i;
    rank1[i] = rank2[i] = 0;
  }
  for (int i = 0; i < m1; i++) {
    int a, b;
    cin >> a >> b;
    unite(a, b, rank1, parent1);
  }
  for (int i = 0; i < m2; i++) {
    int a, b;
    cin >> a >> b;
    unite(a, b, rank2, parent2);
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
        unite(i, j, rank1, parent1);
        unite(i, j, rank2, parent2);
      }
    }
  }
  cout << ans.size() << endl;
  for (auto it : ans) {
    cout << it.first << " " << it.second << endl;
  }
  return 0;
}
