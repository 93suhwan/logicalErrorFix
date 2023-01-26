#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char s[2010][2010];
int b[4000010], c;
vector<int> q[8000010], a[2010][2010];
inline int sq(int x, int y) { return x * x + y * y; }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int ma = (1 << 14) - 1;
  ++n;
  ++m;
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for (int j = 0; j < m; j++) {
      int z = i << 14 | j;
      if (s[i][j] == '1') {
        a[i][j].push_back(c);
        b[c++] = z;
        q[0].push_back(z);
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= 8000000; i++) {
    for (int j = 0; j < q[i].size(); j++) {
      int p = q[i][j];
      int x = p >> 14, y = p & ma, f = 0;
      for (int k = 0; k < a[x][y].size(); k++) {
        int t = a[x][y][k];
        int cx = b[t] >> 14, cy = b[t] & ma;
        if (i != sq(x - cx, y - cy)) continue;
        if (!f) {
          f = 1;
          ans += sq(cx - x, cy - y);
        }
        for (int l = 0; l < 4; l++) {
          int nx = x + dx[l], ny = y + dy[l];
          if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (a[nx][ny].empty()) {
              q[sq(cx - nx, cy - ny)].push_back(nx << 14 | ny);
              a[nx][ny].push_back(t);
            } else {
              int u = a[nx][ny][0], ux = b[u] >> 14, uy = b[u] & ma;
              if (sq(cx - nx, cy - ny) <= sq(ux - nx, uy - ny)) {
                if (sq(cx - nx, cy - ny) < sq(ux - nx, uy - ny)) {
                  q[sq(cx - nx, cy - ny)].push_back(nx << 14 | ny);
                  vector<int>().swap(a[nx][ny]);
                }
                int ff = 0;
                for (int z = 0; z < a[nx][ny].size(); z++) {
                  if (a[nx][ny][z] == t) ff = 1;
                }
                if (!ff) a[nx][ny].push_back(t);
              }
            }
          }
        }
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
