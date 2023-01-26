#include <bits/stdc++.h>
using namespace std;
int n, m;
bool g[1000010];
inline int Hash(int x, int y) { return (x - 1) * m + y; }
queue<pair<int, int> > q;
bool ok[1000010];
const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
inline int getcount(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    int xx = x + dir[i][0], yy = y + dir[i][1];
    if (xx < 1 || xx > n || yy < 1 || yy > m)
      cnt++;
    else {
      int H = Hash(xx, yy);
      if (g[H] || ok[H]) cnt++;
    }
  }
  return cnt;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    int ex, ey, N = 0;
    char c;
    while (N < n * m) {
      while ((c = getchar()) != '.' && c != 'L' && c != '#')
        ;
      if (c == '#')
        g[++N] = true;
      else
        g[++N] = false;
      if (c == 'L') ex = (N - 1) / m + 1, ey = (N - 1) % m + 1;
      ok[N] = (c == 'L');
    }
    q.push({ex, ey});
    while (!q.empty()) {
      int x = q.front().first, y = q.front().second;
      q.pop();
      int cnt = 0;
      for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        int H = Hash(xx, yy);
        if (xx < 1 || xx > n || yy < 1 || yy > m || ok[H] || g[H]) continue;
        int cnt = getcount(xx, yy);
        if (cnt >= 3) {
          ok[H] = true;
          q.push({xx, yy});
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int H = Hash(i, j);
        if (i == ex && j == ey)
          putchar('L');
        else if (g[H])
          putchar('#');
        else if (ok[H])
          putchar('+');
        else
          putchar('.');
      }
      putchar('\n');
    }
  }
  return 0;
}
