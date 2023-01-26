#include <bits/stdc++.h>
using namespace std;
void shuruHoJaa() {
  int q;
  cin >> q;
  map<int, list<int>> cur;
  int siz = 0;
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x;
      cin >> x;
      cur[x].push_back(siz++);
    } else {
      int x, y;
      cin >> x >> y;
      if (cur.count(y) == 0) {
        cur[y] = cur[x];
      } else {
        cur[y].insert(cur[y].end(), cur[x].begin(), cur[x].end());
      }
      cur[x].clear();
    }
  }
  vector<int> res(siz);
  for (auto it : cur) {
    for (auto x : it.second) {
      res[x] = it.first;
    }
  }
  for (auto x : res) cout << x << " ";
  return;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  unsigned t = 1;
  for (unsigned i = 1; i <= t; i++) {
    shuruHoJaa();
    if (i != t) cout << endl;
  }
  cerr << (1000 * clock()) / CLOCKS_PER_SEC << "ms" << endl;
  return 0;
}
