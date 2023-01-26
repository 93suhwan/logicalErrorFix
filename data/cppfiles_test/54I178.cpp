#include <bits/stdc++.h>
using namespace std;
class DSU {
  vector<int> parent;

 public:
  int size0, size1;
  DSU(int n) {
    parent.resize(n, -1);
    size0 = 0;
    size1 = 0;
  }
  int getParent(int a) {
    if (parent[a] == -1) return a;
    return parent[a] = getParent(parent[a]);
  }
  void merge(int a, int b) {
    if (a == 0)
      size0++;
    else
      size1++;
    parent[b] = a;
  }
};
void run() {
  int n, m, i, j;
  cin >> n >> m;
  DSU dsu(n + 2);
  bool bad = false;
  for (i = 0; i < m; i++) {
    int u, v;
    string s;
    cin >> u >> v >> s;
    ++u;
    ++v;
    bool same = (s == "crewmate");
    int pu = dsu.getParent(u);
    int pv = dsu.getParent(v);
    if (pu == u && pv == v) {
      dsu.merge(0, u);
      if (same)
        dsu.merge(0, v);
      else
        dsu.merge(1, v);
    } else if (pu == u) {
      if (same)
        dsu.merge(pv, u);
      else
        dsu.merge(1 - pv, u);
    } else if (pv == v) {
      if (same)
        dsu.merge(pu, v);
      else
        dsu.merge(1 - pu, v);
    } else {
      if ((pu == pv) != same) bad = true;
    }
  }
  if (bad) {
    cout << -1 << endl;
    return;
  }
  int size0 = dsu.size0, size1 = dsu.size1,
      remaining = max(0, n - size0 - size1);
  cout << remaining + max(size0, size1) << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  while (t--) run();
}
