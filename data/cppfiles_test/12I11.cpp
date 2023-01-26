#include <bits/stdc++.h>
using namespace std;
int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[8] = {0, -1, 0, 1, -1, 1, -1, 1};
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
      int x = p >> 14, y = p & ma, mind = 1 << 29;
      for (int k = 0; k < a[x][y].size(); k++) {
        int t = a[x][y][k];
        int cx = b[t] >> 14, cy = b[t] & ma;
        if (mind > sq(x - cx, y - cy)) {
          mind = sq(x - cx, y - cy);
        }
      }
      if (mind != i) continue;
      ans += i;
      for (int k = 0; k < a[x][y].size(); k++) {
        int t = a[x][y][k];
        int cx = b[t] >> 14, cy = b[t] & ma;
        if (i != sq(x - cx, y - cy)) continue;
        for (int l = 0; l < 8; l++) {
          int nx = x + dx[l], ny = y + dy[l];
          if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            mind = 1 << 29;
            for (int z = 0; z < a[nx][ny].size(); z++) {
              if (a[nx][ny][z] == t) {
                mind = -1;
              } else {
                int u = a[nx][ny][z], ux = b[u] >> 14, uy = b[u] & ma;
                if (mind > sq(ux - nx, uy - ny)) mind = sq(ux - nx, uy - ny);
              }
            }
            if (sq(cx - nx, cy - ny) < mind) {
              q[sq(cx - nx, cy - ny)].push_back(nx << 14 | ny);
              vector<int>().swap(a[nx][ny]);
            }
            if (sq(cx - nx, cy - ny) <= mind) {
              a[nx][ny].push_back(t);
            }
          }
        }
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
