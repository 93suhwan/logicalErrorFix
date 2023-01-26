#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
vector<vector<int>> flag;
int n, m, k;
int findFlag(int r, int c) {
  if (flag[r][c] == r || flag[r][c] == n) return flag[r][c];
  flag[r][c] = findFlag(flag[r][c], c);
  return flag[r][c];
}
int main() {
  cin >> n >> m >> k;
  grid = vector<vector<int>>(n, vector<int>(m, 0));
  flag = vector<vector<int>>(n, vector<int>(m, 0));
  vector<int> ball(k, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      flag[i][j] = i;
    }
  }
  for (int i = 0; i < k; i++) {
    cin >> ball[i];
    ball[i]--;
  }
  for (int i = 0; i < k; i++) {
    int rCur = 0;
    int cCur = ball[i];
    while (rCur != n) {
      if (grid[rCur][cCur] == 1) {
        grid[rCur][cCur] = 2;
        cCur++;
      } else if (grid[rCur][cCur] == 3) {
        grid[rCur][cCur] = 2;
        cCur--;
      } else {
        int rNew = findFlag(rCur, cCur);
        if (rCur == rNew) {
          flag[rCur][cCur] = rCur + 1;
          rCur++;
        } else
          rCur = rNew;
      }
    }
    cCur++;
    cout << cCur << endl;
  }
  return 0;
}
