#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 2e18 + 5;
const long long nax = 101010;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (long long i = (0); i < (n); i++) cin >> a[i];
  long long res = -mod;
  long long lo = max(0ll, n - 2 * k - 5);
  for (long long i = (lo); i < (n); i++) {
    for (long long j = (i + 1); j < (n); j++) {
      res = max(res, (i + 1) * (j + 1) - k * (a[i] | a[j]));
    }
  }
  cout << res << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
