#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int N = 1010;
int n, m, k, top;
int a[N][N], c[1000050], ans[1000050];
pair<int, int> nxt[N][N];
int vis[N][N];
vector<pair<int, int>> upd;
void push(int row, int col) {
  for (auto [x, y] : upd) {
    nxt[x][y] = {row, col};
  }
  upd.clear();
}
void go(int i, int j) {
  if (i < 0 || i > n || j < 0 || j >= m) return;
  if (i == n) {
    ans[top++] = j + 1;
    return;
  }
  if (nxt[i][j].first != -1) {
    a[i][j] = 2;
    tie(i, j) = nxt[i][j];
    go(i, j);
    return;
  }
  if (a[i][j] == 1) {
    a[i][j] = 2;
    go(i, j + 1);
    nxt[i][j] = nxt[i + 1][j];
  } else if (a[i][j] == 2) {
    a[i][j] = 2;
    go(i + 1, j);
    nxt[i][j] = nxt[i + 1][j];
  } else {
    a[i][j] = 2;
    go(i, j - 1);
    nxt[i][j] = nxt[i + 1][j];
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < k; i++) {
    scanf("%d", &c[i]);
    --c[i];
    int x = 0, y = c[i];
    while (x < n) {
      int ox = x, oy = y;
      if (a[x][y] == 1)
        y++;
      else if (a[x][y] == 2)
        x++;
      else
        y--;
      a[ox][oy] = 2;
    }
    printf("%d ", y + 1);
  }
}
