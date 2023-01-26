#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 9;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n][2];
    long long one = 0;
    for (long long i = 0; i < n; i++) cin >> a[i][0], one += a[i][0];
    for (long long i = 0; i < n; i++) cin >> a[i][1];
    long long two = 0, ans = INT_MAX;
    for (long long i = 0; i < n; i++) {
      one -= a[i][0];
      ans = min(ans, max(one, two));
      two += a[i][1];
    }
    cout << ans << "\n";
  }
  return 0;
}
