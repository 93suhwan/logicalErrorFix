#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) { return (y == 0 ? x : gcd(y, x % y)); }
long long lcm(long long x, long long y) { return (x / gcd(x, y)) * y; }
long long freq[(long long)5e5 + 5];
int32_t main() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  long long odd = 0;
  long long even = 0;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (arr[i] == 1) {
      if (even > 1) {
        ans++;
        even--;
      } else {
        even++;
      }
    } else if (arr[i] & 1) {
      odd += arr[i];
      if (even > 0) {
        ans += min(even, odd);
        odd -= min(even, odd);
        even -= min(even, odd);
      }
    } else {
      even += arr[i];
    }
  }
  cout << ans << '\n';
}
