#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const long long mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const long long MAXN = 1e5 + 10;
long long a[3][MAXN];
void solve() {
  long long m;
  cin >> m;
  for (long long i = 1; i <= m; ++i) cin >> a[1][i];
  for (long long i = 1; i <= m; ++i) cin >> a[2][i];
  if (m == 1)
    cout << "0\n";
  else {
    long long s = 0, x = 0;
    for (long long i = 2; i <= m; ++i) s += a[1][i];
    long long ans = s;
    for (long long i = 2; i <= m; ++i) {
      s -= a[1][i];
      x += a[2][i - 1];
      long long tmp = max(s, x);
      ans = min(ans, tmp);
    }
    cout << ans << "\n";
  }
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long _ = 1;
  cin >> _;
  for (long long i = 1; i <= _; ++i) {
    solve();
  }
  return 0;
}
