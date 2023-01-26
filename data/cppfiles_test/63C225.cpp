#include <bits/stdc++.h>
using namespace std;
int findParent(int node, vector<int>& parent) {
  if (node == parent[node]) {
    return node;
  }
  return parent[node] = findParent(parent[node], parent);
}
void unionNode(int u, int v, vector<int>& parent) {
  int uParent = findParent(u, parent);
  int vParent = findParent(v, parent);
  if (uParent != vParent) {
    parent[uParent] = vParent;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<int> parent1(n + 1), parent2(n + 1);
    for (int i = 1; i <= n; i++) {
      parent1[i] = i;
      parent2[i] = i;
    }
    int u, v;
    while (m1--) {
      cin >> u >> v;
      unionNode(u, v, parent1);
    }
    while (m2--) {
      cin >> u >> v;
      unionNode(u, v, parent2);
    }
    int res = 0;
    vector<pair<int, int>> edges;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) {
          continue;
        }
        if ((findParent(i, parent1) != findParent(j, parent1)) &&
            (findParent(i, parent2) != findParent(j, parent2))) {
          unionNode(i, j, parent1);
          unionNode(i, j, parent2);
          edges.emplace_back(i, j);
          res++;
        }
      }
    }
    cout << res << "\n";
    for (auto it : edges) {
      cout << it.first << " " << it.second << "\n";
    }
  }
}
