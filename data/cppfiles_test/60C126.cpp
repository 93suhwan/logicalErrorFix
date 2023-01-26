#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = 1e9;
    for (long long i = 0; i < n; i++) {
      for (long long j = i; j < n; j++) {
        long long mx = 0;
        for (long long z = 0; z < j - i + 1; z++) {
          a[i + z] = a[i + z] & a[j - z];
        }
        for (long long z = 0; z < n; z++) {
          mx = max(mx, a[i]);
        }
        ans = min(ans, mx);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
