#include <bits/stdc++.h>
using namespace std;
class UnionFind {
 private:
  vector<int> p;
  vector<int> h;
  int c;

 public:
  UnionFind(int n) {
    p.resize(n);
    h.resize(n, 1);
    for (int i = 0; i < n; i++) p[i] = i;
    c = n;
  }
  int find(int e) {
    if (e == p[e]) return e;
    return (p[e] = find(p[e]));
  }
  bool check(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    return pu == pv;
  }
  bool join(int u, int v) {
    if (check(u, v)) {
      return false;
    }
    int pu = find(u);
    int pv = find(v);
    if (h[pu] < h[pv]) swap(pu, pv);
    if (h[pu] == h[pv]) h[pu]++;
    p[pv] = pu;
    c--;
    return true;
  }
  int count() { return c; }
};
void solve() {
  int n;
  cin >> n;
  int m1, m2;
  cin >> m1 >> m2;
  UnionFind uf1(n);
  UnionFind uf2(n);
  int u, v;
  for (int i = 0; i < m1; i++) {
    cin >> u >> v;
    uf1.join(--u, --v);
  }
  for (int i = 0; i < m2; i++) {
    cin >> u >> v;
    uf2.join(--u, --v);
  }
  vector<pair<int, int> > new_edges;
  for (u = 0; u < n; u++) {
    for (v = u + 1; v < n; v++) {
      if (!uf1.check(u, v) && !uf2.check(u, v)) {
        uf1.join(u, v);
        uf2.join(u, v);
        new_edges.push_back({u, v});
      }
    }
  }
  cout << new_edges.size() << endl;
  for (auto p : new_edges) {
    cout << p.first + 1 << " " << p.second + 1 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
