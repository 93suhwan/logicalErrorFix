#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long inf = 1e18;
long long mx = -1;
long long mn = 1e18;
long long calpow(long long a, long long b, long long md) {
  long long mul = 1;
  while (b > 0) {
    if (b & 1) {
      mul = ((a % md) * (mul % md)) % md;
      b--;
    } else {
      a = ((a % md) * (a % md)) % md;
      b /= 2;
    }
  }
  return mul;
}
void solve() {
  long long i, j, n, t, q, a, b, m, k, ct = 0, sum = 0, flag = 0;
  cin >> m;
  long long ar[2][m];
  long long pre[2][m];
  for (long long i = (0); i < (2); i++) {
    for (long long j = (0); j < (m); j++) cin >> ar[i][j];
  }
  pre[0][0] = ar[0][0];
  pre[1][0] = ar[1][0];
  for (long long i = (1); i < (m); i++) pre[0][i] = ar[0][i] + pre[0][i - 1];
  for (long long i = (1); i < (m); i++) pre[1][i] = ar[1][i] + pre[1][i - 1];
  for (long long i = (1); i < (m); i++) sum += ar[0][i];
  for (long long i = (0); i < (m - 1); i++) ct += ar[1][i];
  mx = inf;
  mn = min(sum, ct);
  for (long long i = (1); i < (m - 1); i++) {
    mx = max(pre[1][i - 1], pre[0][(m - 1)] - pre[0][i]);
  }
  cout << min(mn, mx);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  cerr << clock() * 1000.0 / CLOCKS_PER_SEC << 'm' << 's';
  return 0;
}
