#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> A(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
    }
  }
  vector<vector<int>> T(n, vector<int>(m)), next23(n, vector<int>(m)),
      next12(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = m - 1; j >= 0; j--) {
      if (A[i][j] == 2 || A[i][j] == 3) {
        next23[i][j] = j;
      } else {
        if (j == m - 1) {
          next23[i][j] = m;
        } else {
          next23[i][j] = next23[i][j + 1];
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (A[i][j] == 1 || A[i][j] == 2) {
        next12[i][j] = j;
      } else {
        if (j == 0) {
          next12[i][j] = -1;
        } else {
          next12[i][j] = next12[i][j - 1];
        }
      }
    }
  }
  while (k--) {
    int c;
    cin >> c;
    c--;
    for (int i = 0; i < n; i++) {
      if (A[i][c] == 1) {
        int c0 = c;
        c = next23[i][c];
        bool lol = (A[i][c] == 3);
        for (int cc = c0; cc <= c; cc++) {
          next12[i][cc] = next23[i][cc] = cc;
          A[i][cc] = 2;
        }
        if (lol) {
          c--;
        }
      } else if (A[i][c] == 3) {
        int c0 = c;
        c = next12[i][c];
        bool lol = (A[i][c] == 1);
        for (int cc = c; cc <= c0; cc++) {
          next12[i][cc] = next23[i][cc] = cc;
          A[i][cc] = 2;
        }
        if (lol) {
          c++;
        }
      }
    }
    cout << c + 1 << '\n';
  }
}
