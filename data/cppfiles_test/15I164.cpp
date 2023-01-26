#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> field(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        char c;
        cin >> c;
        if (c == '*') {
          field[i][j] = 1;
        }
      }
    }
    vector<vector<int>> copy(field);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!field[i][j]) continue;
        int count = 0;
        int offset = 1;
        while (true) {
          if (i - offset >= 0 && j - offset >= 0 && j + offset < m) {
            if (field[i - offset][j - offset] &&
                field[i - offset][j + offset]) {
              ++count;
              ++offset;
            } else {
              break;
            }
          } else if (count >= k) {
            copy[i][j] = 0;
            for (int a = 1; a < offset; ++a) {
              copy[i - a][j - a] = 0;
              copy[i - a][j + a] = 0;
            }
            break;
          } else {
            break;
          }
        }
      }
    }
    bool found = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (copy[i][j]) {
          cout << "NO" << '\n';
          found = true;
          break;
        }
      }
      if (found) {
        break;
      }
    }
    if (!found) {
      cout << "YES" << '\n';
    }
  }
}
