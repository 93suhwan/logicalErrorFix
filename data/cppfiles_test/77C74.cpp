#include <bits/stdc++.h>
using namespace std;
bool uMat(int x, int y, int n, int m) {
  return x >= 0 && x < n && y >= 0 && y < m;
}
int main() {
  int n, m, tv;
  cin >> n >> m;
  int dir[4][2];
  dir[0][0] = -1;
  dir[0][1] = 0;
  dir[1][0] = 0;
  dir[1][1] = 1;
  dir[2][0] = 1;
  dir[2][1] = 0;
  dir[3][0] = 0;
  dir[3][1] = -1;
  queue<pair<int, int>> qp;
  pair<int, int> temp;
  vector<int> vi;
  int a[n][m];
  bool bio[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      bio[i][j] = false;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!bio[i][j]) {
        tv = 1;
        qp.push({i, j});
        bio[i][j] = true;
        while (!qp.empty()) {
          temp = qp.front();
          qp.pop();
          for (int d = 0; d < 4; d++) {
            int dc;
            dc = d < 2 ? -2 : 2;
            int x = temp.first + dir[d][0], y = temp.second + dir[d][1];
            if (!(a[temp.first][temp.second] & (1 << (3 - d))) && !bio[x][y] &&
                uMat(x, y, n, m) && !(a[x][y] & (1 << (3 - d + dc)))) {
              qp.push({x, y});
              bio[x][y] = true;
              tv++;
            }
          }
        }
        vi.push_back(tv);
      }
  sort(vi.begin(), vi.end());
  for (int i = vi.size() - 1; i >= 0; i--) cout << vi[i] << ' ';
  cout << endl;
  return 0;
}
