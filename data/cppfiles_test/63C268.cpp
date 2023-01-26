#include <bits/stdc++.h>
using namespace std;
class union_find {
 public:
  vector<int> par;
  vector<int> sz;
  union_find(int n) {
    par.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      par[i] = i;
      sz[i] = 1;
    }
  }
  int find(int n) {
    if (par[n] == n) return n;
    return par[n] = find(par[n]);
  }
  void unite(int u, int v) {
    int up = find(u);
    int vp = find(v);
    if (up == vp) return;
    if (sz[up] < sz[vp]) {
      par[up] = vp;
      sz[vp]++;
    } else {
      par[vp] = up;
      sz[up]++;
    }
  }
  int size(int x) { return sz[find(x)]; }
};
int main() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  union_find diana(n);
  union_find mocha(n);
  vector<pair<int, int>> res;
  for (int i = 1; i <= m1; i++) {
    int u, v;
    cin >> u >> v;
    mocha.unite(u, v);
  }
  for (int i = 1; i <= m2; i++) {
    int u, v;
    cin >> u >> v;
    diana.unite(u, v);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (not(diana.find(i) == diana.find(j)) &&
          not(mocha.find(i) == mocha.find(j))) {
        res.push_back({i, j});
        diana.unite(i, j);
        mocha.unite(i, j);
      }
    }
  }
  cout << res.size() << endl;
  for (auto it : res) {
    cout << it.first << " " << it.second << endl;
    ;
  }
  return 0;
}
