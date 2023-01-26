#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    char mat[n][m];
    int xl = 0, yl = 0;
    bool used[n][m] = {};
        queue<pair<int,int>> q;
    bool ok[n][m] = {};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> mat[i][j];
        if (mat[i][j] == 'L') {
          yl = i;
          xl = j;
          used[i][j] = true;
          q.push({yl, xl});
        }
      }
    }
    

    while (!q.empty()) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();
      
      int dx[4] = {-1, 0, 0, 1};
      int dy[4] = {0, -1, 1, 0};
      
      int ct = 0;
      for (int i = 0; i < 4; ++i) {
        int tx = x+dx[i];
        int ty = y+dy[i];
        if (tx >= 0 && tx < m && ty >= 0 && ty < n) {
          if (mat[ty][tx] == '.' && !ok[ty][tx]) {
            ++ct;
          }
        }
      }
      if (ct <= 1 || x == xl && y == yl) {
        ok[y][x] = true;
        for (int i = 0; i < 4; ++i) {
          int tx = x+dx[i];
          int ty = y+dy[i];
          if (tx >= 0 && tx < m && ty >= 0 && ty < n && !used[ty][tx] && mat[ty][tx] == '.') {
            used[ty][tx] = true;
            q.push({ty, tx});
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i == yl && j == xl || !ok[i][j]) {
          cout << mat[i][j];
        }
        else {
          cout << '+';
        }
      }
      cout << endl;
    }
  }
}