#include <bits/stdc++.h>
using namespace std;
int n;
bool adj[4][110] = {{false}}, checkArr[4][110];
bool BFS() {
  queue<pair<int, int>> bfsQ;
  bfsQ.push({1, 1});
  checkArr[1][1] = true;
  while (!bfsQ.empty()) {
    int x = bfsQ.front().first, y = bfsQ.front().second;
    bfsQ.pop();
    if (x == 2 && y == n) return true;
    for (int i = 0; i < 8; i++) {
      int nx, ny;
      switch (i) {
        case 0:
          nx = x + 1;
          ny = y;
          break;
        case 1:
          nx = x + 1;
          ny = y + 1;
          break;
        case 2:
          nx = x;
          ny = y + 1;
          break;
        case 3:
          nx = x - 1;
          ny = y + 1;
          break;
        case 4:
          nx = x - 1;
          ny = y;
          break;
        case 5:
          nx = x - 1;
          ny = y - 1;
          break;
        case 6:
          nx = x;
          ny = y - 1;
          break;
        case 7:
          nx = x + 1;
          ny = y - 1;
          break;
        default:
          break;
      }
      if (adj[nx][ny] && !checkArr[nx][ny]) {
        checkArr[nx][ny] = true;
        bfsQ.push({nx, ny});
      }
    }
  }
  return false;
}
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    fill(adj[1] + 1, adj[1] + 1 + n, false);
    fill(adj[2] + 1, adj[2] + 1 + n, false);
    fill(checkArr[1] + 1, checkArr[1] + 1 + n, false);
    fill(checkArr[2] + 1, checkArr[2] + 1 + n, false);
    for (int i = 1; i <= n; i++) {
      char x;
      cin >> x;
      if (x == '0')
        adj[1][i] = true;
      else
        adj[1][i] = false;
    }
    for (int i = 1; i <= n; i++) {
      char x;
      cin >> x;
      if (x == '0')
        adj[2][i] = true;
      else
        adj[2][i] = false;
    }
    if (BFS())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
