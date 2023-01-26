#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m, ' '));
    vector<int> lab;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] == 'L') lab = {i, j};
      }
    }
    vector<vector<int>> npths(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '.') {
          if (i - 1 >= 0 && a[i - 1][j] != '#') {
            npths[i][j]++;
          }
          if (j - 1 >= 0 && a[i][j - 1] != '#') {
            npths[i][j]++;
          }
          if (i + 1 < n && a[i + 1][j] != '#') {
            npths[i][j]++;
          }
          if (j + 1 < m && a[i][j + 1] != '#') {
            npths[i][j]++;
          }
        }
      }
    }
    queue<vector<int>> q;
    q.push(lab);
    while (!q.empty()) {
      auto v = q.front();
      q.pop();
      int i = v[0];
      int j = v[1];
      if (i - 1 >= 0 && a[i - 1][j] == '.') {
        npths[i - 1][j]--;
        if (npths[i - 1][j] <= 1) {
          a[i - 1][j] = '+';
          q.push({i - 1, j});
        }
      }
      if (j - 1 >= 0 && a[i][j - 1] == '.') {
        npths[i][j - 1]--;
        if (npths[i][j - 1] <= 1) {
          a[i][j - 1] = '+';
          q.push({i, j - 1});
        }
      }
      if (i + 1 < n && a[i + 1][j] == '.') {
        npths[i + 1][j]--;
        if (npths[i + 1][j] <= 1) {
          a[i + 1][j] = '+';
          q.push({i + 1, j});
        }
      }
      if (j + 1 < m && a[i][j + 1] == '.') {
        npths[i][j + 1]--;
        if (npths[i][j + 1] <= 1) {
          a[i][j + 1] = '+';
          q.push({i, j + 1});
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << a[i][j];
      cout << "\n";
    }
  }
}
