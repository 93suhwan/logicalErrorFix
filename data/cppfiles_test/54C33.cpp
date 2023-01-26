#include <bits/stdc++.h>
using namespace std;
class DSU {
  vector<int> parent;
  vector<int> count;

 public:
  DSU(int n) {
    parent.resize(n, -1);
    count.resize(n, 1);
  }
  int getParent(int a) {
    if (parent[a] == -1) return a;
    return parent[a] = getParent(parent[a]);
  }
  void merge(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) return;
    if (count[a] < count[b]) swap(a, b);
    parent[b] = a;
    count[b] += count[a];
  }
  bool same(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    return a == b;
  }
};
void run() {
  int n, m, i, j;
  cin >> n >> m;
  DSU dsu(n * 2);
  bool bad = false;
  for (i = 0; i < m; i++) {
    int u, v;
    string s;
    cin >> u >> v >> s;
    --u;
    --v;
    if (s == "crewmate") {
      dsu.merge(u, v);
      dsu.merge(u + n, v + n);
    } else {
      dsu.merge(u, v + n);
      dsu.merge(u + n, v);
    }
  }
  for (i = 0; i < n; i++) {
    if (dsu.same(i, i + n)) {
      cout << -1 << endl;
      return;
    }
  }
  map<int, int> mp;
  for (i = 0; i < n; i++) mp[dsu.getParent(i)]++;
  int ret = 0;
  for (i = 0; i < n; i++) {
    int p = dsu.getParent(i), pn = dsu.getParent(i + n);
    if (mp.count(p)) {
      ret += max(mp[p], mp[pn]);
      mp.erase(p);
      mp.erase(pn);
    }
  }
  cout << ret << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  while (t--) run();
}
