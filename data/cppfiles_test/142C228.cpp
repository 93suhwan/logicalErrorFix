#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
const long long mod = 1e9 + 7;
void solve_test() {
  long long m, n;
  cin >> m >> n;
  long long a[m][n];
  for (long long i = 0; i < m; i++)
    for (long long j = 0; j < n; j++) cin >> a[i][j];
  long long l = 0, r = 1e10, ans = 0;
  while (l <= r) {
    long long mid = l + (r - l) / 2;
    bool ok = 1;
    for (long long i = 0; i < n; i++) {
      bool first = 0;
      for (long long j = 0; j < m; j++)
        if (a[j][i] >= mid) first = 1;
      ok &= first;
    }
    bool ok2 = 0;
    for (long long i = 0; i < m; i++) {
      long long cnt = 0;
      for (long long j = 0; j < n; j++)
        if (a[i][j] >= mid) cnt++;
      if (cnt > 1) ok2 = 1;
    }
    if (ok and ok2) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve_test();
  }
  return 0;
}
