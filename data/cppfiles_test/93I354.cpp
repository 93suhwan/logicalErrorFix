#include <bits/stdc++.h>
using namespace std;
long long ceiling(long double n) {
  if (n == (long long)n)
    return n;
  else
    return n + 1;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k, ans = 0, helper = 1, h = 1;
    cin >> n >> k;
    while (helper * 2 < k && (n - helper) > 0) {
      helper *= 2;
      ans++;
      h = 0;
    }
    long long remaining = ceiling(((n - h) - (helper * 1.0 / 2)) / k);
    if (remaining > 0) ans += remaining;
    cout << ans << "\n";
  }
}
