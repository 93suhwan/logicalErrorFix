#include <bits/stdc++.h>
using namespace std;
void inout();
void generate(vector<vector<char>>& mat, int rows, int cols, int h, int v) {
  for (int i = 0; i < rows && h > 0; i += 2) {
    int start = 0;
    for (int j = 0; j < cols && h > 0; j += 2) {
      if (j + 1 >= cols) continue;
      mat[i][j] = (char)(start + 97);
      mat[i][j + 1] = (char)(start + 97);
      start = (start + 1) % 2;
      mat[i + 1][j] = (char)(start + 97);
      mat[i + 1][j + 1] = (char)(start + 97);
      h -= 2;
    }
  }
  for (int j = 0; j < cols; j += 2) {
    int start = 0;
    for (int i = 0; i < rows; i += 2) {
      if (mat[i][j] == 'a' || mat[i][j] == 'b') {
        start = (start + 1) % 2;
        continue;
      }
      if (j + 1 >= cols) {
        mat[i][j] = (char)(start + 97 + 4);
        mat[i + 1][j] = (char)(start + 97 + 4);
        start = (start + 1) % 2;
      } else {
        mat[i][j] = (char)(start + 97 + 2);
        mat[i + 1][j] = (char)(start + 97 + 2);
        start = (start + 1) % 2;
        mat[i][j + 1] = (char)(start + 97 + 2);
        mat[i + 1][j + 1] = (char)(start + 97 + 2);
      }
    }
  }
}
void solve() {
  int n, m, k;
  bool flag = false;
  cin >> n >> m >> k;
  if (n % 2 == 0) {
    if (m % 2 == 0) {
      if (2 * k <= n * m && k % 2 == 0) flag = true;
    } else {
      if (2 * k <= n * (m - 1) && k % 2 == 0) flag = true;
    }
  } else {
    int k2 = (n * m) / 2 - k;
    if (2 * k2 <= m * (n - 1) && k2 % 2 == 0) flag = true;
  }
  if (flag) {
    cout << "YES\n";
    if (n % 2 == 0) {
      int k2 = (n * m) / 2 - k;
      vector<vector<char>> mat(n, vector<char>(m, 'x'));
      generate(mat, n, m, k, k2);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << mat[i][j];
        cout << endl;
      }
    } else {
      int k2 = (n * m) / 2 - k;
      vector<vector<char>> mat(m, vector<char>(n, 'x'));
      generate(mat, m, n, k2, k);
      for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) cout << mat[i][j];
        cout << endl;
      }
    }
  } else
    cout << "NO\n";
}
int main() {
  inout();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
void inout() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
