#include <bits/stdc++.h>
using namespace std;
long long lim = 200005;
long long p[200005][25];
void solve() {
  for (long long i = 1; i <= lim; i++) {
    for (long long j = 0; j <= 20; j++) {
      long long t = 0;
      if (((1 << j) & i) == 0) {
        t = 1;
      }
      p[i][j] = p[i - 1][j] + t;
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    long long ans = 1000000000000000000;
    if (r > l) {
      for (long long i = 0; i <= 20; i++) {
        if (p[r][i] - p[l - 1][i] != (r - l + 1)) {
          ans = min((p[r][i] - p[l - 1][i]), ans);
        }
      }
      cout << ans << "\n";
      continue;
    }
    cout << 0 << "\n";
  }
  return 0;
}
