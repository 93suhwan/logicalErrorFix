#include <bits/stdc++.h>
using namespace std;
long long t, n, m;
long long pre[405][405], a[405][405], sum[405];
long long get(long long a, long long b, long long c) {
  return pre[b][c] - pre[a - 1][c];
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        char f;
        cin >> f;
        a[i][j] = f - '0';
        pre[i][j] = pre[i - 1][j] + a[i][j];
      }
    }
    long long res = 1000000000000000000;
    for (long long l = 1; l <= n - 4; l++) {
      for (long long r = l + 4; r <= n; r++) {
        long long mx = -1000000000000000000;
        for (long long k = 1; k <= 3; k++)
          sum[k] = sum[k - 1] + get(l + 1, r - 1, k) + (2 - a[l][k] - a[r][k]);
        for (long long k = 4; k <= m; k++) {
          sum[k] = sum[k - 1] + get(l + 1, r - 1, k) + (2 - a[l][k] - a[r][k]);
          mx = max(mx, sum[k - 3] - (r - l) + get(l, r - 1, k - 3));
          res = min(res, sum[k - 1] + (r - l) - get(l + 1, r, k) - mx);
        }
      }
    }
    cout << res << "\n";
  }
}
