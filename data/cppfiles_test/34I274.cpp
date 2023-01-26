#include <bits/stdc++.h>
using namespace std;
void solve() {
  long n, k;
  cin >> n >> k;
  vector<long> a(n);
  for (long i = 0; i < n; i++) cin >> a[i];
  long best = n * (n - 1) - k * ((a[n - 1] | a[n - 2]));
  for (long i = max((long)0, n - 300); i < n - 1; i++) {
    for (long j = i + 1; j < n; j++) {
      best = max((long)best, (long)((i + 1) * (j + 1) - k * ((a[i] | a[j]))));
    }
  }
  cout << best << endl;
}
signed main() {
  long tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
