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
      for (long long j = i + 1; j < n; j++) {
        long long mx = 0;
        vector<long long> f = a;
        for (long long z = 0; z < (j - i + 2) / 2; z++) {
          f[i + z] = f[i + z] & f[j - z];
          f[j - z] = f[i + z];
        }
        for (long long z = 0; z < n; z++) {
          mx = max(mx, f[i]);
        }
        ans = min(ans, mx);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
