#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (long long i = 0; i < n; ++i) cin >> a[i];
    long long ans = (-1e9);
    for (long long i = max(0LL, n - 250); i < n; ++i) {
      for (long long j = max(0LL, n - 250); j < i; ++j) {
        ans = max(ans, (i + 1) * (j + 1) - k * (a[i] | a[j]));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
