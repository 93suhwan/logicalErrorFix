#include <bits/stdc++.h>
using namespace std;
int m = 1000000007;
void print_list(string list_name, list<int> lst);
class UnionFind {
 public:
  vector<int> parent;
  vector<int> rank;
  UnionFind(int n) {
    parent = vector<int>(n);
    rank = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  int find(int x) {
    if (x != parent[x]) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }
  void do_union(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
      if (rank[u] > rank[v]) {
        parent[v] = u;
      } else if (rank[u] < rank[v]) {
        parent[u] = v;
      } else {
        parent[v] = u;
        rank[u] += 1;
      }
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  UnionFind dsds1(n + 1);
  UnionFind dsds2(n + 1);
  for (int i = 0; i < m1; i++) {
    int u, v;
    cin >> u >> v;
    dsds1.do_union(u, v);
  }
  for (int i = 0; i < m2; i++) {
    int u, v;
    cin >> u >> v;
    dsds2.do_union(u, v);
  }
  vector<pair<int, int>> added_edges;
  int added = 0;
  for (int u = 1; u < n; u++) {
    for (int v = (u + 1); v <= n; v++) {
      if (dsds1.find(u) != dsds1.find(v) && dsds2.find(u) != dsds2.find(v)) {
        added_edges.push_back({u, v});
        dsds1.do_union(u, v);
        dsds2.do_union(u, v);
        added += 1;
      }
    }
  }
  cout << added << endl;
  for (pair<int, int>& p : added_edges) {
    cout << p.first << " " << p.second << endl;
  }
  return 0;
}
void print_list(string list_name, list<int> lst) {
  cout << list_name << " ";
  for (int e : lst) {
    cout << e << ", ";
  }
  cout << endl;
}
