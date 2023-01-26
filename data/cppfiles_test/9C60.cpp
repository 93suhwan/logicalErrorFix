#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct Comparator {
  bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
    if (lhs.first == rhs.first) return lhs.second < rhs.second;
    return lhs.first < rhs.first;
  }
  bool operator()(int a, int b) const { return a > b; }
};
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int> > grid(m, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[j][i];
    }
  }
  for (int i = 0; i < k; i++) {
    pair<int, int> current;
    cin >> current.first;
    current.second = 0;
    current.first--;
    while (current.second < n) {
      if (grid[current.first][current.second] == 1) {
        grid[current.first][current.second] = 2;
        current.first++;
      } else if (grid[current.first][current.second] == 3) {
        grid[current.first][current.second] = 2;
        current.first--;
      } else if (grid[current.first][current.second] == 2)
        current.second++;
    }
    cout << current.first + 1 << ' ';
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  solve();
  return 0;
}
