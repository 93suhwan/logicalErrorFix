#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<set<int>> gr(n);
  for (int i = (0); i < int(m); i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    gr[x].insert(y);
    gr[y].insert(x);
  }
  int C = 1e5;
  for (int i = (0); i < int(C); i++) {
    set<int> chosen;
    while (chosen.size() != 5) {
      chosen.insert(rand() % n);
    }
    bool is_clique = true;
    for (int x : chosen) {
      for (int y : chosen) {
        if (x == y) continue;
        if (!gr[x].count(y)) {
          is_clique = false;
          break;
        }
      }
      if (!is_clique) break;
    }
    bool is_indep = true;
    for (int x : chosen) {
      for (int y : chosen) {
        if (x == y) continue;
        if (gr[x].count(y)) {
          is_indep = false;
          break;
        }
      }
      if (!is_indep) break;
    }
    if (is_clique || is_indep) {
      for (int x : chosen) {
        cout << x + 1 << ' ';
      }
      cout << '\n';
      return;
    }
  }
  cout << -1 << '\n';
}
int main() {
  srand(time(nullptr));
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  bool _multipleTestCases = false;
  if (_multipleTestCases) {
    long long t;
    cin >> t;
    while (t--) solve();
  } else {
    solve();
  }
  return 0;
}
