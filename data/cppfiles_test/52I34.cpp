#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n;
long double a[100005];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    long double ans = -1e9;
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
    for (int i = 1; i < n; ++i) {
      ans = max(ans, a[i] / i + (a[n] - a[i]) / (n - i));
    }
    cout << fixed << setprecision(6) << ans << endl;
  }
}
