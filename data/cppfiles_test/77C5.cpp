#include <bits/stdc++.h>
using namespace std;
int w[1005][1005][2];
void zhuan(int x, int y, int a) {
  for (int i = 1; i <= 4; i++) {
    int z = a % 2;
    if (z == 1 && i == 1) {
      w[x - 1][y - 1][1] = 1;
    }
    if (z == 1 && i == 2) {
      w[x][y - 1][0] = 1;
    }
    if (z == 1 && i == 3) {
      w[x - 1][y][1] = 1;
    }
    if (z == 1 && i == 4) {
      w[x - 1][y - 1][0] = 1;
    }
    a = a / 2;
  }
}
int biaoji[1005][1005];
int ans[1000005];
int sum;
void DFS(int x, int y) {
  biaoji[x][y] = 1;
  if (w[x - 1][y - 1][0] == 0 && biaoji[x - 1][y] == 0) {
    sum++;
    DFS(x - 1, y);
  }
  if (w[x][y - 1][0] == 0 && biaoji[x + 1][y] == 0) {
    sum++;
    DFS(x + 1, y);
  }
  if (w[x - 1][y - 1][1] == 0 && biaoji[x][y - 1] == 0) {
    sum++;
    DFS(x, y - 1);
  }
  if (w[x - 1][y][1] == 0 && biaoji[x][y + 1] == 0) {
    sum++;
    DFS(x, y + 1);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      zhuan(i, j, x);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (biaoji[i][j] == 1) continue;
      sum = 1;
      DFS(i, j);
      if (sum != 0) ans[++cnt] = sum;
    }
  }
  sort(ans + 1, ans + 1 + cnt);
  for (int i = cnt; i >= 1; i--) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
