#include <bits/stdc++.h>
using namespace std;
long long n;
double eps = 1e-6;
double solve(long long m) {
  double ret = 0;
  if (m >= 1) ret += 1.0l * (n - m) * (n - m - 1) / 2 * m * 1 / 2;
  if (m >= 2) ret += 1.0l * (n - m) * m * (m - 1) / 2;
  if (m >= 3) ret += 1.0l * m * (m - 1) * (m - 2) / 6;
  ret /= 1.0l * n * (n - 1) * (n - 2) / 6;
  return ret;
}
signed main(void) {
  ios::sync_with_stdio(false);
  double p;
  cin >> n >> p;
  if (p < eps) {
    cout << 0 << endl;
    return 0;
  }
  long long l = 0, r = n, m, ans = r;
  while (l <= r) {
    m = (l + r) / 2;
    if (solve(m) >= p) {
      ans = min(ans, m);
      r = m - 1;
    } else
      l = m + 1;
  }
  cout << ans << endl;
  return 0;
}
