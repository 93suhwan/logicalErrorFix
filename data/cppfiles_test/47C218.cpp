#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6;
long long t, n, k, a[N], A;
signed main() {
  cin >> t;
  while (t-- && cin >> n >> k) {
    for (long long i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1), A = 0;
    for (long long i = 1; i <= n; i += k)
      if (a[i] < 0) A -= a[i];
    for (long long i = n; i > 0; i -= k)
      if (a[i] > 0) A += a[i];
    cout << A * 2 - max(abs(a[1]), abs(a[n])) << '\n';
  }
  return 0;
}
