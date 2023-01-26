#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char s[2010][2010];
int a[2010][2010], b[4000010], c;
vector<int> w[8000010], q[8000010];
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
      a[i][j] = -1;
      if (s[i][j] == '1') {
        a[i][j] = c;
        b[c++] = i << 14 | j;
        q[0].push_back(i << 14 | j);
      }
    }
  }
  for (int i = 0; i <= 2000; i++) {
    for (int j = 0; j <= 2000; j++) {
      w[i * i + j * j].push_back(i << 14 | j);
    }
  }
  for (int i = 0; i <= 8000000; i++) {
    if (!w[i].size()) continue;
    for (int j = 0; j < q[i].size(); j++) {
      int p = q[i][j];
      int x = p >> 14, y = p & ma, t = a[x][y];
      int cx = b[t] >> 14, cy = b[t] & ma;
      if (i != sq(x - cx, y - cy)) continue;
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
          if (a[nx][ny] == -1) {
            q[sq(cx - nx, cy - ny)].push_back(nx << 14 | ny);
            a[nx][ny] = t;
          } else {
            int u = a[nx][ny], ux = b[u] >> 14, uy = b[u] & ma;
            if (sq(cx - nx, cy - ny) < sq(ux - nx, uy - ny)) {
              q[sq(cx - nx, cy - ny)].push_back(nx << 14 | ny);
              a[nx][ny] = t;
            }
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int t = a[i][j], cx = b[t] >> 14, cy = b[t] & ma;
      ans += sq(cx - i, cy - j);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
