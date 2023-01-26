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
    long long a[n];
    long long mx = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > mx) {
        mx = a[i];
      }
    }
    long long ans = 1e9;
    for (long long i = 0; i < n; i++) {
      if ((a[i] & mx) < ans) {
        ans = a[i] & mx;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
