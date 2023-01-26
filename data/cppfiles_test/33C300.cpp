#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MX = 10e6;
inline void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long ans = -1;
  if (v[0] * v[1] > ans) ans = v[0] * v[1];
  for (long long i = 1; i < n - 1; i++) {
    ans = max(ans, max(v[i] * v[i - 1], v[i] * v[i + 1]));
  }
  if (v[n - 1] * v[n - 2] > ans) ans = v[n - 1] * v[n - 2];
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
