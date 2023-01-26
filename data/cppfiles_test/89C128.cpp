#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<long long> a(n + 1);
    for (long long i = 1; i <= n; ++i) cin >> a[i];
    string ans = "YES";
    for (long long i = 1; i <= n; ++i) {
      bool ok = 0;
      for (long long j = 2; !ok and j <= (i + 1); ++j) ok |= !!(a[i] % j);
      if (!ok) {
        ans = "NO";
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
