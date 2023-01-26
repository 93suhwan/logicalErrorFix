#include <bits/stdc++.h>
using namespace std;
const int maxn = 410;
int T, n, m, a[maxn][maxn], sum[maxn][maxn], f[maxn];
int getsum(int x1, int y1, int x2, int y2) {
  return sum[x1][y1] + sum[x2 - 1][y2 - 1] - sum[x2 - 1][y1] - sum[x1][y2 - 1];
}
int main() {
  cin >> T;
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) sum[i][j] = 0;
      f[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      string st;
      cin >> st;
      int t = 0;
      for (int j = 0; j < m; j++) {
        a[i][j + 1] = st[j] - '0';
        t += a[i][j + 1];
        sum[i][j + 1] = sum[i - 1][j + 1] + t;
      }
    }
    int ans = 999999;
    for (int l = 1; l <= m; l++) {
      for (int r = l + 3; r <= m; r++) {
        for (int h = 5; h <= n; h++) {
          f[h] = r - l - 1 - getsum(h, r - 1, h, l + 1) + h * 2 - 2 -
                 getsum(h - 1, l, 1, l) - getsum(h - 1, r, 1, r) +
                 getsum(h - 1, r - 1, 1, l + 1);
        }
        for (int i = n; i >= 6; i--) {
          if (f[i] < f[i - 1]) f[i - 1] = f[i];
        }
        for (int h = 5; h <= n; h++) {
          int now = 0;
          now =
              f[h] - getsum(h - 4, r - 1, 1, l + 1) -
              ((h - 4) * 2 - getsum(h - 4, l, 1, l) - getsum(h - 4, r, 1, r)) +
              r - l - 1 - getsum(h - 4, r - 1, h - 4, l + 1);
          if (now < ans) ans = now;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
