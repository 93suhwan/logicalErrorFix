#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18, mod = 1e9 + 7, N = 1e5;
const long double eps = 1e-6;
const long long MAXN = 300002;
const long long lg = 20;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long ans = -inf;
  for (long long i = 0; i < n; ++i) {
    for (long long j = i + 1; j < min(i + 1 + 100, n); ++j) {
      long long p = (i + 1) * (j + 1);
      ans = max(ans, (p - (k * (a[i] | a[j]))));
    }
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
