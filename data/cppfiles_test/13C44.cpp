#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110, nextx[4] = {1, 0, -1, 0}, nexty[4] = {0, 1, 0, -1};
int T, n, m, k;
char state[MAXN][MAXN];
int valid(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }
void place(int x1, int y1, int x2, int y2) {
  for (long long i = (0); i <= (25); i++) {
    int flag = 1;
    for (long long k = (0); k <= (3); k++) {
      int x = x1 + nextx[k], y = y1 + nexty[k];
      if (valid(x, y) && state[x][y] == 'a' + i) flag = 0;
      x = x2 + nextx[k], y = y2 + nexty[k];
      if (valid(x, y) && state[x][y] == 'a' + i) flag = 0;
    }
    if (flag) {
      state[x1][y1] = state[x2][y2] = 'a' + i;
      break;
    }
  }
}
void construct(int x1, int y1, int x2, int y2, int k) {
  for (long long x = x1; x < x2; x += 2) {
    for (long long y = y1; y < y2; y += 2) {
      if (k) {
        place(x, y, x, y + 1);
        place(x + 1, y, x + 1, y + 1);
        k -= 2;
      } else {
        place(x, y, x + 1, y);
        place(x, y + 1, x + 1, y + 1);
      }
    }
  }
}
int main() {
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    memset(state, 0, sizeof state);
    if ((!(n & 1)) && (!(m & 1))) {
      if (k % 2)
        printf("NO\n");
      else {
        printf("YES\n");
        construct(1, 1, n, m, k);
        for (long long i = (1); i <= (n); i++) {
          for (long long j = (1); j <= (m); j++) printf("%c", state[i][j]);
          printf("\n");
        }
      }
    } else if ((!(n & 1)) && (m & 1)) {
      if (k * 2 <= n * m - n && (k % 2) == 0) {
        printf("YES\n");
        for (long long x = 1; x < n; x += 2) {
          place(x, m, x + 1, m);
          construct(1, 1, n, m - 1, k);
        }
        for (long long i = (1); i <= (n); i++) {
          for (long long j = (1); j <= (m); j++) printf("%c", state[i][j]);
          printf("\n");
        }
      } else
        printf("NO\n");
    } else {
      if (k >= m / 2 && (k - m / 2) % 2 == 0) {
        printf("YES\n");
        for (long long y = 1; y < m; y += 2) {
          place(1, y, 1, y + 1);
        }
        construct(2, 1, n, m, k - m / 2);
        for (long long i = (1); i <= (n); i++) {
          for (long long j = (1); j <= (m); j++) printf("%c", state[i][j]);
          printf("\n");
        }
      } else
        printf("NO\n");
    }
  }
  return 0;
}
