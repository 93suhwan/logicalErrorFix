#include <bits/stdc++.h>
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return x * f;
}
const int N = 1e6 + 5;
int n, m, qx, qy;
std::vector<char> c[N];
std::vector<int> vis[N], If[N];
int fx[5] = {0, 0, 1, -1};
int fy[5] = {1, -1, 0, 0};
struct Cell {
  int x, y;
};
std::queue<Cell> q;
int Get(int x, int y) { return x * (n - 1) + y; }
int ok(int x, int y) {
  if (!(x >= 1 && x <= n && y >= 1 && y <= m)) return 0;
  if (c[x][y] == '#') return 0;
  return 1;
}
int Check(int x, int y) {
  if (!(x >= 1 && x <= n && y >= 1 && y <= m)) return 0;
  int res = 0;
  for (int i = 0; i < 4; i++) {
    int tx = x + fx[i], ty = y + fy[i];
    if (ok(tx, ty)) res++;
  }
  if (res <= 2 && res)
    return 1;
  else
    return 0;
}
void Bfs() {
  q.push((Cell){qx, qy}), If[qx][qy] = 1;
  while (q.size()) {
    Cell p = q.front();
    int px = p.x, py = p.y;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int tx = px + fx[i], ty = py + fy[i];
      if (!(tx >= 1 && tx <= n && ty >= 1 && ty <= m)) continue;
      if ((!If[tx][ty]) && c[tx][ty] == '.') {
        if (Check(tx, ty)) vis[tx][ty] = 1, q.push((Cell){tx, ty});
        If[tx][ty] = 1;
      }
    }
  }
}
void Clear() {
  for (int i = 1; i <= n; i++) c[i].clear(), vis[i].clear(), If[i].clear();
}
int main() {
  int T = read();
  while (T--) {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
      c[i].push_back(' ');
      for (int j = 1; j <= m; j++) {
        char ch;
        std::cin >> ch;
        if (ch == 'L') qx = i, qy = j;
        c[i].push_back(ch);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= m; j++) vis[i].push_back(0), If[i].push_back(0);
    }
    Bfs();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (vis[i][j])
          printf("+");
        else
          std::cout << c[i][j];
      }
      printf("\n");
    }
    Clear();
  }
  return 0;
}
