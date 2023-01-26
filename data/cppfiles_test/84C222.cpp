#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
long long cal(long long n) {
  long long x = (n * (n + 1)) / 2;
  return x;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, x, i, j, n, m, k, l, r;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if (n == 1) {
      cout << k << "\n";
      continue;
    }
    l = 1, r = k;
    j = (n / 2) + (n % 2);
    long long ans = 0;
    while (l <= r) {
      m = (l + r) / 2;
      x = k - m;
      x /= (n - j);
      if (x >= m)
        ans = m, l = m + 1;
      else
        r = m - 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
