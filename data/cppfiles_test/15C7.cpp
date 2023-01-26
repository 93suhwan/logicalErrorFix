#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<char>> given(n, vector<char>(m));
  vector<vector<char>> obtained(n, vector<char>(m, '.'));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> given[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (given[i][j] != '*') {
        continue;
      }
      int left = j, right = j, down = i;
      vector<pair<int, int>> mark;
      while (left >= 0 && down >= 0 && right < m && given[down][left] == '*' &&
             given[down][right] == '*') {
        mark.push_back({down, left});
        mark.push_back({down, right});
        left--;
        down--;
        right++;
      }
      if (mark.size() >= 2 * k + 2) {
        for (auto i : mark) {
          obtained[i.first][i.second] = '*';
        }
      }
    }
  }
  cout << (given == obtained ? "YES" : "NO") << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
