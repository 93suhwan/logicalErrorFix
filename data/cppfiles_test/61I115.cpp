#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const long long N = 2e5 + 100;
long long a[N];
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    long long x = 1ll * sum * (n - 2);
    if (x % n == (long long)0) {
      x /= n;
    } else {
      cout << 0 << endl;
      continue;
    }
    sort(a + 1, a + 1 + n);
    long long ans = 0;
    for (long long i = 1; a[i] <= (sum - x); i++) {
      long long l = lower_bound(a + i + 1, a + 1 + n, sum - x - a[i]) - a;
      long long r = upper_bound(a + i + 1, a + 1 + n, sum - x - a[i]) - a;
      ans += (r - l);
    }
    cout << ans << endl;
  }
  return 0;
}
