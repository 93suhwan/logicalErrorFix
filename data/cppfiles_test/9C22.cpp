#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
long long n, m, k;
long long g[1005][1005];
void work(long long x, long long y) {
  if (x > n) {
    cout << y << ' ';
  }
  if (g[x][y] == 1) {
    g[x][y] = 2;
    work(x, y + 1);
  } else if (g[x][y] == 2) {
    work(x + 1, y);
  } else if (g[x][y] == 3) {
    g[x][y] = 2;
    work(x, y - 1);
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> g[i][j];
    }
  }
  for (long long i = 1; i <= k; i++) {
    long long x;
    cin >> x;
    work(1, x);
  }
  return 0;
}
