#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 100;
long long n, h;
long long a[N];
bool check(long long k) {
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    if (a[i] + k - 1 >= a[i + 1] && i != n) {
      ans += a[i + 1] - a[i];
    } else {
      ans += k;
    }
  }
  return ans >= h;
}
signed main() {
  ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> h;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    long long l = 0, r = h;
    long long ans = 0;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      if (check(mid)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << ans << endl;
  }
}
