#include <bits/stdc++.h>
using namespace std;
struct dsu {
  vector<int> p;
  vector<int> depth;
  explicit dsu(int n) {
    p.resize(n);
    depth.resize(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
      depth[i] = 0;
    }
  }
  int get_p(int v) {
    if (p[v] == v) {
      return v;
    }
    return p[v] = get_p(p[v]);
  }
  void merge(int v1, int v2) {
    v1 = get_p(v1);
    v2 = get_p(v2);
    if (depth[v1] < depth[v2]) {
      swap(v1, v2);
    }
    p[v2] = v1;
  }
  bool same_set(int v1, int v2) { return get_p(v1) == get_p(v2); }
};
int main() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  auto dsu1 = dsu(n);
  auto dsu2 = dsu(n);
  for (int i = 0; i < m1; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    dsu1.merge(a, b);
  }
  for (int i = 0; i < m2; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    dsu2.merge(a, b);
  }
  vector<pair<int, int>> new_edges;
  for (int a = 0; a < n; ++a) {
    for (int b = 0; b < n; ++b) {
      if (!dsu1.same_set(a, b) && !dsu2.same_set(a, b)) {
        new_edges.emplace_back(a, b);
        dsu1.merge(a, b);
        dsu2.merge(a, b);
      }
    }
  }
  cout << new_edges.size() << endl;
  for (auto [a, b] : new_edges) {
    cout << a + 1 << " " << b + 1 << endl;
  }
}
