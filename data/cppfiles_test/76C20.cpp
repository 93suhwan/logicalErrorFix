#include <bits/stdc++.h>
using namespace std;
int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  n = min(n, 50);
  vector<vector<int> > g(n, vector<int>(n, 0));
  for (int i = 0; i < (int)(m); i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    if (a >= n || b >= n) continue;
    g[a][b] = g[b][a] = 1;
  }
  vector<int> res(5, -1);
  function<bool(int, int, int)> go = [&](int pos, int lvl, int edge_val) {
    if (n - pos < 5 - lvl) {
      return false;
    }
    if (lvl == 5) {
      return true;
    }
    for (; pos < n; pos++) {
      int ok = 1;
      for (int i = 0; i < lvl; i++) {
        if (g[res[i]][pos] != edge_val) {
          ok = 0;
          break;
        }
      }
      if (!ok) continue;
      res[lvl] = pos;
      if (go(pos + 1, lvl + 1, edge_val)) {
        return true;
      }
    }
    return false;
  };
  for (auto edge_val : vector<int>{0, 1}) {
    if (go(0, 0, edge_val)) {
      goto YES;
    }
  }
  cout << "-1\n";
  return 0;
YES : {
  for (auto x : res) {
    cout << x + 1 << ' ';
  }
  cout << endl;
}
  return 0;
}
