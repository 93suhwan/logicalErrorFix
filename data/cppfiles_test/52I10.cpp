#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, a[100005];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    long double ans = -2e9 - 9;
    for (long long i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
    for (long long i = 1; i < n; ++i) {
      ans = max(ans, (long double)a[i] / (long double)i +
                         (long double)(a[n] - a[i]) / (long double)(n - i));
    }
    cout << fixed << setprecision(9) << ans << endl;
  }
}
