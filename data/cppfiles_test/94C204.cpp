#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long IM = 1e18 + 37;
const long long N = 2e5 + 10;
long long solve(long long cn, long long a[], long long n, long long k) {
  long long ans = 0;
  for (long long i = n - 1; i >= 0; i--) {
    long long val = 1, now = a[i];
    while (now--) val = val * 10;
    ans += cn / val;
    cn = cn - ((cn / val) * val);
  }
  return (ans > k);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (long long &it : a) cin >> it;
    long long ans = 0;
    long long val = 1;
    long long u = k;
    for (long long i = 0; i < n; i++) {
      long long id = 99999999999;
      if (i + 1 <= n - 1) {
        id = 0;
        long long cn = a[i + 1] - a[i];
        while (cn--) {
          id = id * 10 + 9;
        }
      }
      val = 1;
      long long now = a[i];
      while (now--) {
        val = val * 10;
      }
      if (solve(ans + (k + 1) * val, a, n, u)) {
        ans += (k + 1) * val;
        break;
      }
      id = min(k, id);
      k -= id;
      ans += id * val;
    }
    cout << ans << "\n";
  }
  return 0;
}
