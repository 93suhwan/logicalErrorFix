#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
void solve() {
  long long int i, j, n, k;
  cin >> n >> k;
  n--;
  if (k > 1e9 || (k * (k + 1)) / 2 > n) {
    long long int lo = 1, hi = k;
    long long int res = n;
    while (lo <= hi) {
      long long int m = lo + (hi - lo) / 2;
      if (m * m + m - 2 * n >= 0) {
        hi = m - 1;
        res = min(res, m);
      } else {
        lo = hi + 1;
      }
    }
    cout << res;
  } else {
    n -= (k * (k + 1)) / 2;
    long long int res = k;
    res += n / k;
    if (n % k) {
      res++;
    }
    cout << res;
  }
  return;
}
int32_t main() {
  long long int t, tc = 1;
  t = 1;
  cin >> t;
  while (tc <= t) {
    solve();
    cout << "\n";
    tc++;
  }
  return 0;
}
