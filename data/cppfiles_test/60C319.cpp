#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ar[n];
    for (long long i = 0; i < n; i++) {
      cin >> ar[i];
    }
    long long mn = ar[0];
    long long ans = INT_MAX;
    for (long long i = 0; i < n; i++) {
      mn = mn & ar[i];
      ans = min(ans, mn);
    }
    cout << ans << endl;
  }
  return 0;
}
