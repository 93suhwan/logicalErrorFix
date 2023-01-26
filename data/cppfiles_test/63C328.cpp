#include <bits/stdc++.h>
using namespace std;
class Forest {
 public:
  Forest(int size_, vector<vector<int>> edges_)
      : size(size_), edges(edges_), parents(size_ + 1, 0) {
    for (int i = 1; i <= size; i++) dfs(i, i);
  }
  void dfs(int i, int parent) {
    if (parents[i] != 0) return;
    parents[i] = parent;
    for (int j : edges[i]) dfs(j, parent);
  }
  int getParent(int a) {
    if (parents[a] == a) return parents[a];
    parents[a] = getParent(parents[a]);
    return parents[a];
  }
  void graphsUnion(int a, int b) { parents[getParent(a)] = getParent(b); }

 private:
  vector<vector<int>> edges;
  vector<int> parents;
  const int size;
};
vector<vector<int>> inputGraph(int size, int m1) {
  vector<vector<int>> res(size + 1);
  for (int i = 0; i < m1; i++) {
    int u, v;
    cin >> u >> v;
    res[u].push_back(v);
    res[v].push_back(u);
  }
  return res;
}
int main() {
  int size, m1, m2;
  cin >> size >> m1 >> m2;
  vector<vector<int>> edges1 = inputGraph(size, m1),
                      edges2 = inputGraph(size, m2);
  Forest mocha(size, edges1), diana(size, edges2);
  vector<pair<int, int>> ans;
  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= size; j++) {
      if (mocha.getParent(i) != mocha.getParent(j) &&
          diana.getParent(i) != diana.getParent(j)) {
        ans.push_back({i, j});
        mocha.graphsUnion(i, j);
        diana.graphsUnion(i, j);
      }
    }
  }
  cout << ans.size() << endl;
  for (auto [u, v] : ans) cout << u << " " << v << endl;
  return 0;
}
