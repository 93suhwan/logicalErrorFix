#include <bits/stdc++.h>
using namespace std;
long long n, k;
const long long N = 3e5 + 5;
long long a[N];
void solve() {
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long ans = -1e9;
  for (long long i = 1; i < n; i++) {
    for (long long j = i + 1; j <= min(i + k, n); j++) {
      ans = max(ans, i * j - k * (a[i] | a[j]));
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
