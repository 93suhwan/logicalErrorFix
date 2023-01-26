#include <bits/stdc++.h>
using namespace std;
int lowbit(int first) { return first & -first; }
const int N = 410;
int f[N][N];
int n, m;
int query(int x1, int y1, int x2, int y2, int q) {
  int res = f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];
  if (q == 0) res = (x2 - x1 + 1) * (y2 - y1 + 1) - res;
  return res;
}
void solve() {
  scanf("%d%d", &n, &m);
  getchar();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      c = getchar();
      f[i][j] = c - '0';
    }
    getchar();
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + f[i][j];
  int ans = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = i + 4; k <= n; k++) {
        for (int z = j + 3; z <= m; z++) {
          int res = query(i + 1, j, k - 1, j, 0) +
                    query(i, j + 1, i, z - 1, 0) +
                    query(k, j + 1, k, z - 1, 0) +
                    query(i + 1, j + 1, k - 1, z - 1, 1);
          if (res >= ans) break;
          ans = min(ans, res + query(i + 1, z, k - 1, z, 0));
        }
      }
    }
  }
  printf("%d\n", ans);
}
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
