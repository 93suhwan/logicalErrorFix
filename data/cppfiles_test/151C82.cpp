#include <bits/stdc++.h>
using namespace std;
int inf = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  vector<vector<int>> p(1000000 + 13);
  int h = 0;
  for (int _ = 0; _ < t; _++) {
    int c;
    cin >> c;
    if (c == 1) {
      int x;
      cin >> x;
      p[x].push_back(h++);
    } else {
      int x, y;
      cin >> x >> y;
      if (x != y) {
        if (p[x].size() > p[y].size()) swap(p[x], p[y]);
        for (auto i : p[x]) p[y].push_back(i);
        p[x].clear();
      }
    }
  }
  vector<int> ans(h);
  for (int i = 0; i < p.size(); i++) {
    for (auto j : p[i]) {
      ans[j] = i;
    }
  }
  for (int i = 0; i < h; i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}
