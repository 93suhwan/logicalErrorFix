#include <bits/stdc++.h>
using namespace std;
long long dx[] = {0, 0, 1, 0};
long long dy[] = {0, 1, 0, -1};
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long T = 1;
  while (T--) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long a[n][m];
    long long c[k + 1];
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    for (long long i = 0; i < k; i++) {
      c[i] = n - 1;
    }
    c[k] = -1;
    for (long long i = 0; i < k; i++) {
      long long y;
      cin >> y;
      y--;
      long long x = 0;
      long long mn = 1e9;
      while (x < n && y < m) {
        long long v = a[x][y];
        a[x][y] = 2;
        x += dx[v];
        y += dy[v];
        while (c[y] >= 0 && a[c[y]][y] == 2) {
          c[y]--;
        }
        if (x > c[y]) {
          break;
        }
      }
      cout << y + 1 << ' ';
    }
  }
  return 0;
}
